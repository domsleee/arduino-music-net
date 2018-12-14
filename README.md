Arduino Music
===

## Installing

- Clone this repository recursively with `git clone --recursive https://github.com/shvelo/arduino-music.git`
- Run `make` to rebuild `miditones` for your system
- Run `(cd extract; make)` to build `extract`

## Setup arduinos
Connect the PIN_IN of the master to the PIN_OUT of the slave and vice-versa.

## Generating a sketch
Modify `dual.rb` to suit your needs. Namely, use `arduino boards list` to find the fbqn and serial ports that your arduinos are using, and enter these in `dual.rb`. Then, use the following command to upload the sketch to your boards:

~~~bash
./dual.rb <input>
~~~

where `<input>` is an midi file.


## Installing `arduino-cli` for use with `dual.rb` and `generate.rb`
Install [arduino-cli](https://github.com/arduino/arduino-cli). Follow the instructions provided by them, tldr:

~~~bash
arduino core update-index
arduino core install arduino:avr
~~~

I aliased `arduino-cli` as `arduino`, to use the scripts you must do this:

~~~bash
cp arduino-cli /usr/local/bin/arduino
~~~

## Uses libraries from LenShustek
PlayTune from https://github.com/LenShustek/arduino-playtune   
MidiTones from https://github.com/LenShustek/miditones
