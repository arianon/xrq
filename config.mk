PREFIX = /usr
MANPREFIX = $(PREFIX)/share/man

CFLAGS = -pedantic -Wall -Os
LDFLAGS = -L/usr/lib -lc -lX11

CC = cc
LD = $(CC)
