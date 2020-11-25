/**
*
*
*   
*
*
*/

#ifndef RGB_HANDLER_H
#define RGB_HANDLER_H

namespace rgb_dws {
    struct RGB {
        //
        // Constructors
        RGB();
        RGB(short r, short g, short b);
        RGB(const RGB& c);

        //
        // Methods

        // A conversion method from input of the color sensor to accurate RGB value needed?

        //
        // Fields
        short red, green, blue;
    };

    // struct for calculations on RGB values (i.e mean, stand. dev., etc)
    struct RGBCalc {
        RGBCalc();
        RGBCalc(double r, double g, double b);
        RGBCalc(const RGBCalc& c);

        double redC, greenC, blueC;

    };

} // END OF NAMESPACE 'rgb_dws'

#endif
