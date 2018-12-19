#include "tests.hpp"

const unsigned char midilovania [] = {
'P','t', 6, 0xE0, 0x00,  7, // (Playtune file header)
0xC0,81, 0x90,62,100, 0,125, 0x90,62,100, 0,125, 0x90,74,100, 0,125, 0x80, 0,125, 0x90,69,100, 0,125, 0x80, 
0,250, 0x90,68,100, 0,125, 0x80, 0,125, 0x90,67,100, 0,125, 0x80, 0,125, 0x90,65,100, 0,250, 0x90,62,100, 
0,125, 0x90,65,100, 0,125, 0x90,67,100, 0,125, 0x90,60,100, 0,125, 0x90,60,100, 0,125, 0x90,74,100, 0,125, 
0x80, 0,125, 0x90,69,100, 0,125, 0x80, 0,250, 0x90,68,100, 0,125, 0x80, 0,125, 0x90,67,100, 0,125, 0x80, 0,125, 
0x90,65,100, 0,250, 0x90,62,100, 0,125, 0x90,65,100, 0,125, 0x90,67,100, 0,125, 0x90,59,100, 0,125, 0x90,59,100, 
0,125, 0x90,74,100, 0,125, 0x80, 0,125, 0x90,69,100, 0,125, 0x80, 0,250, 0x90,68,100, 0,125, 0x80, 0,125, 
0x90,67,100, 0,125, 0x80, 0,125, 0x90,65,100, 0,250, 0x90,62,100, 0,125, 0x90,65,100, 0,125, 0x90,67,100, 
0,125, 0x90,58,100, 0,125, 0x90,58,100, 0,125, 0x90,74,100, 0,125, 0x80, 0,125, 0x90,69,100, 0,125, 0x80, 
0,250, 0x90,68,100, 0,125, 0x80, 0,125, 0x90,67,100, 0,125, 0x80, 0,125, 0x90,65,100, 0,250, 0x90,62,100, 
0,125, 0x90,65,100, 0,125, 0x90,67,100, 0,125, 0xC1,29, 0x91,50,100, 0x90,62,100, 0,125, 0x90,62,100, 0x81, 
0,125, 0x91,50,100, 0x90,74,100, 0,125, 0x80, 0x81, 0,125, 0x91,50,100, 0x90,69,100, 0,125, 0x91,50,100, 0x80, 
0,125, 0x81, 0,125, 0x90,68,100, 0x91,50,100, 0,125, 0x80, 0x81, 0,125, 0x90,67,100, 0x91,50,100, 0,125, 0x80, 
0x81, 0,125, 0x90,65,100, 0x91,50,100, 0,125, 0x91,50,100, 0,125, 0x90,62,100, 0x91,50,100, 0,125, 0x90,65,100, 
0x91,50,100, 0,125, 0x90,67,100, 0x91,50,100, 0,125, 0x90,60,100, 0x91,48,100, 0,125, 0x90,60,100, 0x81, 0,125, 
0x91,48,100, 0x90,74,100, 0,125, 0x80, 0x81, 0,125, 0x91,48,100, 0x90,69,100, 0,125, 0x91,48,100, 0x80, 0,125, 
0x81, 0,125, 0x90,68,100, 0x91,48,100, 0,125, 0x80, 0x81, 0,125, 0x90,67,100, 0x91,48,100, 0,125, 0x80, 0x81, 0,125, 
0x90,65,100, 0x91,48,100, 0,125, 0x91,48,100, 0,125, 0x90,62,100, 0x91,48,100, 0,125, 0x90,65,100, 0x91,48,100, 
0,125, 0x90,67,100, 0x91,48,100, 0,125, 0x90,59,100, 0x91,47,100, 0,125, 0x90,59,100, 0x81, 0,125, 0x91,47,100, 
0x90,74,100, 0,125, 0x80, 0x81, 0,125, 0x91,47,100, 0x90,69,100, 0,125, 0x91,47,100, 0x80, 0,125, 0x81, 0,125, 
0x90,68,100, 0x91,47,100, 0,125, 0x80, 0x81, 0,125, 0x90,67,100, 0x91,47,100, 0,125, 0x80, 0x81, 0,125, 0x90,65,100, 
0x91,47,100, 0,125, 0x91,47,100, 0,125, 0x90,62,100, 0x91,47,100, 0,125, 0x90,65,100, 0x91,47,100, 0,125, 
0x90,67,100, 0x91,47,100, 0,125, 0x90,58,100, 0x91,46,100, 0,125, 0x90,58,100, 0x81, 0,125, 0x91,46,100, 0x90,74,100, 
0,125, 0x80, 0x81, 0,125, 0x91,46,100, 0x90,69,100, 0,125, 0x91,46,100, 0x80, 0,125, 0x81, 0,125, 0x90,68,100, 
0x91,46,100, 0,125, 0x80, 0x81, 0,125, 0x90,67,100, 0,10, 0x91,48,100, 0,114, 0x80, 0,10, 0x81, 0,114, 0x90,65,100, 
0,10, 0x91,48,100, 0,125, 0x91,48,100, 0,114, 0x90,62,100, 0,10, 0x91,48,100, 0,114, 0x90,65,100, 0,10, 
0x91,48,100, 0,114, 0x90,67,100, 0,10, 0x91,48,100, 0,114, 0xC2,30, 0x92,38,100, 0xC0,48, 0x90,74,100, 0xC3,61, 
0x93,50,100, 0xC4,48, 0x94,74,100, 0xC5,81, 0x95,62,100, 0xC6,87, 0x96,50,100, 0,5, 0,5, 0x81, 0,114, 0x90,86,100};

