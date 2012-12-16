TARGETS = 100
SOURCES = $(addsuffix .c,$(TARGETS))
CFLAGS = -lm -O2 -ansi
DEBUG_CFLAGS = -lm -g
DEBUG_TARGETS = $(addsuffix d,$(TARGETS))
CLEAN_TARGETS = $(TARGETS) $(DEBUG_TARGETS) $(addsuffix .exe,$(TARGETS)) \
				$(addsuffix .exe,$(DEBUG_TARGETS))

all: $(TARGETS)

$(TARGETS): $(SOURCES)
	$(CC) $(CFLAGS) $@.c -o $@
	$(CC) $(DEBUG_CFLAGS) $@.c -o $@d

clean:
	rm -f $(CLEAN_TARGETS)
