#include <iostream> 
#include "vector.h"

using namespace std;

int main() 
{
	Vector v(4);
    for (int i = 0; i < 4; i++) v.insert(i+1); 
    cout << v << endl;
    for (int i = 0; i < 8; i++) v.insert(10+i, i); 
    cout << v << endl;
    for (int i = 1; i < 8; i+=2) v[i] = 20+i;
    cout << v << endl;
    for (int i = 6; i >= 0; i-=3) v.remove(i);
    cout << v << endl;
}
