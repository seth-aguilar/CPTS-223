#include "testQueue.h"

void testQueue::testSize()
{
    /*  Test ID: Queue Size Check - QSC
        Unit: queue::size()
        Description: test to determine if queue::size() returns correct size value
        Test steps:
        1. Construct a queue object
        2. Invoke queue::size()
        3. Enqueue 3 items to queue
        4. Conditionally evaluate the valued returned by queue::size()
        Test data: size = 3
        Precondition: queue object has size 3
        Postcondition: queue object is still size 3
        Expected result: queue has size 3; 3 is returned
        Actual result: queue has size 3; 3 is returned
        Status: passed
    */

    queue task;
    task.enqueue(1);
    task.enqueue(12);
    task.enqueue(7);
    //cout << "QUEUE SIZE CHECK: " << task.size() << endl;
    if (task.size() == 3)
    {
        cout << "QSC SUCCESS" << endl;
    }
}

void testQueue::testIsEmpty()
{
    /*  Test ID: Empty Queue Check - EQC
        Unit: queue::isEmpty()
        Description: test to determine if queue::isEmpty() returns 1 if a queue object is empty
        Test steps:
        1. Construct an empty queue object
        2. Invoke queue::isEmpty()
        3. Conditionally evaluate the valued returned by queue::isEmpty()
        Test data: size = 0
        Precondition: queue object is empty
        Postcondition: queue object is still empty
        Expected result: queue is empty; 1 is returned
        Actual result: queue is empty; 1 is returned
        Status: passed
    */

    queue task;
    //cout << "EMPTY QUEUE CHECK: " << task.isEmpty() << endl;
    if (task.isEmpty() == 1)
    {
        cout << "EQC SUCCESS" << endl;
    }

    /*  Test ID: Non-Empty Queue Check - NEQC
        Unit: queue::isEmpty()
        Description: test to determine if queue::isEmpty() returns 1 if a queue object is empty
        Test steps:
        1.    Construct a queue object with size 1
        2.    Invoke queue::isEmpty()
        3.    Conditionally evaluate the valued returned by queue::isEmpty()
        Test data: size = 1
        Precondition: queue object has size 0
        Postcondition: queue object is still size 1
        Expected result: queue has size 1; 0 is returned
        Actual result: queue has size 1; 0 is returned
        Status: passed
    */

    task.enqueue(3);
    //cout << "NON-EMPTY QUEUE CHECK: " << task.isEmpty() << endl;
    if (task.isEmpty() == 0)
    {
        cout << "NEQC SUCCESS" << endl;
    }
}

void testQueue::testIsFull()
{
    /*  Test ID: Full Queue Check - FQC
        Unit: queue::isFull()
        Description: test to determine if queue::isFull() returns correct bool value
        Test steps:
        1.    Construct a queue object with count = capacity
        2.    Invoke queue::isFull()
        3.    Conditionally evaluate the valued returned by queue::isFull()
        Test data: size = capacity
        Precondition: queue object has count = capacity
        Postcondition: queue object is still count = capacity
        Expected result: queue is full; 1 is returned
        Actual result: queue is full; 1 is returned
        Status: passed
    */

    queue task;
    task.count = SIZE;
    //cout << "FULL QUEUE CHECK: " << task.isFull() << endl;
    if (task.isFull() == 1)
    {
        cout << "FQC SUCCESS" << endl;
    }
}

void testQueue::testDequeue()
{
    /*  Test ID: Empty Dequeue Check - EDC
        Unit: queue::dequeue()
        Description: test to determine if queue::dequeue() returns correct bool value
        Test steps:
        1.    Construct a queue object with size = 0
        2.    Invoke queue::dequeue()
        3.    Conditionally evaluate the valued returned by queue::dequeue()
        Test data: size = 0
        Precondition: queue object has size = 0, enqueue() functions properly
        Postcondition: queue object is still size = 0
        Expected result: queue is empty; false (0) is returned
        Actual result: queue is empty; 0 is returned
        Status: passed
    */

    queue task;
    //cout << "EMPTY DEQUEUE CHECK: " << task.dequeue() << endl;
    if (task.dequeue() == false && task.size() == 0) // failed to dequeue
    {
        cout << "EDC SUCCESS" << endl;
    }

    /*  Test ID: Dequeue Check - DC
        Unit: queue::dequeue()
        Description: test to determine if queue::dequeue() returns correct bool value
                     and removes item from the queue
        Test steps:
        1.    Construct a queue object with size = 1
        2.    Invoke queue::dequeue()
        3.    Conditionally evaluate the valued returned by queue::dequeue()
        4.    Evaluate size of queue after calling dequeue()
        Test data: size = 1
        Precondition: queue object has size = 1 , enqueue() functions properly
        Postcondition: queue object is still size = 0
        Expected result: queue dequeues item and then is empty; true (1) is returned
        Actual result: queue dequeues item and then is empty; 1 is returned
        Status: passed
    */

    task.enqueue(2);
    //cout << "EMPTY DEQUEUE CHECK: " << task.dequeue() << endl;
    if (task.dequeue() == true && task.isEmpty() == true) // dequeued successfully
    {
        cout << "DC SUCCESS" << endl;
    }
}

