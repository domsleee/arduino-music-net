Arduino Music
===

## Installing

- Clone this repository recursively with `git clone --recursive https://github.com/shvelo/arduino-music.git`
- Run `make` to rebuild `miditones` for your system
- Run `(cd extract; make)` to build `extract`

## Setup arduinos
Connect the PIN_IN of the master to the PIN_OUT of the slave and vice-versa.

## Generating a sketch
Modify `generate.py` to suit your needs. Namely, use `arduino boards list` to find the fbqn and serial ports that your arduinos are using, and enter these in `config` in `generate.py`. Then, use the following command to upload the sketch to your boards (default is two boards):

~~~bash
./generate.py upload <midi_input>
~~~

where `<midi_input>` is an midi file (in the format *.mid).

You can also upload to a single board using the standalone config (`-c standalone`).

## Installing `arduino-cli` for use with `generate.py`
Install [arduino-cli](https://github.com/arduino/arduino-cli). Follow the instructions provided by them, tldr:

~~~bash
arduino core update-index
arduino core install arduino:avr
~~~

I aliased `arduino-cli` as `arduino`, to use the scripts you must do this:

~~~bash
cp arduino-cli /usr/local/bin/arduino
~~~


## Acknowledgements
Based on [shvelo/arduino-music](https://github.com/shvelo/arduino-music)

### Libraries from SHuste
PlayTune from https://github.com/LenShustek/arduino-playtune   
MidiTones from https://github.com/LenShustek/miditones
