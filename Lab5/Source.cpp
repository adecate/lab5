#include <iostream>
#include "queue.h"
#include "int_queue.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Ru");

	cout << "Template queue:" << endl << endl;

	Queue<int> z(5);

	z.Pop(); // Очередь пуста!

	z.Push(1);
	z.Push(2);
	z.Push(5);
	z.Push(6);
	z.Push(9);

	cout << z;

	z.Pop();
	cout << z;
	cout << "Number of items in the queue: " << z.GetSize() << endl;

	z.Push(7);
	cout << z;
	cout << "Number of items in the queue: " << z.GetSize() << endl;

	cout << "First item in the queue: " << z.Peek() << endl;

	z.Push(3); // Очередь заполнена!


	cout << endl << "Integer queue:" << endl << endl;

	Queue_int v(5);

	v.Pop(); // Очередь пуста!

	v.Push(1);
	v.Push(2);
	v.Push(5);
	v.Push(6);
	v.Push(9);

	cout << v;

	v.Pop();
	cout << v;
	cout << "Number of items in the queue: " << v.GetSize() << endl;

	v.Push(7);
	cout << v;
	cout << "Number of items in the queue: " << v.GetSize() << endl;

	cout << "First item in the queue: " << v.Peek() << endl;

	v.Push(3); // Очередь заполнена!

	return 0;
}
