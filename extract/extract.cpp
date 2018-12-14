#include <iostream>
#include "Out.hpp"
#include "globals.hpp"
#include "io.hpp"
using namespace std;

struct file_hdr_t {  // the optional bytestream file header
  char id1;     // 'P'
  char id2;     // 't'
  unsigned char hdr_length; // length of whole file header
  unsigned char f1;         // flag byte 1
  unsigned char f2;         // flag byte 2
  unsigned char num_tgens;  // how many tone generators are used by this score
} file_header;
#define HDR_F1_VOLUME_PRESENT 0x80
#define HDR_F1_INSTRUMENTS_PRESENT 0x40
#define HDR_F1_PERCUSSION_PRESENT 0x20

//-----------------------------------------------
// Start playing a score
//-----------------------------------------------


void extract(vector<byte> &score, Out &out);
void tune_go(vector<byte> &score, int score_start, Out &out, int volume_present);

int main(int argc, char ** argv) {
  if (argc < 4) {
    printf("Usage: %s <input> (<out> <num_chans>)+\n", argv[0]);
    exit(1);
  }

  vector<int> tone_dist;
  vector<string> out_files;
  for (int i = 2; i < argc; i++) {
    string out = string(argv[i++]);
    out_files.push_back(out);
    int num_tones = atoi(argv[i]);
    tone_dist.push_back(num_tones);
  }
  int num_chans = out_files.size();
  vector<byte> score = read_score(argv[1]);
  Out out(tone_dist);
  extract(score, out);

  for (int i = 0; i < num_chans; i++) {
    print_chan(out_files[i], out.get_chan_ntones(i), out.get_chan_data(i));
  }
}

void extract(vector<byte> &score, Out &out) {
  int volume_present = 0;
  int score_start = 0;

  // look for the optional file header
  memcpy(&file_header, score.data(), sizeof(file_hdr_t)); // copy possible header from PROGMEM to RAM
  if (file_header.id1 == 'P' && file_header.id2 == 't') { // validate it
    volume_present = file_header.f1 & HDR_F1_VOLUME_PRESENT;
    score_start += file_header.hdr_length; // skip the whole header
    for (int i = 0; i < score_start; i++) out.all(score[i]);
  }
  tune_go(score, score_start, out, volume_present);  /* execute initial commands */
}

void tune_go(vector<byte> &score, int score_start, Out &out, int volume_present) {
  byte cmd, opcode, chan, note;
  int score_cursor = score_start;

  /* Do score commands until a "wait" is found, or the score is stopped.
    This is called initially from tune_playcore, but then is called
    from the interrupt routine when waits expire.
  */
#define CMD_PLAYNOTE    0x90    /* play a note: low nibble is generator #, note is next byte */
#define CMD_STOPNOTE    0x80    /* stop a note: low nibble is generator # */
#define CMD_INSTRUMENT  0xc0 /* change instrument; low nibble is generator #, instrument is next byte */
#define CMD_RESTART 0xe0    /* restart the score from the beginning */
#define CMD_STOP    0xf0    /* stop playing */
  /* if CMD < 0x80, then the other 7 bits and the next byte are a 15-bit big-endian number of msec to wait */

  while (score_cursor < (int)score.size()) {
    dprintf("%d/%d\n", score_cursor, (int)score.size());
    cmd = score[score_cursor++];
    dprintf("%#02x\n", cmd);
    if (cmd < 0x80) { /* wait count in msec. */
      dprintf("wait\n");
      out.all(cmd);
      out.all(score[score_cursor++]);
    }
    opcode = cmd & 0xf0;
    chan = cmd & 0x0f;
    if (opcode == CMD_STOPNOTE) { /* stop note */
      out.chan(chan, cmd);
    }
    else if (opcode == CMD_PLAYNOTE) { /* play note */
      dprintf("note\n");
      note = score[score_cursor++]; // argument evaluation order is undefined in C!
      if (volume_present) ++score_cursor; // ignore volume if present
      out.chan(chan, cmd);
      out.chan(chan, note, true);
    }
    else if (opcode == CMD_INSTRUMENT) { /* change a channel's instrument */
      score_cursor++; // ignore it
    }
    else if (opcode == CMD_RESTART) { /* restart score */
      out.all(cmd);
      dprintf("restart.\n");
      break;
    }
    else if (opcode == CMD_STOP) { /* stop score */
      dprintf("stop.\n");
      out.all(cmd);
      break;
    }
    else {
      //printf("um!\n");
    }
  }
}