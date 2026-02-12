ROM := game.gb

CC := lcc
CFLAGS := -Wa-l -Wl-m -Iinclude -Isrc

SOURCES := $(wildcard src/*.c) $(wildcard src/sprites/*.c)

all: $(ROM)

$(ROM): $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $(SOURCES)

clean:
	del /q $(ROM) 2>nul || exit 0
