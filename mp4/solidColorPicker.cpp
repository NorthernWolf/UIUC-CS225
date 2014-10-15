#include "solidColorPicker.h"

/**
 * Constructs a new solidColorPicker.
 * 
 * @param fillColor The color for this color picker.
 */
solidColorPicker::solidColorPicker(RGBAPixel fillColor)
{
	//set color defined in .h file equal to fillColor
	color = fillColor;
}

/**
 * Picks the color for pixel (x, y).
 *
 * Simply returns the same color (used to construct the picker) all of the
 * time.
 */
RGBAPixel solidColorPicker::operator()(int x, int y)
{
	//pretty basic here
	return color;
}
