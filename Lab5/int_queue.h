#pragma once
#include <iostream>

class Queue_int {
private:

	int* arr;

	int size, head, tail, count;

public:

	Queue_int(int size); // Инициализация

	Queue_int(const Queue_int& other); // Копирование

	Queue_int(Queue_int&& other); // Перемещение

	Queue_int& operator=(const Queue_int& other); // Присваивание

	Queue_int& operator=(Queue_int&& other); // Присваивание с перемещением

	~Queue_int(); // Деструктор

	int GetSize();

	void Push(const int& element); // Вставка элемента

	int Pop(); // Удаление элемента

	int Peek(); // Просмотр элемента

	friend std::ostream& operator <<(std::ostream& os, const Queue_int& obj); // Вывод
};

