#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"
using namespace std;

template <typename T>
class ListLinked;

template <typename T>
ostream& operator<<(ostream &out, const ListLinked<T> &List);

template <typename T>
class ListLinked : public List<T> {
	private:
		Node<T>* first;
		int n;

		void check_insert_pos(int pos) const {
			if(pos < 0 || pos > n){
				throw out_of_range("Posición invalida");
			}
		}

		void check_acces_pos(int pos) const{
			if(pos < 0 || pos >= n){
				throw out_of_range("Posición invalida");
			}
		}

		Node<T>* node_at(int pos) const{
			Node<T>* cur = first;
			for(int i = 0; i < pos; i++){
				cur = cur -> next;
			}
			return cur;
		}

	public:
		ListLinked() : first(nullptr), n(0) {}

		~ListLinked() override{
			while(first != nullptr){
				Node<T>* aux = first->next;
				delete first;
				first = aux;
			}
			n=0;
		}

		void insert(int pos, T e) override{
			check_insert_pos(pos);

			if(pos == 0){
				first = new Node<T>(e,first);
			}else{
				Node<T>* prev = node_at(pos-1);
				prev->next = new Node<T>(e, prev->next);
			}
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

			Node<T>* to_delete = nullptr;
			T removed;

			if(pos == 0){
				to_delete = first;
				removed = first -> data;
				first = first -> next;
			}else{
				Node<T>* prev = node_at(pos-1);
				to_delete = prev -> next;
				removed  = to_delete -> data;
				prev -> next = to_delete -> next;
			}
			delete to_delete;
			--n;
			return removed;
		}

		T get(int pos) override{
			check_acces_pos(pos);
			return node_at(pos) -> data;
		}

		int search(T e) override{
			Node<T>* cur = first;
			int i = 0;
			while(cur != nullptr){
				if (cur -> data == e){
					return i;
				}
				cur = cur -> next;
				i++;
			}
			return -1;

		}

		bool empty() override{
			return n == 0;
		}

		int size() override{
			return n;
		}

		T operator [](int pos){
			check_acces_pos(pos);
			return node_at(pos)-> data;
		}
		friend ostream& operator<< <>(ostream &out, const ListLinked<T> &List);

};


template <typename T>
ostream& operator<<(ostream &out, const ListLinked<T> &List){
	out<< "List => [";
	if(List.n > 0) out << "\n";

	Node<T>* cur = List.first;
	while(cur != nullptr){
		out << " "<< cur -> data<<"\n";
		cur = cur -> next;
	}

	out << "]";
	return out;
}

#endif
