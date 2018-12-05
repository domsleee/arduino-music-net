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

!!MELODY!!

Playtune pt;

int val;

void setup() {
  // Enable pins
  pt.tune_initchan(4);
  pt.tune_initchan(5);
  pt.tune_initchan(6);
  pt.tune_initchan(7);
}

void loop () {
  pt.tune_playscore (score);  /* start playing */
  while (pt.tune_playing) ;   /* wait here until playing stops */
}
