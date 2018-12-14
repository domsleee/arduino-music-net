#ifndef GLOBALS_H
#define GLOBALS_H
using namespace std;

#define HEX_TYPE 0
#define NORMAL_TYPE 1
typedef unsigned char byte;

#define DEBUG

#ifdef DEBUG
#define dprintf(...) printf(__VA_ARGS__)
#else
#define dprintf(...) 
#endif

#define ERROR(...) { printf(__VA_ARGS__); exit(1); }

typedef pair<byte, char> p;

#endif