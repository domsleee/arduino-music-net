#!/usr/bin/env ruby
require 'fileutils'
exit 0 if ARGV.length < 1

LIBS = ["./playtune/Playtune.cpp", "./playtune/Playtune.h", "./SquareSync.hpp", "./SquareSync.cpp"]
boards = {
    "a" => {"port" => "/dev/cu.usbserial-A9M9DV3R", "fqbn" => "arduino:avr:pro"},
    "b" => {"port" => "/dev/cu.usbmodem454", "fqbn" => "arduino:avr:micro" }
}

file = ARGV[0]
basename = File.basename(file, '.mid')
dirname = File.dirname file

system "screen -S myscreeny -X kill" # kill running screen, to free up tty
system "screen -S myscreenx -X kill" # kill running screen, to free up tty
system "./miditones -t6 -v -pt -d -i -b \"#{dirname}/#{basename}\" >/dev/null"
bin_file = "#{dirname}/#{basename}.bin"
system "./extract/extract \"#{bin_file}\" /tmp/#{basename}_a.c 3 /tmp/#{basename}_b.c 4"
#print "./extract/extract \"#{bin_file}\" /tmp/#{basename}_a.c 3 /tmp/#{basename}_b.c 4"


for v in ["a", "b"]
    port = boards[v]["port"]
    fqbn = boards[v]["fqbn"]
    print "v: #{v}, port: #{port}, fqbn: #{fqbn}\n"

    sketch_folder = "./out/#{basename}_#{v}/"
    FileUtils::mkdir_p "#{sketch_folder}"
    for lib in LIBS
        FileUtils::cp(lib, "#{sketch_folder}/")
    end

    source = File.read "./source_#{v}.cpp"
    melody = File.read "/tmp/#{basename}_#{v}.c"
    source['!!MELODY!!'] = melody
    File.open("#{sketch_folder}/#{basename}_#{v}.ino", "w") { |io|
        io.write source
    }
    FileUtils::rm("/tmp/#{basename}_#{v}.c")

    # now upload
    print "Compiling...\n"
    system "arduino compile -b \"#{fqbn}\" #{sketch_folder} >/dev/null"
    print "Uploading...\n"
    system "arduino upload -b \"#{fqbn}\" -p #{port} #{sketch_folder}"
end

