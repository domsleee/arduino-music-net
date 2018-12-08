#ifndef OUT_H
#define OUT_H
#include <iostream>
#include <vector>
#include "globals.hpp"
using namespace std;

typedef unsigned char byte;

class Out {
  vector<vector<byte> > chans;
  vector<int> chan_dist;
public:
  Out(vector<int> &chan_dist); // a distribution of channels, e.g. {3,4}
  void all(byte b);
  void chan(int chan, byte b, bool skip_processing=false);
  vector<byte>& get_chan_data(int chan);
  int get_chan_ntones(int chan);
  int get_nchans();
};
#endif