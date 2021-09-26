CC=gcc
CFLAGS=-DWall -Dwerror -g

all : translator

translator: translator.c Dict.c Dict.h

