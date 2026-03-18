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

Vector::Vector(size_t n) : sz(0), max_sz(n), values(nullptr) {
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

Vector& Vector::operator=(const Vector& other) {
	if(this == &other) {
		return *this;
	}
	delete[] values;
	sz = other.sz;
	max_sz = other.max_sz;
	if(max_sz > 0) {
		values = new double[max_sz];
		for(size_t i = 0; i < sz; i++) {
			values[i] = other.values[i];
		}
	}
}

size_t Vector::size() const {
	return sz;
}

bool Vector::empty() const {
	if(sz > 0) {
		return false;
	} else return true;
}

void Vector::clear() {
	sz = 0;
}

void Vector::reserve(size_t n) {
	if(max_sz < n) {
		double* new_values = new double[n];
		for(size_t i = 0; i < sz; i++) {
			new_values[i] = values[i];
		}
		delete values[];
		values = new_values;
		max_sz = n;
	}
}

void Vector::shrink_to_fit() {
	if(max_sz > sz) {
		double* new_values = new double[sz];
		for(size_t i = 0; i < sz; i++) {
			new_values[i] = values[i];
		}
		delete[] values;
		values = new_values;
		max_sz = sz;
	}
}

void Vector::push_back(double x) {
	if(max_sz == sz) {
		if(max_sz == 0) {
			reserve(1);
		} 
		reserve(max_sz * 2);
	}
	values[sz] = x;
	sz++;
}

void Vector::pop_back() {
	if(sz == 0) throw runtime_error("Vector ist leer");
	sz--;
}

double& Vector::operator[](size_t index) {
	if(index > sz) throw runtime_error("Index ist nicht im erlaubten Bereich");
	return values[index];
}

const double& Vector::operator[](size_t index) const {
	if(index > sz) throw runtime_error("Index ist nicht im erlaubten Bereich");
	return values[index];
}

size_t Vector::capacity() const {
	return max_sz;
}

ostream& operator<<(ostream& os, const Vector& v) {
	os << "[";
	for(size_t i = 0; i < v.sz; i++) {
		os << v[i];
		if(i < sz - 1) os << ", ";
	}
	os << "]";
	return os;
}

#endif
