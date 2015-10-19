PREFIX = /usr

CFLAGS = -pedantic -Wall -Os
LDFLAGS = -L/usr/lib -lc -lX11

CC = cc
LD = $(CC)
