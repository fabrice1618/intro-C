CC      = gcc
CFLAGS  = -Wall -Wextra -g

# Flags pour la bibliotheque MySQL (utilisee uniquement par le loader)
MYSQL_CFLAGS = $(shell mysql_config --cflags)
MYSQL_LIBS   = $(shell mysql_config --libs)

BINS = loader sender

all: $(BINS)

loader: loader.c
	$(CC) $(CFLAGS) $(MYSQL_CFLAGS) -o $@ $< $(MYSQL_LIBS)

sender: sender.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(BINS)

.PHONY: all clean
