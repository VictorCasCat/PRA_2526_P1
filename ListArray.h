#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <ostream>
#include <stdexcept>
#include "List.h"
using namespace std;

template <typename T>

class ListArray;

template <typename T>
ostream& operator<<(ostream &out, const ListArray<T> &list);

template <typename T>
class ListArray: public List<T>{
	private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE = 2;

		void resize(int new_size){
			if(new_size < MINSIZE) new_size = MINSIZE;
			T* new_arr = new T[new_size];
			for(int i = 0; i < n; i++){
				new_arr[i] = arr[i];
			}
			delete[] arr;
			arr = new_arr;
			max = new_size;
		}

		void check_insert_pos(int pos) const{
			if(pos < 0 || pos > n){
				throw out_of_range("Posición invalida!");
			}
		}

		void check_acces_pos(int pos) const{
			if(pos < 0 || pos >= n){
				throw out_of_range("Posición invalida!");
			}
		}

	public:
		ListArray(): arr(new T[MINSIZE]),max(MINSIZE), n(0){}

		~ListArray() override{
		delete[] arr;
		arr = nullptr;
		max = 0;
		n = 0;
		}

		void insert(int pos, T e) override{
			check_insert_pos(pos);

			if(n == max){
				resize(max *2);
			}

			for(int i =n; i > pos; --i){
				arr[i] = arr[i-1];
			}

			arr[pos] = e;
			n++;
		}

		void append(T e) override{
			insert(n, e);
		}

		void prepend(T e) override{
			insert(0, e);
		}

		T remove(int pos) override{
			check_acces_pos(pos);

			T removed = arr[pos];

			for(int i = pos; i < n-1; i++){
				arr[i] = arr[i+1];
			}
			--n;

			if(max > MINSIZE && n <= max/4){
				resize(max/2);
			}

			return removed;
		}

		T get(int pos) override{
			check_acces_pos(pos);
			return arr[pos];
		}

		int search(T e) override{
			for(int i = 0; i < n; i++){
				if(arr[i] == e){return i;}
			}
			return -1;
		}

		bool empty() override{
			return n == 0;
		}

		int size() override{
			return n;
		}

		T operator[](int pos){
			check_acces_pos(pos);
			return arr[pos];
		}

		friend ostream& operator<< <>(ostream &out, const ListArray<T> &List);
};

template <typename T>
ostream& operator<<(ostream &out, const ListArray<T> &List){
	out<< "List => {";
	if(List.n > 0)out << "\n";
	for(int i = 0; i < List.n; i++){
		out << " " << List.arr[i] << "\n";
	}
	out << "]";
	return out;
}
#endif
