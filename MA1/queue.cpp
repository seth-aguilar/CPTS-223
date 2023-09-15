#include "queue.h"

// Constructor to initialize queue
queue::queue(int size)
{
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

// Destructor to free memory allocated to the queue
queue::~queue()
{
    delete[] arr; // you are not required to test this function;
    // however, are there issues with it?
}

// Utility function to remove front element from the queue
bool queue::dequeue()
{
    // check for queue underflow
    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
        return false;
    }

    cout << "Removing " << arr[front] << '\n';

    front = (front + 1) % capacity;
    count--;
    return true;
}

// Utility function to add an item to the queue
bool queue::enqueue(int x)
{
    // check for queue overflow
    if (isFull())
    {
        cout << "OverFlow\nProgram Terminated\n";
        return false;
    }

    cout << "Inserting " << x << '\n';

    rear = (rear + 1) % capacity;
    arr[rear] = x;
    count++;
    return true;
}

// Utility function to return front element in the queue
int queue::peek()
{
    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
        return numeric_limits<int>::min();
    }
    return arr[front];
}

// Utility function to return the size of the queue
int queue::size()
{
    return count;
}

// Utility function to check if the queue is empty or not
bool queue::isEmpty()
{
    return (size() == 0);
}

// Utility function to check if the queue is full or not
bool queue::isFull()
{
    return (size() == capacity);
}
