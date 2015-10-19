include config.mk

SRC = xrq.c
OBJ = $(SRC:.c=.o)
BIN = $(SRC:.c=)

.POSIX:
all: $(BIN)

.c.o:
	$(CC) -c $< -o $@ $(CFLAGS)

$(BIN): $(OBJ)
	$(LD) -o $@ $(OBJ) $(LDFLAGS)

install: $(BIN)
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp -f $(BIN) $(DESTDIR)$(PREFIX)/bin
	chmod 755 $(DESTDIR)$(PREFIX)/bin/$(BIN)

uninstall:
	rm -f $(DESTIDR)$(PREFIX)/bin/$(BIN)

clean:
	rm -f $(OBJ) $(BIN)
