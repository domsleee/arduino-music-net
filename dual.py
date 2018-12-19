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
EXTRACT_BIN = rel_dir('./src/extract/extract')
MIDITONES_BIN = rel_dir('./src/lib/miditones-src/miditones')
TEMPLATE_FOLDER = rel_dir('./src/templates')
LIBS = ['./src/lib/playtune/Playtune.cpp', './src/lib/playtune/Playtune.h', './src/Sync.hpp', './src/Sync_const.cpp', './src/Sync_init.cpp']

Board = namedtuple('Board', 'name port fqbn template tones freq')
class Dir:
    def __init__(self, board: Board, basename: str):
        fname = f'{basename}_{board.name}'
        self.sketch_folder = rel_dir(f'./out/{fname}')
        self.melody_file = f'/tmp/{fname}.c'
        self.arduino_file = f'{self.sketch_folder}/{fname}.ino'
        self.template_file = f'{TEMPLATE_FOLDER}/{board.template}'
        self.compile_cmd = f'arduino compile -b "{board.fqbn}" "{self.sketch_folder}" --build-properties build.f_cpu={board.freq}000000L'
        self.upload_cmd = f'arduino upload -b "{board.fqbn}" -p {board.port} "{self.sketch_folder}"'
        self.extract_args = [self.melody_file, str(board.tones)]

configs = {
    'default': [
        Board(name='a', port='/dev/cu.usbserial-A9M9DV3R', fqbn='arduino:avr:pro', template='master.cpp', tones=3, freq=16),
        Board(name='b', port='/dev/cu.usbmodem465', fqbn='arduino:avr:micro', template='slave.cpp', tones=4, freq=16)
    ],
    'standalone': [
        Board(name='a', port='/dev/cu.usbserial-A9M9DV3R', fqbn='arduino:avr:pro', template='standalone.cpp', tones=8, freq=16)
    ],
    'test': [
        Board(name='a', port='/dev/cu.usbserial-A9M9DV3R', fqbn='arduino:avr:pro', template='master.cpp', tones=1, freq=16),
        Board(name='b', port='/dev/cu.usbmodem492', fqbn='arduino:avr:micro', template='slave.cpp', tones=1, freq=16)
    ]
}

def main(args):
    kill_screen_sessions()
    boards = configs[args.config]
    basefile = rel_dir(os.path.splitext(args.file)[0])
    syscall(f'{MIDITONES_BIN} -t{num_tones(boards)} -v -pt -pi -d -i -b "{basefile}"')
    basename = basefile.split('/')[-1]
    split_tracks(basefile, basename, boards)

    if args.command == 'compile':
        compile(boards, basename)
    elif args.command == 'upload':
        compile(boards, basename)
        upload(boards, basename)
    os.remove(f'{basefile}.bin')


def header(s):
    z = '='*64
    return f'{z}\n{s}\n{z}'


def syscall(s, failable=False, quiet=False):
    if not quiet:
        print(f'SYSCALL: {s}')
    fun = subprocess.call if failable else subprocess.check_call
    if quiet:
        fun(s, stdout=open(os.devnull, 'w'), shell=True)
    else:
        fun(s, shell=True)


def kill_screen_sessions():
    syscall('screen -S myscreeny -X kill', failable=True, quiet=True)
    syscall('screen -S myscreenx -X kill', failable=True, quiet=True)


def num_tones(boards):
    tones = 0
    for b in boards:
        tones += b.tones
    return tones


def split_tracks(basefile, basename, boards):
    """ Split tracks using extract program """
    a = [EXTRACT_BIN, f'{basefile}.bin']
    for b in boards:
        d = Dir(b, basename)
        a += d.extract_args
    syscall(' '.join([f'"{x}"' for x in a]))


def compile(boards, basename):
    print(header('Compiling for all boards!'))
    for b in boards:
        print(f'template: {b.template}, port: {b.port}, fqbn: {b.fqbn}')
        d = Dir(b, basename)
        pathlib.Path(d.sketch_folder).mkdir(parents=True, exist_ok=True)
        for lib in LIBS:
            shutil.copy(lib, f'{d.sketch_folder}/')

        repl = {
            'MELODY': open(d.melody_file).read()
        }
        src = Template(open(d.template_file).read())
        with open(d.arduino_file, 'w') as fout:
            fout.write(src.safe_substitute(repl))
        os.remove(d.melody_file)
        syscall(d.compile_cmd)


def upload(boards, basename):
    print(header('Uploading for all boards!'))
    for b in boards:
        d = Dir(b, basename)
        print("Uploading...")
        syscall(d.upload_cmd)


if __name__ == '__main__':
    parser = argparse.ArgumentParser('Compile/upload to arduino')
    parser.add_argument('command', help='either just compile or compile and then upload', choices=['compile', 'upload'])
    parser.add_argument('file', help='midi file (in the format .midi)')
    parser.add_argument('--config', '-c', help='board configuration', choices=configs.keys(), default='default')
    main(parser.parse_args())