void testQueue::testEnqueue()
{
    /*  Test ID : Empty queue check - EQC
        Unit : queue::isEmpty()
        Description : test to determine if queue::isEmpty() returns 1 if a
        queue object is empty
        Test steps :
        1. Construct an empty queue object
        2. Invoke queue::isEmpty()
        3. Conditionally evaluate the valued returned by
        queue::isEmpty()
        Test data : size = 0
        Precondition : queue object is empty
        Postcondition : queue object is still empty
        Expected result : queue is empty; 1 is returned
        Actual result : queue is empty; 1 is returned
        Status : passed
    */
    queue task;
    //cout << "EMPTY ENQUEUE CHECK: " << task.enqueue(2) << endl;
    if (task.enqueue(2) == true && task.size() == 1 && task.peek() == 2) // enqueued successfully
    {
        cout << "EEC SUCCESS" << endl;
    }

    /*  Test ID: Enqueue Check - EC
        Unit: queue::enqueue()
        Description: test to determine if queue::enqueue() returns correct bool value
                     and inserts value into queue
        Test steps:
        1.    Construct a queue object with size = 1
        2.    Invoke queue::enqueue(2), queue::enqueue(5)
        3.    Conditionally evaluate the value returned by queue::enqueue(5)
        4.    Conditionally evaluate the value inserted into
              queue by queue::enqueue(5)
        Test data: size = 0
        Precondition: queue object has size = 1
        Postcondition: queue object is size = 2, item 5 is inserted to queue
        Expected result: queue is size = 2, item 5 inserted; true (1) is returned and task.arr[1] = 5
        Actual result: queue is size = 2, item 5 inserted; true (1) is returned and task.arr[1] = 5
        Status: passed
    */

    //cout << "ENQUEUE CHECK: " << task.enqueue(2) << endl;
    if (task.enqueue(5) == true && task.size() == 2 && task.arr[1] == 5) // enqueued successfully
    {
        cout << "EC SUCCESS" << endl;
    }

}

void testQueue::testPeek()
{
    /*  Test ID: Empty Peek Check - EPC
        Unit: queue::peek()
        Description: test to determine if queue::peek() returns correct int value
        Test steps:
        1.    Construct a queue object with size = 0
        2.    Invoke queue::peek()
        3.    Conditionally evaluate the value returned by queue::peek()
        Test data: size = 0
        Precondition: queue object has size = 0
        Postcondition: queue object is still size = 0
        Expected result: queue is size = 0; false (0) is returned
        Actual result: queue is size = 0; false (0) is returned
        Status: passed
    */

    queue task;
    //cout << "EMPTY PEEK CHECK: " << task.peek() << endl;
    if (task.peek() == numeric_limits<int>::min()) // empty queue, peek unsuccessful
    {
        cout << "EPC SUCCESS" << endl;
    }

    /*  Test ID: Non-empty Peek Check - NEPC
        Unit: queue::peek()
        Description: test to determine if queue::peek() returns correct int value
        Test steps:
        1.    Construct a queue object with size = 1
        2.    Invoke queue::peek()
        3.    Conditionally evaluate the value returned by queue::peek()
        Test data: size = 0
        Precondition: queue object has size = 1
        Postcondition: queue object is still size = 1
        Expected result: queue is size = 1; proper int is returned
        Actual result: queue is size = 0; proper int is returned
        Status: passed
    */

    task.enqueue(2);
    cout << "EMPTY PEEK CHECK: " << task.peek() << endl;
    if (task.peek() == 2) // queue, peek successful
    {
        cout << "NEPC SUCCESS" << endl;
    }
}