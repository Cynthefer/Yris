CXX = g++

PREFIX = /usr/local/

BINDIR = $(PREFIX)bin

INSTALL = install

TARGET = build

CXXFLAGS = -Iinclude 

SOURCES = $(wildcard src/*.cpp)

OUTPUT = build/yris

$(TARGET): $(SOURCES)
	clear
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(OUTPUT)

$(INSTALL): $(TARGET)
	$(INSTALL) -d $(BINDIR)
	$(INSTALL) -m 755 $(OUTPUT) $(BINDIR)/
	rm -rf $(OUTPUT)

test: $(TARGET)
	clear
	./$(OUTPUT)
	rm -rf $(OUTPUT)

clean:
	rm -rf $(OUTPUT)

uninstall:
	rm -rf /usr/local/bin/yris

.PHONY: build install clean test
