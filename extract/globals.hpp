typedef unsigned char byte;

#ifdef DEBUG
#define dprintf(...) printf(__VA_ARGS__)
#else
#define dprintf(...) 
#endif

#define ERROR(...) { printf(__VA_ARGS__); exit(1); }
