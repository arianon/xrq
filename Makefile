include config.mk

SRC = xrq.c
OBJ = $(SRC:.c=.o)
BIN = $(SRC:.c=)
MAN = $(SRC:.c=.1)

.POSIX:
all: $(BIN)

.c.o:
	$(CC) -c $< -o $@ $(CFLAGS)

$(BIN): $(OBJ)
	$(LD) -o $@ $(OBJ) $(LDFLAGS)

install: $(BIN)
	install -Dm755 $(BIN) $(DESTDIR)$(PREFIX)/bin
	install -Dm644 $(MAN) $(DESTDIR)$(MANPREFIX)/man1

uninstall:
	rm -f $(DESTIDR)$(PREFIX)/bin/$(BIN)

clean:
	rm -f $(OBJ) $(BIN)
