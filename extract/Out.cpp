#include "Out.hpp"

Out::Out(vector<int> &tone_dist) {
  this->tone_dist.assign(tone_dist.begin(), tone_dist.end());
  this->chans.resize(tone_dist.size());
}

void Out::all(byte b) {
  dprintf("all, push_back: %#02x\n", b);
  for (vector<byte> &c: this->chans) {
    c.push_back(b);
  }
}

void Out::chan(int chan, byte b, bool skip_processing) {
  for (int i = 0; i < this->chans.size(); i++) {
    int v = this->tone_dist[i];
    if (chan < v) {
      // 0x0f is where the channel is.
      byte nb = skip_processing ? b : ((b & (~0x0F)) | chan);
      dprintf("chans[%d].push_back(%#02x -> %#02x) (? -> %d)\n", i, b, nb, chan);
      this->chans[i].push_back(nb);
      return;
    }
    chan -= v;
  }

  ERROR("FATAL: Attempt to output to channel: %d\n", chan);
}

vector<byte>& Out::get_chan_data(int chan) {
  if (!(0 <= chan < chans.size())) {
    ERROR("FATAL: Attempt to access channel: %d in get_chan_data\n", chan);
  }
  return this->chans[chan];
}

int Out::get_chan_ntones(int chan) {
  if (!(0 <= chan < chans.size())) {
    printf("FATAL: Attempt to access channel: %d in get_chan_ntones\n", chan);
    exit(1);
  }
  return this->tone_dist[chan];
}

int Out::get_nchans() {
  return (int)this->chans.size();
}
