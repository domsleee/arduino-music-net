#include "extract.hpp"
#include "io.hpp"
#include "tests.hpp"
#include "globals.hpp"

int main(int argc, char ** argv) {
  if (argc == 2 && string(argv[1]) == "test") test();
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
