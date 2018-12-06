#!/usr/bin/env ruby
require 'fileutils'
exit 0 if ARGV.length < 1

boards = {
    "a" => {"port" => "/dev/cu.usbserial-A9M9DV3R", "fqbn" => "arduino:avr:pro"},
    "b" => {"port" => "/dev/cu.usbmodem347", "fqbn" => "arduino:avr:micro" }
}

file = ARGV[0]
basename = File.basename(file, '.mid')
dirname = File.dirname file

system "screen -S myscreeny -X kill" # kill running screen, to free up tty
system "screen -S myscreenx -X kill" # kill running screen, to free up tty
system "./miditones -t6 -v -pt -d -i \"#{dirname}/#{basename}\" >/dev/null"

for v in ["a", "b"]
    port = boards[v]["port"]
    fqbn = boards[v]["fqbn"]
    print "v: #{v}, port: #{port}, fqbn: #{fqbn}\n"

    FileUtils::cp("#{dirname}/#{basename}.c", "#{dirname}/#{basename}_#{v}.c")

    sketch_folder = "./out/#{basename}_#{v}/"
    FileUtils::mkdir_p "#{sketch_folder}"
    FileUtils::cp("./playtune/Playtune.cpp", "#{sketch_folder}/")
    FileUtils::cp("./playtune/Playtune.h", "#{sketch_folder}/")
    FileUtils::cp("./playtune/Playtune.h", "#{sketch_folder}/")
    FileUtils::cp("./SquareSync.hpp", "#{sketch_folder}/")
    FileUtils::cp("./SquareSync.cpp", "#{sketch_folder}/")

    source = File.read "./source_#{v}.cpp"
    melody = File.read "#{dirname}/#{basename}_#{v}.c"
    source['!!MELODY!!'] = melody
    File.open("#{sketch_folder}/#{basename}_#{v}.ino", "w") { |io|
        io.write source
    }
    FileUtils::rm("#{dirname}/#{basename}_#{v}.c")

    # now upload
    print "Compiling...\n"
    system "arduino compile -b \"#{fqbn}\" #{sketch_folder} >/dev/null"
    print "Uploading...\n"
    system "arduino upload -b \"#{fqbn}\" -p #{port} #{sketch_folder}"
end

