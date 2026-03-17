#ifndef VECTOR_H
#define VECTOR_H

#include<iostream>
#include<initializer_list>

using namespace std;

class Vector {
	private:
		size_t sz;
		size_t max_sz;
		double* values;
	public:
		Vector();
		Vector(const Vector& other);
		Vector(size_t n);
		Vector(initializer_list<double> list);
		~Vector();

		Vector& operator=(const Vector& other);
		size_t size() const;
		bool empty() const;
		void clear();
		void reserve(size_t n);
		void shrink_to_fit();
		void push_back(double x);
		void pop_back();
		double& operator[](size_t index);
		const double& operator[](size_t index) const;
		size_t capacity() const;
		friend ostream& operator<<(ostream& os, const Vector& v);
}

Vector::Vector() : sz(0), max_sz(0), values(nullptr) {}

Vector::Vector(const Vector& other) : sz(sz.other), max_sz(max_sz.other), values(nullptr) {
	if(max_sz > 0) {
		values = new double[max_sz];
		for(size_t i = 0; i < sz; i++) {
			values[i] = other.values[i];
		}
	}	
}

Vector::Vector(size_t n) : sz(n), max_sz(n), values(nullptr) {
	if(n > 0) {
		values = new double[n];
		for(size_t i = 0; i < n; i++) {
			values[i] = 0;
		}
	}
}

Vector::Vector(initializer_list<double> list) : sz(list.size()), max_sz(list.size()), values(nullptr) {
	if(sz > 0) {
		values = new double[sz];
		size_t i = 0; 
		for(double val : list) {
			values[i] = val;
			i++;
		}
	}
}

Vector::~Vector() {
	delete[] values;
}

Vector& operator=(const Vector& other);
size_t size() const;
bool empty() const;
void clear();
void reserve(size_t n);
void shrink_to_fit();
void push_back(double x);
void pop_back();
double& operator[](size_t index);
const double& operator[](size_t index) const;
size_t capacity() const;
ostream& operator<<(ostream& os, const Vector& v);

#endif
