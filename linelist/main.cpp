#include <iostream> 
#include "linelist.hpp"

using namespace std;

int main(void)
{
    LineList<int> list;
    cout << "Begging " << list << endl;
    list.insertFirst(10);
    LineListElem<int> *ptr = list.getStart();
    list.insertAfter(ptr, 15);
    list.insertAfter(ptr->getNext(), 12);
    list.insertFirst(7);
    cout << "step 1 " << list << endl;
    return 0;   
}