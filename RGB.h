/**
*
*
*   
*
*
*/

#ifndef RGB_H
#include <cstdint>

namespace rgb_lsd {

    class RGB {
    public:
    
    //
    //Constructors
    RGB();
    RGB(uint8_t r, uint8_t g, uint8_t b);
    //RGB(float r, float g, float b);

    //
    // Methods

    //
    // Getters
    uint8_t get_red();
    uint8_t get_green();
    uint8_t get_blue();
    //
    //Setters
    void set_red();
    void set_blue();
    void set_green();

    private:

    uint8_t red, green, blue;

    };
} // namespace rgb_lsd

#endif