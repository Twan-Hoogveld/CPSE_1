#ifndef _CIRCLE_CLOCK_HPP
#define _CIRCLE_CLOCK_HPP

class clock{
private:   
    int hours = 0;
    int minutes = 0;
    int devide_minutes = 0;
    int devide_hours = 0;
    int r_clock = 30;
    int r_dots = 2;
    int spot = 0;
    hwlib::xy start_dots;
 
    hwlib::glcd_oled & oled;
    hwlib::target::pin_in & b_Hour;
    hwlib::target::pin_in & b_Min;
    hwlib::target::pin_in & b_Confirm;
    hwlib::font_default_16x16 & font;
    hwlib::terminal_from & display;
    hwlib::xy positions[2208];

public: 
    
    clock(hwlib::glcd_oled & oled, hwlib::target::pin_in & b_Hour,
    hwlib::target::pin_in & b_Min, hwlib::target::pin_in & b_Confirm,
    hwlib::font_default_16x16 & font, hwlib::terminal_from & display)  : 
    oled(oled),
    b_Hour(b_Hour), 
    b_Min(b_Min),
    b_Confirm(b_Confirm),
    font(font),
    display(display)
    
    {}

    constexpr hwlib::xy get_Pos(int start_posX, int start_posY, int radius, float radian);
    constexpr void clock_Positions();
    void draw_Clock();
    void set_Clock();
    void run_Clock();

};







#endif

