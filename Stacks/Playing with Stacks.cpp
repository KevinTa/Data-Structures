#include <iostream>
#include <cstdlib>
#include <string>
#include <string.h>

using namespace std;

class Stack{
private:
    double *_data;
    int _top;
    int _max;
    int _count;
    double _median;
public:
    Stack(int max);
    ~Stack();
    void push(double n);
    double pop();
    double top();
    void showStack();
    Stack(const Stack &);
    Stack & operator= (const Stack &);
    void resetStack();
    void selectionsort();
    double getMedian();

};

int main()
{
    Stack s(3);
    s.push(9);
    s.push(2);
    s.push(6);
    s.showStack();
    cout<<s.getMedian()<<endl;

}
//main to test the functions.
Stack::Stack(int max)
{
    _max = max;
    _data = new double[max];
    _top = -1;
    _count = 0;
    _median = 0;
}
//initializes _top, _max, _count, and _data.

Stack::~Stack()
{
    if(_top!=-1)
    {
        delete [] _data;
    }
}

Stack::Stack(const Stack& rhs)
{
    *this = rhs;
}
//copy constructor

Stack & Stack::operator= (const Stack & rhs)
{
    _top=rhs._top;
    while(_count != rhs._count)
    {
        _data[_count]=rhs._data[_count];
        _count++;
    }
    return *this;
}
//operator to return *this.

void Stack::resetStack(){
    _top = -1;
    _count = 0;
}
//function to return stack to initial state to enter in more inputs.

void Stack::push(double n)
{
    if(_count<_max)
    {
        _top = _top + 1;
        _data[_top] = n;
        _count++;
    }
}
//inserts a new double into the current _top position in the data array then increments the _top value and _count forward.

double Stack::pop()
{
    double tmp;
    if(_count>=0)
    {
        tmp = _data[_top];
       _top = _top - 1;
       _count--;
    }
    return tmp;

}
//In the case that Stack is not empty,removes value at the top of Stack, then deincrements _top.

void Stack::showStack()
{
    if(_top>=0)
    {
        for(int i = 0; i<=_top; i++)
        {
            cout <<"Stack: "<< _data[i]<<endl;
        }
    }
}

//displays all values in Stack.

double Stack::top()
{
    return _data[_top];
}

void Stack::selectionsort()
{
    int min;
    double tmp;
    for (int i = 0; i < _count-1; i++)
    {
        min = i;
        for (int j = i+1; j < _count; j++)
        {
          if (_data[j] < _data[min])
          min = j;
        }
        tmp = _data[i];
        _data[i] = _data[min];
        _data[min]=tmp;
    }
}
//selectionsort algorithm to order the data values from least to greatest.
double Stack::getMedian()
{
    if(_count!=0)
    {
        selectionsort();
        if(_count%2==0)
        {
            _median = _data[_count/2] + _data[(_count/2)+1];
        }
        else
        {
            _median = _data[_count/2];
        }
        return _median;
    }
}
//calls selectionsort to sort the values, then determines the median value then returns it.



