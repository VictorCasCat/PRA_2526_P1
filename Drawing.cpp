#include "Drawing.h"
#include "Circle.h"
#include "Square.h"
#include <iostream>
using namespace std;

Drawing::Drawing(){
	shapes = new ListLinked<Shape*>();
}

Drawing::~Drawing(){
	while(!shapes->empty()){
		Shape* s = shapes->remove(0);
		delete s;
	}
	delete shapes;
}

void Drawing::add_front(Shape* shape){
	shapes->insert(0, shape);
}

void Drawing::add_back(Shape* shape){
	shapes->insert(shapes->size(), shape);
}

void Drawing::print_all(){
	for(int i = 0; i< shapes->size(); i++){
		Shape* s = shapes->get(i);
		s->print();
		cout << endl;
	}
}

double Drawing::get_area_all_circles(){
	double sum = 0.0;
	for(int i = 0; i < shapes->size(); i++){
		Shape* s = shapes->get(i);
		if(dynamic_cast < Circle*>(s) != nullptr){
			sum += s->area();
		}
	}
	return sum;
}

void Drawing::move_squares(double incX, double incY){
	for(int i = 0; i < shapes->size(); i++){
		Shape* s = shapes->get(i);
		if(dynamic_cast < Square*>(s) != nullptr){
			s->translate(incX, incY);
		}
	}
}


