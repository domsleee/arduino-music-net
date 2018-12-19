Arduino Music
===

## Installing

- Clone this repository recursively with `git clone --recursive https://github.com/domsleee/arduino-music-net.git`
- Run `make` from the root of the repository

Install [arduino-cli](https://github.com/arduino/arduino-cli). Follow the instructions provided by them, or tldr (after aliasing `arduino-cli` to `arduino`):

~~~bash
arduino core update-index
arduino core install arduino:avr
~~~

`./generate.py` makes system calls `arduino-cli` using the alias `arduino`. To make the alias:

~~~bash
cp arduino-cli /usr/local/bin/arduino
~~~

## Setup arduinos
Connect the PIN_IN of the master to the PIN_OUT of the slave and vice-versa (see `./src/templates/master.cpp` and `./src/templates/slave.cpp` for these values).

## Generating a sketch
Modify `generate.py` to suit your needs. Namely, use `arduino boards list` to find the fbqn and serial ports that your arduinos are using, and enter these in `config` in `generate.py`. Then, use the following command to upload the sketch to your boards (default is two boards):

~~~bash
./generate.py upload <midi_input>
~~~

where `<midi_input>` is an midi file (in the format *.mid).

You can also upload to a single board using the standalone config (`-c standalone`).

## Acknowledgements
Based on [shvelo/arduino-music](https://github.com/shvelo/arduino-music)

### Libraries from LenShustek
PlayTune from https://github.com/LenShustek/arduino-playtune   
MidiTones from https://github.com/LenShustek/miditones
