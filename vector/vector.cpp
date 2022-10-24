#include "vector.h"


Vector::Vector(int startCapacity)
{
    capacity = startCapacity >= 0 ? startCapacity : DEFAULT_CAPACITY;
    ptr = new int[capacity]; 
    size = 0; 
}

Vector::Vector(const Vector& v) 
{
    ptr = new int[v.capacity]; 
    size = v.size;
    capacity = v.capacity; 
    for (int i = 0; i < size; i++)
    {
        ptr[i] = v.ptr[i];
    }
}

void Vector::insert(int elem, int index)
{
    if (index < 0 || index > size) throw VectorException(); 
    if (size == capacity) increaseCapacity(size+1);
    for (int i = size-1; i >= index; j--)
    {
        ptr[j+1] = ptr[j];
    }
    size++;
    ptr[index] = elem;
}

void Vector::remove(int index)
{
    if (index < 0 || index >= size) throw VectorException();
    for (int i = index; i < size-1; i++) 
        ptr[i] = ptr[i+1];
    ptr[size-1] = 0; 
    size--;
    
}

void Vector::increaseCapacity(int newCapacity) {
    capacity = newCapacity < capacity*2 ? capacity*2 : newCapacity; 
    int *newPtr = new int[capacity]; 
    for (int i = 0; i < size; i++) 
    {
        newPtr[i] = ptr[i];
    }
    delete[] ptr; 
    ptr = newPtr;
}

Vector& Vector::operator = (const Vector& v)
{
    if (this == &v) return *this;
    if (capacity != v.capacity)
    {
        delete[] ptr; 
        ptr = new int[v.capacity];
        capacity = v.capacity; 
    }
    size = v.size;
    for (int i=0; i < size; i++) 
    {
        ptr[i] = v.ptr[i];
    }
    return *this;
}

int Vector::operator [](int index)
{
    if (index >= size || index < 0)
        throw VectorException(); 
    else
        return ptr[index]; 
}

Vector::~Vector()
{
    delete[] ptr; 
}