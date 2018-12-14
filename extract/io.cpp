#include "io.hpp"
#include <iomanip>


vector<byte> read_score(char *filename) {
  ifstream fin(filename, ios::binary);
  if (!fin) {
    ERROR("FATAL ERROR: file \"%s\" not found\n", filename);
  }
  vector<byte> b(istreambuf_iterator<char>(fin), {});
  return b;
}

void print_chan(string &filepath, int ntones, vector<p> &data) {
  printf("Writing to file \"%s\"\n", filepath.c_str());
  ofstream fout(filepath);
  if (!fout) {
    ERROR("FATAL ERROR: file \"%s\" couldn't be opened\n", filepath.c_str());
  }
  fout << "// ntones: " << ntones << '\n';
  fout << "const unsigned char PROGMEM score [] = {";
  for (int i = 0; i < data.size(); i++) {
    if (data[i].second == HEX_TYPE)
      fout << "0x" << setw(2) << setfill('0') << hex << (int)data[i].first;
    else {
      fout << dec;
      fout << (int)data[i].first;
    }
    if (i < data.size()-1) {
      fout << ',';
    }
    if (i % 10 == 0) fout << '\n';
  }
  fout << "};\n";
}
