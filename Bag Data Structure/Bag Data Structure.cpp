#include <iostream>
#include <stdlib.h>
#include <time.h>
#define CAPACITY 10
using namespace std;

class Bag{
public:
    Bag();
    void insert(double);
    void printVal();
    bool isEmpty();
    bool isFull();
    int getSize();
protected:
    int _size;
    double _data[CAPACITY];
};//bag class
class Set:public Bag{//derived class for set.
public:
  void insert(double);
};


int main()
{
    Set m;
    m.insert(1);
    m.insert(2);
    m.insert(2);
    cout<<"Set: "<<endl;
    m.printVal();
    return 0;

}

Bag::Bag()
{
    _size = 0;
}

void Bag::insert(double n)
{
    if(!isFull())
    {
        _data[_size] = n;
        _size++;
    }
}
//function to insert for bag.

void Set::insert(double s)
{
    bool copy = false;
    if(!isFull())
    {
        for(int j = 0; j<_size; j++)
        {
            if(_data[j]==s)
            {
                copy = true;
            }
        }
        if(copy==false)
        {
            _data[_size] = s;
            _size++;
        }
    }
}
//function for insert set that does not allow duplicates.

void Bag::printVal()
{
    if(!isEmpty())
    {
        for(int i = 0;i<_size;i++)
            cout<<_data[i]<<endl;
    }
}
//prints the values in the class.

bool Bag::isEmpty()
{
    bool statE = false;
    if(_size == 0)
    {
        statE = true;
    }
    return statE;
}
//checks if the class is empty.
bool Bag::isFull()
{
    bool statF = false;
    if(_size == CAPACITY)
    {
        statF = true;
    }
    return statF;
}
//checks if the class is filled to capacity.
int Bag::getSize()
{
    return _size;
}
//returns size.

