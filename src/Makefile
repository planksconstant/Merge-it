CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = mergeit
SRC = MergeingEngine.cpp

# Installation paths (Defaults to /usr/local/bin)
PREFIX ?= /usr/local
BINDIR = $(PREFIX)/bin

HAS_PKG_CONFIG := $(shell command -v pkg-config 2> /dev/null)

ifdef HAS_PKG_CONFIG
    CXXFLAGS += $(shell pkg-config --cflags libqpdf)
    LDFLAGS += $(shell pkg-config --libs libqpdf)
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S), Darwin)
        UNAME_M := $(shell uname -m)
        ifeq ($(UNAME_M), arm64)
            CXXFLAGS += -I/opt/homebrew/include
            LDFLAGS += -L/opt/homebrew/lib
        else
            CXXFLAGS += -I/usr/local/include
            LDFLAGS += -L/usr/local/lib
        endif
    endif
    LDFLAGS += -lqpdf
endif

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(LDFLAGS) -o $(TARGET)

# Copy the compiled binary into the system's global binary directory
install: all
	mkdir -p $(DESTDIR)$(BINDIR)
	cp -f $(TARGET) $(DESTDIR)$(BINDIR)
	chmod 755 $(DESTDIR)$(BINDIR)/$(TARGET)

# Remove the binary from the system
uninstall:
	rm -f $(DESTDIR)$(BINDIR)/$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all install uninstall clean
