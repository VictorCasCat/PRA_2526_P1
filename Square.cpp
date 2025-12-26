#include "Square.h"
#include <iostream>
#include <cmath>
using namespace std;


static bool same_double(double a, double b, double eps = 1e-9){
	return fabs(a - b) < eps;
}

bool Square::check(Point2D* vertices){
	if(vertices  == nullptr){
		return false;
	}

	double d01 = Point2D::distance(vertices[0], vertices[1]);
	double d12 = Point2D::distance(vertices[1], vertices[2]);
	double d23 = Point2D::distance(vertices[2], vertices[3]);
	double d30 = Point2D::distance(vertices[3], vertices[0]);

	return same_double(d01,d12) && same_double(d12,d23) && same_double(d23,d30);
}

Square::Square() : Rectangle(){
	Point2D verts[N_VERTICES] = {
		Point2D(-1, 1),
		Point2D(1, 1),
		Point2D(1, -1),
		Point2D(-1, -1)
	};
	set_vertices(verts);
}

Square::Square(string color, Point2D* vertices) : Rectangle(){
	set_color(color);
	set_vertices(vertices);
}

void Square::set_vertices(Point2D* vertices){
	if(!check(vertices)){
		throw invalid_argument("Pon valores validos para un cuadrado!!");
	}
	for(int i = 0; i < N_VERTICES; i++){
		vs[i] = vertices[i];
	}
}

void Square::print(){
	cout << *this;
}

ostream& operator<<(ostream &out, const Square &s){
	out << "[Square: color = " << s.get_color() << "; v0 = " << s.vs[0] << "; v1 = " << s.vs[1] << "; v2 = " << s.vs[2] << "; v3 = " << s.vs[3] << "]";
	return out;
}

