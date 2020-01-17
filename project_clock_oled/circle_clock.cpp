#include "hwlib.hpp"
#include "circle_clock.hpp"
#include <math.h>
#include <time.h>
#define PI  3.141592653589

constexpr hwlib::xy clock::get_Pos(int start_posX, int start_posY, int radius, float radian){
    return hwlib::xy( (start_posX + (radius * cos(radian))), (start_posY + (radius * sin(radian))));
    
}

constexpr void clock::clock_Positions(){

    for(float j = 0.0 ;j <= ((2 * PI) - 0.1); j+= (PI / 6)){
       start_dots =  get_Pos(64, 32, r_clock, j);
            for(float i = 0.0; i <= (2 * PI); i+= (PI / 4.500001)){
                positions[spot] = get_Pos((start_dots.x ), (start_dots.y ), r_dots, i);
                spot++;
            }
    }
    for(int q = 0; q < 60 ; q++){
        for(int p = 1; p <= r_clock; p++){
            positions[spot] = get_Pos(64, 32, p, (((q *6)-90) * (PI/180)));
            spot++;
        }
    }
    for(int w = 0; w < 12 ; w++){
        for(int o = 1; o <= (r_clock*0.7); o++){
            positions[spot] = get_Pos(64, 32, o, (((w *30)-90) * (PI/180)));
            spot++;
           
        }
         
    }
    
}



void clock::draw_Clock(){
    display <<  "\t0000" << hours << ":" << minutes << hwlib::flush;
    for(int u = 0 ; u < 120 ; u++){
        oled.write(positions[u]);
    }
    for(int r = 0; r < 30 ; r++){
        oled.write(positions[(120 + ((minutes*30 ) + r))]);
    }
    for(int t = 0; t < 21 ; t++){
        oled.write(positions[(1920 + ((hours*21) + t))]);
        
    }
    

     oled.flush();  
}






void clock::set_Clock(){

    display << "\t0101"  << hours << ":" << minutes << hwlib::flush;
    
    while(b_Confirm.read() == 1){
        hwlib::wait_ms(50);
        if(!b_Hour.read()){
            ( hours == 12 ) ? (hours = 0) : (hours++);
            oled.clear();
            display <<  "\t0101" << hours << ":" << minutes << hwlib::flush;
            
        }else if(!b_Min.read()){
            ( minutes == 60 ) ? (minutes = 0) : (minutes++);
            oled.clear();
            display <<  "\t0101" << hours << ":" << minutes << hwlib::flush;
        }
    }
    oled.clear();
}


void clock::run_Clock(){
    
    hwlib::cout << std::max(0,-32);
    /*
    
    
    oled.clear();
    oled.flush();
    clock_Positions();
    set_Clock();
    draw_Clock();
    
    for(;;){
        hwlib::cout << "{ "<< hours << " : " << minutes << " : " << ((hwlib::now_us() / 1000000) / (devide_minutes+1)) << " }\n";
        if((int)((hwlib::now_us()/1000000)) == (60 * (devide_minutes +1))){
            minutes++;
            devide_minutes++;
            if(minutes == (60*(devide_hours+1))){
                minutes = 0;
                hours++;
                devide_hours++;
            }
            if(hours == 12){
                hours = 0;
            }
            oled.clear();
            draw_Clock();
        }
    }
     * */

    
}

