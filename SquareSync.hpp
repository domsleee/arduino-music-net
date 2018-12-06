
#include "Playtune.h"

class SquareSync {
  int pin_in, pin_out;
  Playtune &pt;
  wait_for_signal(bool);
public:
  SquareSync(int pin_in, int pin_out, Playtune &pt): pin_in(pin_in), pin_out(pin_out), pt(pt) {
    pinMode(pin_in, INPUT);
    pinMode(pin_out, OUTPUT);
    digitalWrite(pin_out, LOW);
  }
  sync_master();
  sync_slave();
};
