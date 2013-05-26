CTARGETS = 100 101 102
CXXTARGETS = 103
CFLAGS = -lm -O2 -ansi
CXXFLAGS = -lm -O2
CLEAN_TARGETS = $(CTARGETS) $(addsuffix .exe,$(CTARGETS)) \
		$(CXXTARGETS) $(addsuffix .exe,$(CXXTARGETS))

all: $(CTARGETS) $(CXXTARGETS)

clean:
	rm -f $(CLEAN_TARGETS)
