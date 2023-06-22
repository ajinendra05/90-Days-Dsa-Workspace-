#include <bits/stdc++.h>
using namespace std;

// DrawBack as we can't manage size efficiently [we can throw overflow error while space is present in queue]
class customQueue
{
    int front;
    int rear;
    int size;
    int *arr;

public:
    customQueue(int size = 10)
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }
    void enQueue(int x)
    {
        if (rear == size)
        {
            throw invalid_argument(" STACK OVERFLOW");
        }
        else
        {
            arr[rear++] = x;
        }
    }
    void deQueue()
    {
        if (front == rear)
        {
            throw invalid_argument(" STACK UNDERFLOW");
        }
        else
        {
            arr[front] = -1;
            front++;
        }

        if (front == rear)
        {
            front = rear = 0;
        }
    }
    int getFront()
    {
        if (front == rear)
        {
            throw invalid_argument(" STACK UNDEFLOW");
        }
        else
        {
            return arr[front];
        }
    }
    bool isEmpty()
    {
        if (front == rear)
            return true;
        return false;
    }
};

// it utilize space perfectly but also have o(n) for pop an element;
class customQueue2
{
    // int front;
    int rear;
    int size;
    int *arr;

public:
    customQueue2(int size = 10)
    {
        this->size = size;
        arr = new int[size];
        rear = 0;
    }
    void enQueue(int x)
    {
        if (rear == size)
        {
            throw invalid_argument(" STACK OVERFLOW");
        }
        else
        {
            arr[rear++] = x;
        }
    }
    void deQueue()
    {
        if (rear == 0)
        {
            throw invalid_argument(" STACK UNDERFLOW");
        }
        else
        {
            for (int i = 1; i < rear; i++)
            {
                arr[i - 1] = arr[i];
            }
            rear--;
        }
    }
    int getFront()
    {
        if (rear == 0)
        {
            throw invalid_argument(" STACK UNDEFLOW");
        }
        else
        {
            return arr[0];
        }
    }
    bool isEmpty()
    {
        if (rear == 0)
            return true;
        return false;
    }
};

class customCircularQueue
{
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
    bool isFull()
    {
        if (front == 0 && rear == capacity - 1)
            return true;
        if ((front % capacity) == (rear % capacity) + 1)
            return true;
        return false;
    }

public:
    customCircularQueue(int size = 10)
    {
        this->capacity = size;
        arr = new int(size);
        front = rear = 0;
        this->size = 0;
    }

    void enQueue(int x)
    {
        if (size == capacity)
        { // for dynamic size grow
            // grow();
            // arr[rear++] = x;
            // rear %= capacity;
            // size++;
            throw invalid_argument(" STACK OVERFLOW");
        }
        else
        {

            arr[rear++] = x;
            rear %= capacity;
            size++;
        }
    }
    void deQueue()
    {
        if (size == 0)
        {
            throw invalid_argument(" STACK UNDERFLOW");
        }
        else
        {
            front++;
            front = front % capacity;
            size--;
        }
    }
    int getFront()
    {
        if (size == 0)
        {
            throw invalid_argument(" STACK UNDERFLOW");
        }
        else
        {
            return arr[front];
        }
    }
    bool isEmpty()
    {
        if (size == 0)
            return true;
        return false;
    }
    // for dyanamic call this function
    void grow()
    {

        int *temp = new int[capacity * 2];
        int ind;
        for (int i = 0; i < capacity; i++)
        {
            ind = (front + i) % capacity;
            temp[i] = arr[ind];
        }
        delete (arr);
        arr = temp;
        front = 0;
        rear = capacity;
        capacity = capacity * 2;
    }
};

class doublyEndedQueue
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    doublyEndedQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        rear = -1;
        front = -1;
    }
    void pushFront(int x)
    {
        if (isfull())
        {
            throw invalid_argument(" STACK OVERFLOW");
        }
        if (front == -1)
        {
            front = rear = 0;
        }
        else if (front == 0)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = x;
    }
    void pushBack(int x)
    {
        if (isfull())
        {
            throw invalid_argument(" STACK OVERFLOW");
        }
        if (rear == -1)
        {
            front = rear = 0;
        }
        else if (rear == size - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = x;
    }
    void popBack()
    {
        if (isempty())
        {
            throw invalid_argument(" STACK UNDERFLOW");
        }
        arr[rear] = -1;
        if (rear == front)
        {

            front = rear = -1;
        }
        else if (rear == 0)
        {

            rear = size - 1;
        }
        else
        {

            rear--;
        }
    }
    void popFront()
    {
        if (isempty())
        {
            throw invalid_argument(" STACK UNDERFLOW");
        }
        arr[front] = -1;
        if (rear == front)
        {

            front = rear = -1;
        }
        else if (front == size - 1)
        {

            front = 0;
        }
        else
        {

            front++;
        }
    }
    bool isfull()
    {
        if (front == 0 && rear == size - 1)
            return true;
        if ((front % size) == (rear % size) + 1)
            return true;
        return false;
    }
    bool isempty()
    {
        return front=-1;
    }
    int getfront()
    {
        if (isempty())
        {
            throw invalid_argument(" STACK UNDERFLOW");
        }
        return arr[front];
    }
    int getBack()
    {
        if (isempty())
        {
            throw invalid_argument(" STACK UNDERFLOW");
        }
        return arr[rear];
    }
};

int main()
{

    // queue<int> x;
    // x.push(20);
    // x.push(12);
    // x.push(14);
    // x.pop();
    // cout << x.size();
    // cout << x.back();
    // cout << x.front();

    // customCircularQueue c(5);
    // c.enQueue(50);
    // c.enQueue(1);
    // c.enQueue(12);
    // c.enQueue(24);
    // c.enQueue(45);
    // // c.grow();
    // c.enQueue(60);
    // c.enQueue(660);
    // cout << c.getFront() << endl;
    // c.deQueue();
    // cout << c.getFront() << endl;
    // c.deQueue();
    // c.deQueue();
    // cout << c.getFront() << endl;

    // cout << c.getFront();
    // c.isEmpty() ? cout << "no" : cout << "yes";
    // c.deQueue();
    // c.enQueue(120);
    // c.enQueue(103);
    // cout << c.getFront() << endl;
    // c.deQueue();
    // cout << c.getFront() << endl;

    doublyEndedQueue d(5);
    d.pushFront(15);
    d.pushBack(20);
    d.pushFront(45);
    d.pushFront(4);
    d.pushBack(9);
    

    cout<<d.getfront()<<endl;
    cout<<d.getBack()<<endl;
    deque<int> de;

    de.push_front(15);
    de.push_back(20);
    de.push_front(45);
    de.push_front(4);
    de.push_back(9);
    cout << de.front() << endl;
    cout << de.back() << endl;

    return 0;
}