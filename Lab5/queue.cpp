#include "int_queue.h"


Queue_int::Queue_int(int size) : size(size), head(0), tail(0), count(0)
{
	arr = new int[size];
}


Queue_int::~Queue_int()
{
	delete[] arr;
}


Queue_int::Queue_int(const Queue_int& other)
{
	size = other.size;

	arr = new int[other.size];

	head = other.head;
	tail = other.tail;
	count = other.count;

	for (int i = 0; i < size; ++i)
	{
		arr[i] = other.arr[i];
	}
}


Queue_int& Queue_int::operator=(const Queue_int& other)
{
	if (this == &other)
	{
		return *this;
	}

	delete[] arr;

	size = other.size;
	arr = new int[other.size];

	for (int i = 0; i < size; ++i)
	{
		arr[i] = other.arr[i];
	}
}


Queue_int& Queue_int::operator=(Queue_int&& other)
{
	if (this == &other)
	{
		return *this;
	}

	delete[] arr;

	size = other.size;
	arr = other.arr;

	other.arr = nullptr;
}


Queue_int::Queue_int(Queue_int&& other)
{
	size = other.size;
	arr = other.arr;

	other.arr = nullptr;
}


int Queue_int::GetSize()
{
	return this->count;
}


void Queue_int::Push(const int& element)
{
	if (count < size)
	{
		arr[tail] = element;

		tail = (tail + 1) % size;

		count++;
	}
	else
		std::cout << "queue is full!" << "\n";
}


int Queue_int::Pop()
{
	if (count > 0)
	{
		int element = arr[head];
		head = (head + 1) % size;
		count--;

		return element;
	}
	else
	{
		std::cout << "queue is empty!" << "\n";
		return -1;
	}
}

int Queue_int::Peek()
{
	return arr[head];
}

std::ostream& operator << (std::ostream& os, const Queue_int& obj)
{
	Queue_int temp = obj;

	os << "current queue => ";

	for (int i = 0; i < temp.size; i++)
	{
		if (temp.count > 0)
		{
			os << temp.arr[temp.head] << " ";
			temp.head = (temp.head + 1) % temp.size;
			temp.count--;
		}
	}

	os << "\n";

	return os;
}
