CC=gcc
CFLAGS=-Wall -Wextra -pedantic
DEFINES=
INCLUDES=-I./lib/raylib/src/
LIBS=-L./lib/raylib/src/ -lraylib -lm

SRCDIR=./src
BUILDDIR=./build
INSTALLDIR=/usr/bin/

ifeq ($(BUILD_TYPE), DEBUG)
CFLAGS += -g -ggdb
endif

SRC=$(wildcard $(SRCDIR)/*.c)
OBJ=$(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRC))

BINARYNAME=stater
BINARY=$(BUILDDIR)/$(BINARYNAME)

ifeq ($(OS), Windows_NT)
LIBS += -lopengl32 -lgdi32 -lwinmm

INSTALLDIR=C:\Windows\System32\

BINARYNAME=stater.exe
endif

.PHONY: all setup clean destroy install uninstall

all: $(BINARY)

$(BINARY): $(BUILDDIR)/$(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $(BINARY) $(LIBS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(DEFINES) $(INCLUDES) -c $< -o $@

setup:
	git submodule update --init
	make -C lib/raylib/src
	mkdir -p $(BUILDDIR)

clean:
	rm -rf $(BINARY)
	rm -rf $(OBJ)

destroy:
	rm -rf $(BUILDDIR)
	make -C lib/raylib/src clean

install:
	cp $(BINARY) $(INSTALLDIR)

uninstall:
	rm $(INSTALLDIR)$(BINARYNAME)
