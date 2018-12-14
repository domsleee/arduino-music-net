//**************************************************
//
// Arduino UNO Music Player
// Run on server (UNO)
//
// Dom Slee, 2018
//
// Nick Shvelidze, 2013
//
// L. Shustek, 31 Jan 2011, initial release.
// L. Shustek, 27 Feb 2011, new score data
//
//**************************************************


#include "Playtune.h"
#include "SquareSync.hpp"

#define PIN_IN  3
#define PIN_OUT 12
#define DELAY_MS 10
typedef unsigned int uint;

!!MELODY!!

Playtune pt;
SquareSync s(PIN_IN, PIN_OUT, pt);


void setup() {
  Serial.begin(9600);
  Serial.write("!");

  // Enable pins
  pt.tune_initchan(5);
  pt.tune_initchan(6);
  pt.tune_initchan(7);
}

void loop() {
  s.sync_master();
  //while (true); //shutup
  pt.tune_playscore (score);
  while (pt.tune_playing);
}
