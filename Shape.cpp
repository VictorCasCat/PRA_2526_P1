#include "Shape.h"
using namespace std;

Shape::Shape(string color) : color("red"){
	set_color(color);
}

string Shape::get_color() const{
	return color;
}

void Shape::set_color(string c){
	if(!valid_color(c)){
		throw invalid_argument("Color no valido!!");
	}
	color = c;
}
