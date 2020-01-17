

#include "hwlib.hpp"



extern "C" void  Compressie_assembler();

extern "C" void Text_Decoder();


extern "C" void print_text(char c){
            hwlib::cout<< c;       
}


int main( void ){	
    
    hwlib::wait_ms(200);
    hwlib::cout<<"hij begint";
    
    Compressie_assembler();
    hwlib::cout<<"hij eindigt";
    
}