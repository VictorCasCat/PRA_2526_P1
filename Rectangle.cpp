#include "Rectangle.h"
#include <cmath>
#include <stdexcept>
using namespace std;

static bool same_double(double a, double b, double eps = 1e-9){
	return fabs(a - b) < eps;
}

bool Rectangle::check(Point2D* vertices){
	if(vertices == nullptr){
		return false;
	}
	double d01 = Point2D::distance(vertices[0], vertices[1]);
	double d23 = Point2D::distance(vertices[2], vertices[3]);
	double d12 = Point2D::distance(vertices[1], vertices[2]);
	double d30 = Point2D::distance(vertices[3], vertices[0]);

	return same_double(d01, d23) && same_double(d12, d30);
}

void Rectangle::check_index(int ind) const {
	if(ind < 0 || ind >= N_VERTICES){
		throw out_of_range("Index out os range!!!");
	}
}

Rectangle::Rectangle() : Shape(), vs(new Point2D[N_VERTICES]){
	vs[0] = Point2D(-1, 0.5);
	vs[1] = Point2D(1, 0.5);
	vs[2] = Point2D(1, -0.5);
	vs[3] = Point2D(-1, -0.5);
}

Rectangle:: Rectangle(string color, Point2D* vertices) : Shape(color), vs(new Point2D[N_VERTICES]){
	if(!check(vertices)){
		delete[] vs;
		vs = nullptr;
		throw invalid_argument("Introduce valores validos para un rectangulo");
	}

	for(int i = 0; i< N_VERTICES; i++){
		vs[i] = vertices[i];
	}
}

Rectangle::Rectangle(const Rectangle &r) : Shape(r.color), vs(new Point2D[N_VERTICES]){
	for(int i = 0; i < N_VERTICES; i++){
		vs[i] = r.vs[i];
	}
}

Rectangle::~Rectangle(){
	delete[] vs;
	vs = nullptr;
}

Point2D Rectangle::get_vertex(int ind) const{
	check_index(ind);
	return vs[ind];
}

Point2D Rectangle:: operator[](int ind) const {
	check_index(ind);
	return vs[ind];
}

void Rectangle::set_vertices(Point2D* vertices){
	if(!check(vertices)){
		throw invalid_argument("Introduce valores validos para un rectangulo");
	}
	for(int i = 0; i < N_VERTICES; i++){
		vs[i] = vertices[i];
	}
}

Rectangle& Rectangle::operator=(const Rectangle &r){
	if(this == &r){
		return *this;
	}

	this->color = r.color;

	Point2D* new_vs = new Point2D[N_VERTICES];
	for(int i = 0; i < N_VERTICES; i++){
		new_vs[i] = r.vs[i];
	}

	delete[] vs;
	vs = new_vs;

	return *this;
}

double Rectangle::area() const{
	double base = Point2D::distance(vs[0], vs[1]);
	double height = Point2D::distance(vs[1], vs[2]);

	return base * height;
}

double Rectangle::perimeter() const{
	double base = Point2D::distance(vs[0], vs[1]);
        double height = Point2D::distance(vs[1], vs[2]);
	
	return 2 * (base + height);
}

void Rectangle::translate(double incX, double incY){
	for(int i = 0; i < N_VERTICES; i++){
		vs[i].x += incX;
		vs[i].y += incY;
	}
}

void Rectangle::print(){
	cout << *this;
}

ostream& operator<<(ostream &out, const Rectangle &r){
	out << "[Rectangle: color = " << r.get_color() << "; v0 = " << r.vs[0] << "; v1 = " << r.vs[1] << "v2 = " << r.vs[2] << "v3 = " << r.vs[3] << "]";
       return out;	
}
