#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source & header files in this project (main.cpp is automatically assumed)
binaries = melody.cpp generator.o note_printer.o rtttl_player.o make_melody.exe
all: melody.cpp
	make run   

melody.cpp: generator.o note_printer.o rtttl_player.o 
	g++ -std=c++17  generator.o note_printer.o rtttl_player.o -o make_melody.exe
	chmod u+x make_melody.exe
	./make_melody.exe 

generator.o: generator.cpp  
	g++ -std=c++17 -c generator.cpp 

note_printer.o: note_printer.cpp
	g++ -std=c++17 -c note_printer.cpp

rtttl_player.o: rtttl_player.cpp
	g++ -std=c++17 -c rtttl_player.cpp
    
clean_melody:
	rm -f $(binaries) *.o 
	make clean

HEADERS += note.hpp
HEADERS += note_player.hpp
HEADERS += fur_elise.hpp
HEADERS += generator.hpp

HEADERS += note_player_gpio.hpp
SOURCES += note_player_gpio.cpp
HEADERS += melody.hpp
SOURCES += melody.cpp



# other places to look for files for this project
SEARCH  := 

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there

RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.due
