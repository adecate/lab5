#pragma once
#include <iostream>

template<typename T>
class Queue {
private:

	T* arr;

	int size, head, tail, count;

public:

	Queue(int size); 

	Queue(const Queue& other); 

	Queue(Queue&& other); 

	Queue& operator=(const Queue& other); 

	Queue& operator=(Queue&& other); 

	~Queue(); 

	int GetSize();

	void Push(const T& element);

	T Pop(); 

	T Peek(); 

	template<typename T>
	friend std::ostream& operator <<(std::ostream& os, const Queue<T>& obj); // Вывод
};

template<typename T>
Queue<T>::Queue(int size) : size(size), head(0), tail(0), count(0)
{
	arr = new T[size];
}

template<typename T>
Queue<T>::~Queue()
{
	delete[] arr;
}

template<typename T>
Queue<T>::Queue(const Queue& other)
{
	size = other.size;

	arr = new T[other.size];

	head = other.head;
	tail = other.tail;
	count = other.count;

	for (int i = 0; i < size; ++i)
	{
		arr[i] = other.arr[i];
	}
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue& other)
{
	if (this == &other)
	{
		return *this;
	}

	delete[] arr;

	size = other.size;
	arr = new T[other.size];

	for (int i = 0; i < size; ++i)
	{
		arr[i] = other.arr[i];
	}
}

template<typename T>
Queue<T>& Queue<T>::operator=(Queue&& other)
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

template<typename T>
Queue<T>::Queue(Queue&& other)
{
	size = other.size;
	arr = other.arr;

	other.arr = nullptr;
}

template<typename T>
int Queue<T>::GetSize()
{
	return this->count;
}

template<typename T>
void Queue<T>::Push(const T& element)
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

template<typename T>
T Queue<T>::Pop()
{
	if (count > 0)
	{
		T element = arr[head];
		head = (head + 1) % size;
		count--;

		return element;
	}
	else
	{
		std::cout << "queue is empty" << "\n";
		return -1;
	}
}

template<typename T>
T Queue<T>::Peek()
{
	return arr[head];
}

template<typename T>
std::ostream& operator << (std::ostream& os, const Queue<T>& obj)
{
	Queue<T> temp = obj;

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

