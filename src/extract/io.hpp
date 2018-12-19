#ifndef IO_H
#define IO_H
#include <fstream>
#include <vector>
#include "globals.hpp"
using namespace std;

vector<byte> read_score(char *filename);
void print_chan(string &filepath, int ntones, vector<p> &data);
#endif