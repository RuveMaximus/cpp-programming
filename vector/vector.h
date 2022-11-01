#ifndef VECTOR_H
#define VECTOR_H

#include <ostream>
using namespace std;
const int DEFAULT_CAPACITY = 5;

class VectorException {};

class Vector
{
private:
	int *ptr;
	int size, capacity; 

public:
	explicit Vector(int startCapacity=DEFAULT_CAPACITY);

	Vector(const Vector& v);
	~Vector();

	int getSize();
	int getCapacity();

	void insert(int elem, int index); 
	void push_back(const int elem);
	void remove(const int index);
	void increaseCapacity(const int newCapacity); 

	int& operator[] (int index);
	Vector& operator = (const Vector& v);

	friend ostream& operator << (ostream& out, const Vector& v); 
};

#endif 