// ntones 4
const unsigned char exp1 [] = {80,
116,6,224,0,7,0xc0,81,0x90,62,100,0,125,0x90,62,100,0,125,0x90,74,100,0,125,0x80,0,125,
0x90,69,100,0,125,0x80,0,250,0x90,68,100,0,125,0x80,0,125,0x90,67,100,0,125,0x80,0,125,0x90,
65,100,0,250,0x90,62,100,0,125,0x90,65,100,0,125,0x90,67,100,0,125,0x90,60,100,0,125,0x90,
60,100,0,125,0x90,74,100,0,125,0x80,0,125,0x90,69,100,0,125,0x80,0,250,0x90,68,100,0,125,
0x80,0,125,0x90,67,100,0,125,0x80,0,125,0x90,65,100,0,250,0x90,62,100,0,125,0x90,65,100,0,
125,0x90,67,100,0,125,0x90,59,100,0,125,0x90,59,100,0,125,0x90,74,100,0,125,0x80,0,125,0x90,
69,100,0,125,0x80,0,250,0x90,68,100,0,125,0x80,0,125,0x90,67,100,0,125,0x80,0,125,0x90,65,
100,0,250,0x90,62,100,0,125,0x90,65,100,0,125,0x90,67,100,0,125,0x90,58,100,0,125,0x90,58,
100,0,125,0x90,74,100,0,125,0x80,0,125,0x90,69,100,0,125,0x80,0,250,0x90,68,100,0,125,0x80,
0,125,0x90,67,100,0,125,0x80,0,125,0x90,65,100,0,250,0x90,62,100,0,125,0x90,65,100,0,125,
0x90,67,100,0,125,0xc1,29,0x91,50,100,0x90,62,100,0,125,0x90,62,100,0x81,0,125,0x91,50,100,0x90,
74,100,0,125,0x80,0x81,0,125,0x91,50,100,0x90,69,100,0,125,0x91,50,100,0x80,0,125,0x81,0,125,
0x90,68,100,0x91,50,100,0,125,0x80,0x81,0,125,0x90,67,100,0x91,50,100,0,125,0x80,0x81,0,125,0x90,
65,100,0x91,50,100,0,125,0x91,50,100,0,125,0x90,62,100,0x91,50,100,0,125,0x90,65,100,0x91,50,
100,0,125,0x90,67,100,0x91,50,100,0,125,0x90,60,100,0x91,48,100,0,125,0x90,60,100,0x81,0,125,
0x91,48,100,0x90,74,100,0,125,0x80,0x81,0,125,0x91,48,100,0x90,69,100,0,125,0x91,48,100,0x80,0,
125,0x81,0,125,0x90,68,100,0x91,48,100,0,125,0x80,0x81,0,125,0x90,67,100,0x91,48,100,0,125,0x80,
0x81,0,125,0x90,65,100,0x91,48,100,0,125,0x91,48,100,0,125,0x90,62,100,0x91,48,100,0,125,0x90,
65,100,0x91,48,100,0,125,0x90,67,100,0x91,48,100,0,125,0x90,59,100,0x91,47,100,0,125,0x90,59,
100,0x81,0,125,0x91,47,100,0x90,74,100,0,125,0x80,0x81,0,125,0x91,47,100,0x90,69,100,0,125,0x91,
47,100,0x80,0,125,0x81,0,125,0x90,68,100,0x91,47,100,0,125,0x80,0x81,0,125,0x90,67,100,0x91,47,
100,0,125,0x80,0x81,0,125,0x90,65,100,0x91,47,100,0,125,0x91,47,100,0,125,0x90,62,100,0x91,47,
100,0,125,0x90,65,100,0x91,47,100,0,125,0x90,67,100,0x91,47,100,0,125,0x90,58,100,0x91,46,100,
0,125,0x90,58,100,0x81,0,125,0x91,46,100,0x90,74,100,0,125,0x80,0x81,0,125,0x91,46,100,0x90,69,
100,0,125,0x91,46,100,0x80,0,125,0x81,0,125,0x90,68,100,0x91,46,100,0,125,0x80,0x81,0,125,0x90,
67,100,0,10,0x91,48,100,0,114,0x80,0,10,0x81,0,114,0x90,65,100,0,10,0x91,48,100,0,125,
0x91,48,100,0,114,0x90,62,100,0,10,0x91,48,100,0,114,0x90,65,100,0,10,0x91,48,100,0,114,
0x90,67,100,0,10,0x91,48,100,0,114,0xc2,30,0x92,38,100,0xc0,48,0x90,74,100,0xc3,61,0x93,50,100,
0,5,0,5,0x81,0,114,0x90,86,100};

