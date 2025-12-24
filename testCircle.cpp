#include <iostream>
#include "Circle.h"
#include "Point2D.h"
using namespace std;

int main(){
	Circle c1;
	Circle c2("green", Point2D(1,1), 2);
	cout << "c1 = " << c1 << endl;
	cout << "c2 = " << c2 << endl;
	cout << endl;

	c1.set_center(c2.get_center());
	c1.set_radius(c2.get_radius());
	c2.set_color("blue");

	cout << "c1 = " << c1 << endl;
	cout << "c2 = " << c2 << endl;
}
