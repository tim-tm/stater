CC=gcc
CFLAGS=-Wall -Wextra -pedantic -g
DEFINES=
INCLUDES=-I./lib/raylib/src/
LIBS=-L./lib/raylib/src/ -lraylib -lm

SRCDIR=src
BUILDDIR=build
RELEASEDIR=build/release

ifeq ($(BUILD_TYPE), RELEASE)
CFLAGS=-Wall -Wextra -pedantic
BUILDDIR=$(RELEASEDIR)
DEFINES=
endif

SRC=$(wildcard $(SRCDIR)/*.c)
OBJ=$(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRC))

BINARYNAME=stater
BINARY=$(BUILDDIR)/$(BINARYNAME)

.PHONY: all setup clean destroy install uninstall

all: $(BINARY)

$(BINARY): $(BUILDDIR)/$(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $(BINARY) $(LIBS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(DEFINES) $(INCLUDES) -c $< -o $@

setup:
	git submodule update --init
	make -C lib/raylib/src
	mkdir -p $(RELEASEDIR)

clean:
	rm -rf $(BINARY)
	rm -rf $(OBJ)

destroy:
	rm -rf $(BUILDDIR)
	make -C lib/raylib/src clean

install:
	sudo cp $(BINARY) /usr/bin/

uninstall:
	sudo rm /usr/bin/$(BINARYNAME)
