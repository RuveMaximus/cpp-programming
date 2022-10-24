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

	void indexIsValid();

	void insert(int elem, int index); 
	void insert(int elem);
	void remove(int index);
	void increaseCapacity(int newCapacity); 

	int& operator[] (int index);
	Vector& operator = (const Vector& v);

	friend ostream& operator << (ostream& out, const Vector& v); 
};

#endif 
