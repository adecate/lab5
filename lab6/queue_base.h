#pragma once

template <typename T>
class QueueBase
{
public:
	virtual void Push(const T& element) = 0; // ������� (����������) ��������
	virtual T Pop() = 0; // �������� ��������
	virtual T Peek() = 0; // �������� (������ ��� ��������) �������� 
	virtual int GetSize() const = 0; // ����������� ���-�� ���������
};
