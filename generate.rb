#!/usr/bin/env ruby

require 'fileutils'

exit 0 if ARGV.length < 1

file = ARGV[0]
basename = File.basename(file, '.mid')
dirname = File.dirname file

system "./miditones -t6 -v -pt -d -i \"#{dirname}/#{basename}\""

melody = File.read "#{dirname}/#{basename}.c"

source = File.read "./source.cpp"

source['!!MELODY!!'] = melody

FileUtils::mkdir_p "./out/#{basename}"
FileUtils::cp("./playtune/Playtune.cpp", "./out/#{basename}/")
FileUtils::cp("./playtune/Playtune.h", "./out/#{basename}/")

File.open("./out/#{basename}/#{basename}.ino", "w") { |io|
	io.write source
}

#FileUtils::rm("#{dirname}/#{basename}.c")