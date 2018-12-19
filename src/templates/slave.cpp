//**************************************************
//
// Arduino UNO Music Player
// Run on client (leonardo/micro)
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
#include "Sync.hpp"

#define PIN_IN  9
#define PIN_OUT 14
#define DELAY_MS 10

typedef unsigned int uint;

$MELODY

Playtune pt;
Sync s(PIN_IN, PIN_OUT, pt, SLAVE);

void setup() {
  Serial.begin(9600);

  // Enable pins
  pt.tune_initchan(4);
  pt.tune_initchan(5);
  pt.tune_initchan(6);
  pt.tune_initchan(7);
}

void loop() {
  s.sync_init();
  //while (true); //shutup
  pt.tune_playscore(score);  /* start playing */
  while (pt.tune_playing) ;   /* wait here until playing stops */
  pt.tune_delay(100);
}

