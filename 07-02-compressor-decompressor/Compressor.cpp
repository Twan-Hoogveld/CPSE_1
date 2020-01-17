#include <iostream>
#include <fstream>

#include "compressor.hpp" 
#include "decompressor.hpp" 

int main( void ){	
   lz_compressor< 4096 > compressor;
 
   std::ifstream f1;
   f1.open( "wilhelmus.txt" );
   if( ! f1.is_open()){
      std::cerr << "input file not opened";
      return -1;      
   }
   
    std::ofstream f3;
   f3.open( "Compressie_assembler.asm", std::ofstream::trunc);
   if( ! f3.is_open()){
      std::cerr << "input file not opened";
      return -1;      
   }
    f3 << ".cpu cortex-m0 \ntekst:\n\t.asciz \"";
    f3.close();
    f3.open( "Compressie_assembler.asm", std::ofstream::app);
   

   
   
   
   
   compressor.compress( 
      [ &f1 ]()-> int { auto c = f1.get(); return f1.eof() ? '\0' : c; },
      [ &f3 ]( char c ){if(c =='\n'){f3.put('\\'); f3.put('n');}else{(f3.put(c));} }
    );
    f3 << "\\0\" \n.align 1\n.text\n.global Compressie_assembler \n.global tekst\n\nCompressie_assembler:\n\tLDR R0, =tekst\n\tBL Text_Decoder\n\ndone:\n\tMOV PC, LR";




   f1.close();
   f3.close();
 //   Compressie_assembler();
   
   
   
   
   
   
  /* 
   
   f1.open( "compressed.txt" );
   if( ! f1.is_open()){
      std::cerr << "compressed file not opened";
      return -1;      
   }   
   
   lz_decompressor decompressor;
   decompressor.decompress( 
      [ &f1 ]()-> int { auto c = f1.get(); return f1.eof() ? '\0' : c; },
      [ &f2 ]( char c ){ std::cout << c; }
   );
    * */
}