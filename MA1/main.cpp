#include "queue.h"
#include "testQueue.h"

/* Attributes

* Namespace std

* Redundant Comments

* #define size 10 could be defined as a const

* in enqueue and dequeue error handling was inefficient

* inside of enqueue the size is inserted into the queue instead of the item passed into the function

*/


// main function
int main()
{
    testQueue test;

    test.testSize();
    test.testIsEmpty();
    test.testIsFull();
    test.testDequeue();
    test.testEnqueue();
    test.testPeek();

    return 0;
}