const unsigned char exp2[] = {80,
116,6,224,0,7,0,125,0,125,0,125,0,125,0,125,0,250,0,125,0,125,0,125,0,125,
0,250,0,125,0,125,0,125,0,125,0,125,0,125,0,125,0,125,0,250,0,125,0,125,0,
125,0,125,0,250,0,125,0,125,0,125,0,125,0,125,0,125,0,125,0,125,0,250,0,125,
0,125,0,125,0,125,0,250,0,125,0,125,0,125,0,125,0,125,0,125,0,125,0,125,0,
250,0,125,0,125,0,125,0,125,0,250,0,125,0,125,0,125,0,125,0,125,0,125,0,125,
0,125,0,125,0,125,0,125,0,125,0,125,0,125,0,125,0,125,0,125,0,125,0,125,0,
125,0,125,0,125,0,125,0,125,0,125,0,125,0,125,0,125,0,125,0,125,0,125,0,125,
0,125,0,125,0,125,0,125,0,125,0,125,0,125,0,125,0,125,0,125,0,125,0,125,0,
125,0,125,0,125,0,125,0,125,0,125,0,125,0,125,0,125,0,125,0,125,0,125,0,125,
0,125,0,125,0,125,0,10,0,114,0,10,0,114,0,10,0,125,0,114,0,10,0,114,0,
10,0,114,0,10,0,114,0xc0,48,0x90,74,100,0xc1,81,0x91,62,100,0xc2,87,0x92,50,100,0,5,0,
5,0,114};

static bool test_midilovania();
static void print_res(string title, bool ok);
static unsigned long long score_length(vector<byte> &score);

void test() {
  bool ok = true;
  if (!test_midilovania()) ok = false;

  printf("\nAll: %s\n", ok ? "PASSed" : "FAILed");
}

// helpers
static void print_res(string title, bool ok) {
  printf("%-48s: %s\n", title.c_str(), ok ? "PASSed" : "FAILed");
}

static vector<byte> equiv_vector(vector<p> out_data) {
  vector<byte> data;
  for (p tp: out_data) {
    data.push_back(tp.first);
  }
  return data;
}

