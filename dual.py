#!/usr/bin/env python3
import argparse
from collections import namedtuple
import os       # remove
import pathlib  # mkdir -p
import shutil   # cp
from string import Template
import subprocess # syscall

def rel_dir(s):
    dirname = os.path.dirname(__file__)
    return os.path.join(dirname, s)

Board = namedtuple('Board', 'name port fqbn template')
EXTRACT_BIN = rel_dir('./src/extract/extract')
MIDITONES_BIN = rel_dir('./src/lib/miditones-src/miditones')
SOURCE_FOLDER = rel_dir('./src/templates')
LIBS = ['./src/lib/playtune/Playtune.cpp', './src/lib/playtune/Playtune.h', './src/Sync.hpp', './src/Sync_const.cpp', './src/Sync_init.cpp']
boards = [
    Board(name='a', port='/dev/cu.usbserial-A9M9DV3R', fqbn='arduino:avr:pro', template='master.cpp'),
    Board(name='b', port='/dev/cu.usbmodem465', fqbn='arduino:avr:micro', template='slave.cpp')
]

def main(args):
    kill_screen_sessions()
    basefile = rel_dir(os.path.splitext(args.file)[0])
    syscall(f'{MIDITONES_BIN} -t6 -v -pt -pi -d -i -b "{basefile}"')
    basename = basefile.split('/')[-1]
    # todo - this command should reflect `boards`.
    syscall(f'{EXTRACT_BIN} "{basefile}.bin" "/tmp/{basename}_a.c" 3 "/tmp/{basename}_b.c" 4')

    if args.command == 'compile':
        compile(basename)
    elif args.command == 'upload':
        compile(basename)
        upload(basename)
    os.remove(f'{basefile}.bin')


def header(s):
    z = '='*64
    return f'{z}\n{s}\n{z}'


def syscall(s, failable=False, quiet=False):
    if not quiet:
        print(f'SYSCALL: {s}')
    quiet_str = '>/dev/null' if quiet else ''
    fun = subprocess.call if failable else subprocess.check_call
    fun(f'{s} {quiet_str}', shell=True)


def kill_screen_sessions():
    syscall('screen -S myscreeny -X kill', failable=True, quiet=True)
    syscall('screen -S myscreenx -X kill', failable=True, quiet=True)


def compile(basename):
    print(header('Compiling for all boards!'))
    for b in boards:
        print(f'template: {b.template}, port: {b.port}, fqbn: {b.fqbn}')
        fname = f'{basename}_{b.name}'
        sketch_folder = rel_dir(f'./out/{fname}')
        pathlib.Path(sketch_folder).mkdir(parents=True, exist_ok=True)
        for lib in LIBS:
            shutil.copy(lib, f'{sketch_folder}/')

        repl = {
            'MELODY': open(f'/tmp/{fname}.c').read()
        }
        src = Template(open(rel_dir(f'./src/templates/{b.template}')).read())
        with open(f'{sketch_folder}/{fname}.ino', 'w') as fout:
            fout.write(src.safe_substitute(repl))
        os.remove(f'/tmp/{fname}.c')
        syscall(f'arduino compile -b "{b.fqbn}" "{sketch_folder}"')


def upload(basename):
    print(header('Uploading for all boards!'))
    for b in boards:
        print("Uploading...")
        fname = f'{basename}_{b.name}'
        sketch_folder = rel_dir(f'./out/{fname}')
        syscall(f'arduino upload -b "{fqbn}" -p {port} "{sketch_folder}"')


if __name__ == '__main__':
    parser = argparse.ArgumentParser('Compile/upload to arduino')
    parser.add_argument('command', help='either just compile or compile and then upload', choices=['compile', 'upload'])
    parser.add_argument('file', help='midi file (in the format .midi)')
    main(parser.parse_args())
