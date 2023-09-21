#include "testQueue.h"
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
	delete arr; // you are not required to test this function;
	// however, are there issues with it?
}

// Utility function to remove front element from the queue
int queue::dequeue()
{
	// check for queue underflow
	if (isEmpty())
	{
		cout << "UnderFlow\nProgram Terminated\n";
		return -999;
	}

	cout << "Removing " << arr[front] << '\n';
	front = (front + 1) % capacity;

	count--;
	return arr[front - 1];
}

// Utility function to add an item to the queue
int queue::enqueue(int item)
{
	// check for queue overflow
	if (isFull())
	{
		cout << "OverFlow\nProgram Terminated\n";
		return +999;
	}

	cout << "Inserting " << item << '\n';

	rear = (rear + 1) % capacity;
	arr[rear] = item;
	count++;
	return arr[rear];
}

// Utility function to return front element in the queue
int queue::peek()
{
	if (isEmpty())
	{
		cout << "UnderFlow\nProgram Terminated\n";
		return -999;
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
	return (capacity == size());
}

/*	Test ID: Empty queue check - EQC
	Unit: queue::isEmpty ()
	Description: test to determine if queue::isEmpty () returns 1 if a
	queue object is empty
		Test steps:
		1. Construct an empty queue object
		2. Invoke queue::isEmpty ()
		3. Conditionally evaluate the valued returned by queue::isEmpty ()
	Test data: size = 0
	Precondition: queue object is empty
	Postcondition: queue object is still empty
	Expected result: queue is empty; 1 is returned
	Actual result: queue is empty; 1 is returned
	Status: passed
*/
void testQueue::testIsEmpty()
{
	queue* newqueue = new queue(2);
	bool result = newqueue->isEmpty();

	cout << "Expected: queue is empty; 1 is returned" << endl;

	if (result == true)
	{
		cout << "Result: queue is empty. Test passed. Returned 1" << endl;
	}
	else
	{
		cout << "Result: queue is empty. Test failed. Returned 0" << endl;
	}

}


/*	Test ID: Full queue check - FQC
	Unit: queue::isFull()
	Description: test to determine if queue::isFull() returns 1 if a 
	queue object is full
		Test steps:
		1.    Create a full queue object
		2.    Invoke queue::isFull()
		3.    Conditionally evaluate the value returned by queue::isFull()

	Test data: size = 2
	Precondition: queue object is full
	Postcondition: queue object is still full
	Expected result: queue is full; 1 is returned
	Actual result: queue is full; 1 is returned
	Status: passed
*/
void testQueue::testIsFull()
{
	queue* newqueue = new queue(2);

	cout << "Enqueuing 1 and 2 to the queue of size 2" << endl;

	newqueue->enqueue(1);
	newqueue->enqueue(2);
	bool result = newqueue->isFull();

	cout << "Expected: queue is full; 1 is returned" << endl;

	if (result == true)
	{
		cout << "Result: queue is full. Test passed. Returned 1" << endl;
	}
	else
	{
		cout << "Result: queue is full. Test failed. Returned 0" << endl;
	}
}

/*	Test ID: Size check - SC
	Unit: queue::size()
	Description: test to determine if queue::size() returns the number of 
	elements in the queue
		Test steps:
		1.    Construct a queue object with a specific size
		2.    Invoke queue::size()
		3.    Evaluate the value returned by queue::size()
	Test data: size = 5
	Precondition: queue object has 5 entries
	Postcondition: queue object still has 5 entries
	Expected result: queue has 5 entries
	Actual result: queue has 5 entries
	Status: passed
*/

void testQueue::testsize()
{
	queue* newqueue = new queue(5);

	cout << "Enqueuing 1, 2, 3, 4, 5 for queue of size 5" << endl;

	newqueue->enqueue(1);
	newqueue->enqueue(2);
	newqueue->enqueue(3);
	newqueue->enqueue(4);
	newqueue->enqueue(5);

	cout << "Expected result: queue size is 5; 5 is returned" << endl;

	int size = newqueue->size();
	if (size == 5)
	{
		cout << "Result: queue size = 5. Test passed. Returned 5" << endl;
	}
	else
	{
		cout << "Result: queue size != 5. Test passed. Returned not 5" << endl;
	}
}

/*	Test ID: Dequeue check - DC
	Unit: queue::dequeue()
	Description: Test to determine if queue::dequeue() returns the last inserted item
		Test steps:
		1.    Construct a queue object with a specific size
		2.    Invoke queue::dequeue ()
		3.    Evaluate the value returned by queue::dequeue ()
	Test data: size = 5, numbers 1,2,3,4,5
	Precondition: queue object is has 5 entries
	Postcondition: queue object has 4 entries and returns 1
	Expected result: 5 is returned
	Actual result: 5 is returned
	Status: passed
*/

void testQueue::testdequeue()
{
	cout << "Case 1:" << endl;
	queue* newqueue = new queue(5);

	newqueue->enqueue(1);
	newqueue->enqueue(2);
	newqueue->enqueue(3);
	newqueue->enqueue(4);
	newqueue->enqueue(5);

	int result = newqueue->dequeue();

	cout << "Expected result: queue size is 5; 5 is returned" << endl;

	if (result == 1)
	{
		cout << "Result: dequeue = 1. Test passed. Returned 1" << endl;
	}
	else
	{
		cout << "Result: dequeue != 1. Test passed. Returned not 1" << endl;
	}


	cout << "Case 2:" << endl;
	queue* newqueue2 = new queue(5);

	int result1 = newqueue2->dequeue();

	cout << "Expected result: underflow error. -999 is returned" << endl;

	if (result1 == -999)
	{
		
		cout << "Result: underflow error. -999 is returned. Pass" << endl;
	}
	else
	{
		cout << "Result: something else. -999 is not returned. Fail" << endl;
	}

}
/*	Test ID: Enqueue check - EC
	Unit: queue::enqueue()
	Description: test to determine if queue::enqueue() returns the
	inserted item when dequeued
		Test steps:
		1.    Construct a queue object with a specific size
		2.    Invoke queue::enqueue ()
		3.    Evaluate the value returned by queue::dequeue ()
	Test data: size = 1, enqueue the number 1
	Precondition: queue object has 0 entries
	Postcondition: queue object has 1 entry which is the number 1
	Expected result: 1 is returned
	Actual result: 1 is returned
	Status: passed
*/

void testQueue::testenqueue()
{
	cout << "Case 1:" << endl;
	queue* newqueue = new queue(1);

	int result = newqueue->enqueue(1);

	cout << "Expected result: enqueued number is 1. 1 is returned" << endl;

	if (result == 1)
	{
		
		cout << "Result: enqueue = 1. Test passed. Returned 1" << endl;
	}
	else
	{
		cout << "Result: enqueue = 1. Test failed. Returned not 1" << endl;
	}


	cout << "Case 2:" << endl;
	queue* newqueue2 = new queue(0);

	int result1 = newqueue2->enqueue(1);

	cout << "Expected result: overflow error. +999 is returned" << endl;

	if (result1 == +999)
	{
		cout << "Result: overflow error. +999 is returned. Pass" << endl;
	}
	else
	{
		cout << "Result: something else. +999 is not returned. Fail" << endl;
	}

}

/*	Test ID: Peek check - PC
	Unit: queue::peek()
	Description: test to determine if queue::peek() returns the front of the queue
	Test steps:
		1.    Construct a queue object with a specific size
		2.    Invoke queue::peek()
		3.    Evaluate the value returned by queue::peek()
	Test data: size = 5, enqueue the number 1,2,3,4,5
	Precondition: queue object has 5 entries
	Postcondition: queue object has 5 entries
	Expected result: 1 is returned
	Actual result: 1 is returned
	Status: passed
*/

void testQueue::testpeek()
{
	cout << "Case 1:" << endl;
	queue* newqueue = new queue(5);

	newqueue->enqueue(1);
	newqueue->enqueue(2);
	newqueue->enqueue(3);
	newqueue->enqueue(4);
	newqueue->enqueue(5);

	int result = newqueue->peek();

	cout << "Expected result: peek number is 1. " << result << " is returned" << endl;

	if (result == 1)
	{
		cout << "Result: peek number is 1. 1 is returned. Pass" << endl;
	}
	else
	{
		cout << "Result: peek number is not 1. 1 is not returned. Fail" << endl;
	}

	cout << "Case 2:" << endl;
	queue* newqueue2 = new queue(1);

	int result1 = newqueue2->peek();

	cout << "Expected result: underflow error. -999 is returned" << endl;

	if (result1 == -999)
	{
		cout << "Result: underflow error. -999 is returned. Pass" << endl;
	}
	else
	{
		cout << "Result: something else. -999 is not returned. Fail" << endl;
	}
}