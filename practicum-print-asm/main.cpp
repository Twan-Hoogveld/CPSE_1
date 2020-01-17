#include "hwlib.hpp"

extern "C" void uart_put_char( char c ){
    hwlib::cout << c;
}


extern "C" void print_asciz( const char * s );


extern "C" void application();

extern "C" void convert_char( const char * g);

int main( void ){	
   
   namespace target = hwlib::target;   
    

   hwlib::wait_ms( 2000 );
    namespace target = hwlib::target;   

    hwlib::wait_ms( 2000 );
    //hwlib::cout << "hallo\n";

    application();
}

/* copy van opdracht 1.1
global print_asciz

print_asciz:
    CMP R0, #0
    BEQ done
    PUSH R0
    uart_put_char //volgens mij klopt dit zo, maar vraag na
    ADD R0, #1
    B print_asciz
    
done:
    MOV PC, LR
*/

/* Copy van opdracht 1.2
global application

application:
>>>>>>> Stashed changes

    push R0
    print_asciz

done:
    MOV PC, LR
*/


/*copy van opdracht 1.3
 extern "C" void convert_char( const char * g){
        if(g <=122 && g >=97){
            g -= 32;
        }
        else if(g <= 90 && g >= 65){
            g += 32;
        }
}

*/
  







/*copy van opdracht 1.3 (niet correct maar wel handig)
extern "C" void convert_char( const char * g){
    For(int i=0; g[i] != '\0'; i++){
        if(g[i]<=122 && g[i]>=97){
            g[i] -= 32;
        }
        else if(g[i]<=90 && g[i] >= 65){
            g[i] += 32;
        }
    }
}
*/