static bool equiv(vector<byte> &score, vector<p> &out_data) {
  if (score.size() != out_data.size()) return false;
  for (int i = 0; i < score.size(); i++) {
    if (score[i] != out_data[i].first) return false;
  }
  return true;
}

static unsigned long long score_length(vector<byte> &score) {
  byte cmd, opcode, chan, note;
  unsigned long long duration = 0;
  int score_cursor = 0;
  /* Do score commands until a "wait" is found, or the score is stopped.
    This is called initially from tune_playcore, but then is called
    from the interrupt routine when waits expire.
  */
#define CMD_PLAYNOTE  0x90  /* play a note: low nibble is generator #, note is next byte */
#define CMD_STOPNOTE  0x80  /* stop a note: low nibble is generator # */
#define CMD_INSTRUMENT  0xc0 /* change instrument; low nibble is generator #, instrument is next byte */
#define CMD_RESTART 0xe0  /* restart the score from the beginning */
#define CMD_STOP  0xf0  /* stop playing */
  /* if CMD < 0x80, then the other 7 bits and the next byte are a 15-bit big-endian number of msec to wait */

  auto pgm_read_byte = [score](int a) {
    return score[a];
  };

  while (score_cursor < score.size()) {
    cmd = pgm_read_byte(score_cursor++);
    if (cmd < 0x80) { /* wait count in msec. */
      duration += ((unsigned)cmd << 8) | (pgm_read_byte(score_cursor++));
      break;
    }
    opcode = cmd & 0xf0;
    chan = cmd & 0x0f;
    if (opcode == CMD_STOPNOTE) { /* stop note */

    }
    else if (opcode == CMD_PLAYNOTE) { /* play note */
      note = pgm_read_byte(score_cursor++); // argument evaluation order is undefined in C!
      if (1) ++score_cursor; // ignore volume if present
    }
    else if (opcode == CMD_INSTRUMENT) { /* change a channel's instrument */
      score_cursor++; // ignore it
    }
    else if (opcode == CMD_RESTART) { /* restart score */
      break;
    }
    else if (opcode == CMD_STOP) { /* stop score */
      break;
    }
  }
  return duration;
}

static bool test_midilovania() {
  vector<bool> ok;
  vector<int> tone_dist;
  tone_dist.push_back(7);
  Out out(tone_dist);
  vector<byte> score(midilovania, midilovania+sizeof(midilovania));
  extract(score, out);
  vector<p> out_data = out.get_chan_data(0);
  ok.push_back(equiv(score, out_data));
  print_res("single channel", *ok.rbegin());

  tone_dist[0] = 4;
  tone_dist.push_back(3);
  Out out_2(tone_dist);
  extract(score, out_2);

  vector<byte> exp1_b(exp1, exp1+sizeof(exp1));
  vector<byte> exp2_b(exp2, exp2+sizeof(exp2));
  ok.push_back(equiv(exp1_b, out_2.get_chan_data(0)) &&
               equiv(exp2_b, out_2.get_chan_data(1)));
  print_res("as expected", *ok.rbegin());


  // these tests aren't essential, mostly sanity

  // substring up to 0x93 should be the same.
  vector<byte> a(score.begin(), find(score.begin(), score.end(), 0x93));
  vector<p> b = out_2.get_chan_data(0);
  vector<p> c = vector<p>(b.begin(), find(b.begin(), b.end(), p(0x93, HEX_TYPE)));
  ok.push_back(equiv(a, c));
  print_res("up to 0x93", *ok.rbegin());

  unsigned long long sl = score_length(score);
  vector<byte> z0 = equiv_vector(out_2.get_chan_data(0));
  vector<byte> z1 = equiv_vector(out_2.get_chan_data(1));
  unsigned long long sl0 = score_length(z0);
  unsigned long long sl1 = score_length(z1);
  printf("sl: %llu, sl0: %llu, sl1: %llu\n", sl, sl0, sl1);
  ok.push_back(sl == sl0 && sl0 == sl1);
  print_res("sl = sl0 = sl1", *ok.rbegin());

  return all_of(ok.begin(), ok.end(), [](bool ok) { return ok; });
}

