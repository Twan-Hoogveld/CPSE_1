#include "hwlib.hpp"
#include "note_printer.hpp"

  
void note_printer::play( const note & n ){
   if( n.frequency == 0 ){
      hwlib::wait_us( n.duration );
      
   } else {
       hwlib::wait_ms(n.duration / 1000);
        hwlib::cout<<"{"<<n.frequency<<"}, ";
      }        
}




/*
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * ten eerste, fuck mijn leven, want deze code hieronder koste mij 6 uur en bleek compleet useless te zijn
 * ten tweede, yay, nieuwe code werkte binnen 10 minuten aan typen
 * #ifdef BMPTK_TARGET
   #include "hwlib.hpp"
   #define COUT hwlib::cout
#else
   #include <iostream>
   #define HWLIB_TRACE std::cerr << "\n" << std::flush
   #define COUT std::cerr
#endif
#include "note_printer.hpp"

bool is_cijfer( char c ){ return ( c >= '0' ) && ( c <= '9' ); }
bool is_letter( char c ){ return ( c >= 'a' ) && ( c <= 'z' ); }
int frequenties[] = { 440'000, 493'880, 261'630, 293'660, 329'630, 349'230, 392'000 };




void note_printer( const char *s){
    

    
    int state = 0;
    int default_var;
    int waarde;
    int punt;
    float note_looptijd;
    int note_looptijd_int;
    int maat;
    int octaaf_timer = 0;
    int looptijd, octaaf, frequentie; 
    int def_looptijd, def_octaaf;   
    
    for( const char *p = s; state >= 0; p++ ){
        const char c = *p;

        switch(state ){
            
            case 0:
                if( c == ':' ){
                    state = 1;
                } 
                break;
                
               
            case 1:
               
                if( is_letter( c )){
                    default_var= c;
                    state = 2;    
                }
                break;

        
            case 2:
                if( c == '=' ){
                    waarde = 0;
                }
                else if( is_cijfer( c )){
                    waarde = ( 10 * waarde ) + ( c - '0' );
                    
                } 
                else if(( c == ':' ) || ( c == ',' )) {
                    if( default_var == 'o'){
                        def_octaaf = waarde;
                    } 
                    else if( default_var == 'd' ){
                        def_looptijd = waarde;
                    } 
                    else if( default_var == 'b' ){
                        maat = waarde;
                    } 
  
                    state = ( c == ':' ) ? 3 : 1;
                } 
                break;
                
                
                case 3:  
                    looptijd = def_looptijd;
                    octaaf = def_octaaf;
                    state = 4;
                    punt = 0;
            
                    if( c == ' ' ){
                        break;
                    }
                    
                case 4:   
                    if( is_cijfer( c )){
                        looptijd = c -'0';
                        state = 5;
                        break;
                    }         
            
                case 5:   
                    if( is_cijfer( c )){
                        looptijd = ( looptijd * 10 ) + ( c -'0' );
                        state = 6;
                        break;
                    } 



                case 6:   
 
                    if( is_letter( c )){
                        if( c == 'p' ){
                            frequentie = 0;
                        }
                        
                        else {
                            frequentie = frequenties[ c - 'a' ]; 
                        }    
                    }   
               
                        state = 7;
                        break;


                case 7:   
                    if( c == '#' ){
                        frequentie = 10595LL * frequentie / 10000;
                        state = 8;
                        break;
                    }
                    
                    
                case 8:
                    if( c == '.' ){
                    punt = 1;
                    state = 9;
                    break;
                    }            

                case 9:
                    if( is_cijfer( c )){
                        octaaf = c - '0';
                        state = 10;
                        break;
                    }       
                
                
                case 10:   
                    if( ( c == ',' ) || ( c == '\0') ){
                        while( octaaf > 4 ){ 
                            --octaaf;
                            octaaf_timer++;
                            frequentie *= 2; 
                        }
                        if( punt ){
                            looptijd += looptijd / 2;
                        }
                        note_looptijd =  ((maat / 60)*1000) / looptijd;     //(((60 / maat) / looptijd) * 1000);
                        note_looptijd_int = static_cast<int>(note_looptijd);
                        frequentie = frequentie/1000;
                        hwlib::wait_ms(note_looptijd_int);
                        hwlib::cout<<"{"<<frequentie<<"}, ";
                        
                        octaaf_timer = 0;
                        state = 3;

                        if( c == '\0' ){
                            hwlib::cout<<"{END}";
                            state = -1;
                        }
                    break;       
                    }
        }
    }
}
   */     
