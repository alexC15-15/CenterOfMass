# Compiler und Flags
CC = gcc
CFLAGS = -Wall -g

# Projekt Name
TARGET = CenterOfMassMain

# Source Files
SOURCES = CenterOfMassMain.c CenterOfMass.c
HEADERS = CenterOfMass.h

# Build
all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET) -lm

clean:
	rm -f $(TARGET)

rebuild: clean all
