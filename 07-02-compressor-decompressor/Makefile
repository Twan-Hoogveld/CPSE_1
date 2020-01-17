
# source & header files in this project (main.cpp is automatically assumed)
binaries = Compressor.o

all: Compress
	make run   
	
Compress: Compressor.o 
	g++ -std=c++17 Compressor.o  -o make_Compressor.exe
	chmod u+x make_Compressor.exe
	./make_Compressor.exe 
	
Compressor.o: match.hpp compressor.hpp decompressor.hpp Compressor.cpp 
	g++ -std=c++17 -c Compressor.cpp

clean_Compressor:
	rm -f $(binaries) *.o 
	make clean

	
# source files in this project (main.cpp is automatically assumed)
SOURCES := Compressie_assembler.asm Text_Decoder.asm

# header files in this project
HEADERS := 
# other places to look for files for this project
SEARCH  := 

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE) ../
include $(RELATIVE)Makefile.due


