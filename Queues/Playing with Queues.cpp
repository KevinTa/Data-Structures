#include <iostream>
#include <assert.h>

using namespace std;
template<class Object>
class Queue;
template<class Object>
ostream& operator<<(ostream&, Queue<Object>&);
template<class Object>
class Queue{
private:
    Object* data;
    int count;
    int front;
    int back;
    int CAPACITY;
public:
    Queue(int n);
    ~Queue();
    void resetQueue();
    Queue& operator = (const Queue<Object>&);
    Queue(const Queue<Object>&);
    void enque(Object);
    void deque();
    void reverse();
    int next_i(int i);
    void inc_cap();
    Object getFront();
    bool isEmpty();
    friend ostream& operator<< <>(ostream& , Queue<Object>&);
};

int main()
{
    Queue<int> x(3);
    x.enque(12);
    x.enque(48);
    x.enque(72);
    cout<<"x: "<<x<<endl;
    x.reverse();
    cout<<"x: "<<x<<endl;
    return 0;
}

template<class Object>
Queue<Object>::Queue(int n)
{
    data = new int[n];
    count = 0;
    front = 0;
    back = -1;
    CAPACITY = n;
}
//constructor
template<class Object>
Queue<Object>::~Queue()
{
    if(data!=NULL)
    {
        delete[] data;
    }
}
//destructor
template<class Object>
void Queue<Object>::resetQueue()
{
    count = 0;
    front = 0;
    back = -1;
}
//function to reset queue to beginning state

template<class Object>
Queue<Object>& Queue<Object>::operator = (const Queue<Object> &q)
{
    if(this == &q)
    {
        return *this;
    }
    if(data!=NULL)
    {
        delete [] data;
    }
    data = new int[q.CAPACITY];
    count = q.count;
    front = q.front;
    back = q.back;
    CAPACITY = q.CAPACITY;
    if(count == 0)
    {
        return *this;
    }
    for(int i = front; i!=back; i = next_i(i))
    {
        data[i] = q.data[i];
    }
    data[back]= q.data[back];
    return *this;
}
//assignment operator for queue
template <class Object>
int Queue<Object>::next_i(int i)
{
    return(i+1)%CAPACITY;
}
//returns next iteration position of queue
template <class Object>
Queue<Object>::Queue(const Queue<Object> &q)
{
    *this = q;
}
//copy constructor of queue
template <class Object>
void Queue<Object>::enque(Object n)
{
    if(count == CAPACITY)
    {
        inc_cap();
    }
    back = next_i(back);
    data[back] = n;
}
//Adds value to queue
template<class Object>
void Queue<Object>::inc_cap()
{
    int j = 0;
    int *tmp = new int[CAPACITY * 2];
    for(int i = front; i!=back;i=next_i(i))
    {
        tmp[j]=data[i];
        j++;
    }
    tmp[j] = data[back];
    delete[] data;
    data = tmp;
    front = 0;
    back = j;
    CAPACITY *=2;
}
//increases queue's capacity
template <class Object>
void Queue<Object>::deque()
{
    if(count == 0)
    {
        return;
    }
    front = next_i(front);
    count--;
}
//removes value from queue
template <class Object>
Object Queue<Object>::getFront()
{
    assert(count!=0);
    return data[front];
}
//returns value of front of queue
template <class Object>
bool Queue<Object>::isEmpty()
{
    bool v = false;
    if(count == 0)
    {
        v = true;
    }
        return v;
}
//checks if queue is empty
template <class Object>
ostream& operator<<(ostream& out, Queue<Object>& rhs)
{
    for(int i = rhs.front; i!=rhs.back; i = (i+1)% rhs.CAPACITY)
    {
        out<<rhs.data[i]<<",  ";
    }
    out<<rhs.data[rhs.back]<<endl;
    return out;
}
//output operator for queue.
template <class Object>
void Queue<Object>::reverse()
{
    int tcap = CAPACITY;
    Object tmp[tcap];
    for(int i = front; i!= back; i = (i+1) % CAPACITY)
    {
        tmp[i]=data[i];
        deque();
    }
    tmp[tcap-1]=data[back];
    resetQueue();
    for(int i = tcap-1; i>=0; i--)
    {
        enque(tmp[i]);
    }

}
//reverses order of queue by copying the queue into a temporary array while dequeuing the queue each time, then resetting the queue and enqueuing each element of the array into the queue in revere order.
