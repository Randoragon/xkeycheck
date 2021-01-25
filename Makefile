CC=gcc
CFLAGS=-std=c99 -pedantic -Wall
LDFLAGS=-lX11
OBJS=xkeycheck.o
OUT=xkeycheck
DESTDIR=
PREFIX=/usr/local
MANPREFIX=/usr/share/man

all: main

main: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(OUT)

%.o: %.c
	$(CC) -c $(CFLAGS) $^ -o $@

clean:
	rm -f *.o

debug: CFLAGS += -g -Og
debug: clean $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o a.out

install: CFLAGS += -O3
install: clean all
	@echo installing $(OUT)...
	@mkdir -p $(DESTDIR)$(PREFIX)/bin
	@cp -- $(OUT) $(DESTDIR)$(PREFIX)/bin
	@chmod 755 $(DESTDIR)$(PREFIX)/bin/$(OUT)
	@echo installing man page...
	@cp xkeycheck.1 $(DESTDIR)$(MANPREFIX)/man1/xkeycheck.1
	@chmod 644 $(DESTDIR)$(MANPREFIX)/man1/xkeycheck.1

