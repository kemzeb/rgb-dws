#include <iostream>

#include "mbed.h"
#include "Map.hpp"
#include "TCS3200.h"


/**
Nucleo - TCS3200 interfacing pins 

s0 (PA_8);    // pin D7
s1 (PB_10);   // pin D6
s2 (PB_4);    // pin D5
s3 (PB_5);    // pin D4

*/

int main() {
    long red_pw, green_pw, blue_pw;
    
    // Pulse width calibration values
    long red_min    = 31;
    long red_max    = 301;
    long green_min  = 37;
    long green_max  = 389;
    long blue_min   = 29;
    long blue_max   = 310;
    
    TCS3200 pw(PA_8, PB_10, PB_4, PB_5, PA_5);
    
    Map r_map(red_min, red_max, 0, 255);
    Map g_map(green_min, green_max, 0, 255);
    Map b_map(blue_min, blue_max, 0, 255);
    
    
    pw.SetMode(TCS3200::SCALE_100);
    
    while(1) {
        red_pw     = pw.ReadRed();
        green_pw   = pw.ReadGreen();
        blue_pw    = pw.ReadBlue();
        
       // printf("Red:    %d        Green: %d         Blue: %d  \n\r", 
//            red_pw, green_pw, blue_pw);
            
        printf("Red:    %d        Green: %d         Blue: %d  \n\r", 
            r_map.Calculate(red_pw), g_map.Calculate(green_pw), 
            b_map.Calculate(blue_pw) );
        wait_us(1000000);
    }
}