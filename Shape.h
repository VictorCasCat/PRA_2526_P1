#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <stdexcept>
#include "Point2D.h"
using namespace std;

class Shape{
	protected:
		string color;
		static bool valid_color(const string &c){
			return (c == "red"|| c == "green" || c == "blue");
		}

	public:
		Shape();
		Shape(string color);
		virtual ~Shape(){}

		string get_color() const;
		void set_color(string c);

		virtual double area() const = 0;
		virtual double preimetro() const = 0;
		virtual void translate(double incX, double incY) = 0;
		virtual void print() = 0;
};

#endif

