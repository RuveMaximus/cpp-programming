#include <iostream> 
#include "vector.h"

using namespace std;


void input(int& value, const char* introduce)
{
    cout << introduce; cin >> value;
}


int main() 
{
    int n, k; 
    input(n, "Enter the number of persons: ");
    input(k, "Enter the interval: ");

    Vector v(n);
    for (int i = 0; i < n; ++i) v.push_back(i+1);
    for (int i = 0; v.getSize() > 1; i += k - 1, i %= v.getSize(), v.remove(i));
    cout << "Answer: " << v[0] << endl;
}
