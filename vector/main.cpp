#include <iostream> 
#include <ctime>
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
    unsigned int start_time = clock();
    
    Vector v(n);
    for (int i = 0; i < n; ++i) v.push_back(i+1);
    for (int i = 0; v.getSize() > 1; i += k - 1, i %= v.getSize(), v.remove(i));
    cout << "Answer: " << v[0] << endl;
    
    unsigned int end_time = clock();
    cout << "Working time: " << (end_time - start_time)/1000.0 << "s" << endl;

    return 0;
}
