#pragma once
#include <iostream>

class Queue_int {
private:

	int* arr;

	int size, head, tail, count;

public:

	Queue_int(int size); // �������������

	Queue_int(const Queue_int& other); // �����������

	Queue_int(Queue_int&& other); // �����������

	Queue_int& operator=(const Queue_int& other); // ������������

	Queue_int& operator=(Queue_int&& other); // ������������ � ������������

	~Queue_int(); // ����������

	int GetSize();

	void Push(const int& element); // ������� ��������

	int Pop(); // �������� ��������

	int Peek(); // �������� ��������

	friend std::ostream& operator <<(std::ostream& os, const Queue_int& obj); // �����
};

