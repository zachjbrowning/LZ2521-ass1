CC=gcc
CFLAGS=-DWall -Dwerror -g

all : translator

translator: translator.c Dict.c Dict.h BST.c BST.h List.c List.h

practice: practice.c BST.c BST.h

