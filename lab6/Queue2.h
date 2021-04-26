#pragma once

#include "queue_base.h"
#include "List.h"

template<typename T>
class Queue2 : public QueueBase<T>
{
private:

	List2<T>* list2;
	int size;

public:

	Queue2();

	Queue2(const Queue2& other);

	Queue2(Queue2&& other);

	~Queue2();

	int GetSize() const;

	void Push(const T& element);

	T Pop();

	T Peek();

	Queue2& operator=(const Queue2& other);
	Queue2& operator=(Queue2&& other);

	template<typename T>
	friend std::ostream& operator<< (std::ostream& os, const Queue2<T>& obj);
};

template<typename T>
Queue2<T>::Queue2() : list2(new List2<T>()), size(0)
{ }

template<typename T>
Queue2<T>::Queue2(const Queue2& other) : list2(new List2<T>()), size(other.size)
{
	for (int i = 0; i < other.size; i++)
	{
		this->list2->push_back(other.list2->operator[](i));
	}
}

template<typename T>
Queue2<T>::Queue2(Queue2&& other) : size(other.size), list2(other.list2)
{
	other.size = NULL;
	other.list2 = nullptr;
}

template<typename T>
Queue2<T>::~Queue2()
{
	delete list2;
	size = 0;
}

template<typename T>
int Queue2<T>::GetSize() const { return size; }

template<typename T>
void Queue2<T>::Push(const T& element)
{
	list2->push_back(element);
	++size;
}

template<typename T>
T Queue2<T>::Pop()
{
	--size;
	return list2->pop_front();
}

template<typename T>
T Queue2<T>::Peek() { return list2->operator[](0); }

template<typename T>
Queue2<T>& Queue2<T>::operator=(const Queue2<T>& other)
{
	if (this == &other)
	{
		return *this;
	}

	list2->clear();

	size = other.size;

	for (int i = 0; i < other.size; i++)
	{
		this->list2->push_back(other.list2->operator[](i));
	}
}

template<typename T>
Queue2<T>& Queue2<T>::operator=(Queue2<T>&& other)
{
	if (this == &other)
	{
		return *this;
	}

	list2->clear();

	size = other.size;
	list2 = other.list2;
	other.size = NULL;
	other.list2 = nullptr;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Queue2<T>& obj)
{
	os << "Текущая очередь => ";

	for (size_t i = 0; i < obj.size; i++)
	{
		os << obj.list2->operator[](i) << " ";
	}

	os << std::endl;

	return os;
}
