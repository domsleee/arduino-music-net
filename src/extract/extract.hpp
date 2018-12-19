#ifndef EXTRACT_H
#define EXTRACT_H
#include <iostream>
#include "Out.hpp"
#include "globals.hpp"
using namespace std;

static struct file_hdr_t {  // the optional bytestream file header
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

void extract(vector<byte> &score, Out &out);
void tune_go(vector<byte> &score, int score_start, Out &out, int volume_present);

#endif