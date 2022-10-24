#ifndef VECTOR_H
#define VECTOR_H

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

	void indexIsValid();

	void insert(int elem, int index); 
	void remove(int index);
	void increaseCapacity(int newCapacity); 

	int operator[] (int index);
	Vector& operator = (const Vector& v);
	~Vector();
};

#endif 
