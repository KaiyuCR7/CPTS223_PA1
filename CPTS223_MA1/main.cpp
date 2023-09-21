#include "testQueue.h"

// main function
int main()
{
	// call your test functions here!
	testQueue* tQueue = new testQueue();

	cout << "testing isEmpty" << endl;
	tQueue->testIsEmpty();

	getchar();
	system("cls");


	cout << "testing isFull" << endl;
	tQueue->testIsFull();

	getchar();
	system("cls");


	cout << "testing size" << endl;
	tQueue->testsize();

	getchar();
	system("cls");


	cout << "testing dequeue" << endl;
	tQueue->testdequeue();

	getchar();
	system("cls");

	cout << "testing enqueue" << endl;
	tQueue->testenqueue();

	getchar();
	system("cls");

	cout << "testing peek" << endl;
	tQueue->testpeek();

	getchar();
	system("cls");

	return 0;
}