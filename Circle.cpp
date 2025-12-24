#include "Circle.h"
#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

static const double PI = 3.141592;


Circle::Circle() : Shape(), center(0,0), radius(1) {};

Circle::Circle(string color, Point2D center, double radius) : Shape(color), center(center), radius(radius){
	set_radius(radius);
}

Point2D Circle::get_center() const {
	return center;
}

void Circle::set_center(Point2D p){
	center = p;
}

double Circle::get_radius() const {
	return radius;
}

void Circle::set_radius(double r){
	if(r <= 0){
		throw invalid_argument("Radio no valido!!!");
	}

	radius = r;
}

double Circle::area() const {
	return PI * pow(radius, 2);
}

double Circle::perimeter() const {
	return 2 * PI * radius;
}

void Circle::translate(double incX, double incY){
	center.x += incX;
	center.y += incY;
}

void Circle::print(){
	cout << *this;
}

ostream& operator<<(ostream &out, const Circle &c){
	out << "[Circle: color = " << c.get_color() << "; center = " << c.get_center() << "; radius = " << c.get_radius() <<"]";
	return out;
}


