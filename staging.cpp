/**
*
*	The implementations found below
*   will most likely find a place
*	within their own header and source
*	files but will exist here for now
*	for quick testing of functionality
*
*/
#include <iostream>
#include <vector>
#include <cstdlib>

// struct for RGB values
struct RGB {
    //
    // Constructors
    RGB() : red(0), green(0), blue(0) 
    {}
    RGB(short r, short g, short b) : red(r), green(g), blue(b) 
    {}

    //
    // Methods

    // A conversion method from input of the color sensor to accurate RGB value needed?

    //
    // Fields
    short red, green, blue;
};

// struct for calculations on RGB values (i.e mean, stand. dev., etc)
struct RGBCalc {
	RGBCalc() : red(0), green(0), blue(0)
	{}
	RGBCalc(double r, double g, double b) : red(r), green(g), blue(b)
	{} 

	double red, green, blue;
};

// struct Color {
// 	Color() : color(0)
// 	{}
// 	Color(uint8_t c) : color(c) 
// 	{}

// 	uint8_t color;
// }

// Methods for StatsHandler header
RGBCalc samp_mean(std::vector<RGB> data);

int main() {
	srand(time(NULL));
	std::vector<RGB> d; 
	d.resize(10);

std::cout << "Red\tGreen\tBlue\n";

	for(int i = 0; i < d.size(); i++) {
		d[i].red 	= rand() % 256;
		d[i].green 	= rand() % 256;
		d[i].blue 	= rand() % 256;
		std::cout << d[i].red << "\t" << d[i].green << "\t" << d[i].blue << "\n";
	}

	//samp_mean(d);
	RGBCalc test = samp_mean(d);
	std::cout << test.red << " " << test.green << " " << test.blue << "\n";
	return 0;
}

RGBCalc samp_mean(std::vector<RGB> data) {
	RGBCalc color;
	int sum_red = 0, sum_green = 0, sum_blue = 0;

	// Sum the squared RGB values
	for(int i = 0; i < data.size(); i++) {
		sum_red 		+= data[i].red * data[i].red; 
		sum_green 		+= data[i].green * data[i].green;
		sum_blue 		+= data[i].blue * data[i].red;
	}
	// Sqrt the mean of their squared values to compute average color
	color.red 	= sqrt(sum_red/data.size());
	color.green = sqrt(sum_green/data.size());
	color.blue 	= sqrt(sum_blue/data.size());

	return color;
}