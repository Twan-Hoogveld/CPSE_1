#include "hwlib.hpp"
#include "circle_clock.hpp"

int main( void ){	
   
    
    
    hwlib::wait_ms( 2000 );   
   
    namespace target = hwlib::target;
   
    auto scl     = target::pin_oc( target::pins::scl );
    auto sda     = target::pin_oc( target::pins::sda );
    auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );
    auto oled    = hwlib::glcd_oled( i2c_bus, 0x3c ); 
    auto font    = hwlib::font_default_16x16();
    auto display = hwlib::terminal_from( oled, font );
    auto b_Hour = hwlib::target::pin_in(  hwlib::target::pins::d11 );
    auto b_Min = hwlib::target::pin_in( hwlib::target::pins::d12 );
    auto b_Confirm = hwlib::target::pin_in( hwlib::target::pins::d13) ;

    clock klok(oled, b_Hour, b_Min, b_Confirm, font, display);
    klok.run_Clock();


}