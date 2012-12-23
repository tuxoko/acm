CTARGETS = 100 102
CXXTARGETS = 103
CSOURCES = $(addsuffix .c,$(CTARGETS))
CXXSOURCES = $(addsuffix .cpp,$(CXXTARGETS))
CFLAGS = -lm -O2 -ansi
CXXFLAGS = -lm -O2
DEBUG_CFLAGS = -lm -g
CDEBUG_TARGETS = $(addsuffix d,$(CTARGETS))
CXXDEBUG_TARGETS = $(addsuffix d,$(CXXTARGETS))
CLEAN_TARGETS = $(CTARGETS) $(CDEBUG_TARGETS) $(addsuffix .exe,$(CTARGETS)) \
		$(addsuffix .exe,$(CDEBUG_TARGETS)) $(CXXTARGETS) \
		$(CXXDEBUG_TARGETS) $(addsuffix .exe,$(CXXTARGETS)) \
		$(addsuffix .exe,$(CXXDEBUG_TARGETS))

all: $(CTARGETS) $(CXXTARGETS)

$(CTARGETS): $(CSOURCES)
	$(CC) $(CFLAGS) $@.c -o $@
	$(CC) $(CDEBUG_CFLAGS) $@.c -o $@d

$(CXXTARGETS): $(CXXSOURCES)
	$(CXX) $(CXXFLAGS) $@.cpp -o $@
	$(CXX) $(DEBUG_CFLAGS) $@.cpp -o $@d

clean:
	rm -f $(CLEAN_TARGETS)
