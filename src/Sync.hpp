#include "Playtune.h"


enum Type { MASTER, SLAVE };
class Sync {
  int pin_in, pin_out;
  Playtune &pt;
  Type type;
  void wait_for_signal(bool);
  void sync_init_slave();
  void sync_init_master();
  void sync_const_slave();
  void sync_const_master();
public:
  Sync(int pin_in, int pin_out, Playtune &pt, Type type): pin_in(pin_in), pin_out(pin_out), pt(pt), type(type) {
    pinMode(pin_in, INPUT);
    pinMode(pin_out, OUTPUT);
    digitalWrite(pin_out, LOW);
  }
  void sync_init();
  void sync_const();
};

#define DELAY(x) this->pt.tune_delay(x)
