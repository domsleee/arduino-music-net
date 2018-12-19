#include "Sync.hpp"

const int LENGTH = 35;
const int LENGTH_DELTA = 2;
const int LENGTH_LO = LENGTH - LENGTH_DELTA;
const int LENGTH_HI = LENGTH + LENGTH_DELTA;
const int SUCCESS = 31;

void Sync::sync_init() {
  if (this->type == MASTER) {
    sync_init_master();
  }
  else {
    sync_init_slave();
  }
}

void Sync::sync_init_master() {
 wait_for_signal(true);  
}

void Sync::sync_init_slave() {
  wait_for_signal(false);

  // deliver output once.
  int8_t out_status = 1;
  int8_t out_ct = 0;
  digitalWrite(this->pin_out, out_status);
  DELAY(1);

  int8_t out_cycles_rem = SUCCESS;
  for (;out_cycles_rem > 0;) {
    if (++out_ct == LENGTH) {
      out_ct = 0;
      out_status ^= 1;
      digitalWrite(this->pin_out, out_status);
      out_cycles_rem--;
    }
    DELAY(1);
  }
}

void Sync::wait_for_signal(bool output_signal) {
  int8_t last = -1;
  int8_t last_amount = 0;
  int8_t out_status = 0;
  int8_t out_ct = 0;
  int8_t success = 0;

  for (;;) {
    int n = digitalRead(this->pin_in);
    if (n == last) {
      if (last_amount != -1) {
        if (++last_amount > LENGTH_HI) last_amount = -1;
      }
    }
    else {
      if (LENGTH_LO <= last_amount && last_amount <= LENGTH_HI) {
        Serial.println(success);
        if (++success == SUCCESS) break;
      }
      else success = 0;

      last_amount = 1;
    }
    last = n;

    if (output_signal && ++out_ct == LENGTH) {
      out_ct = 0;
      out_status ^= 1;
      digitalWrite(this->pin_out, out_status);
    }
    DELAY(1);
  }
}
