#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

template <typename T>//������ ������
class List
{
public:
	List();//�����������
	~List();//����������

	void pop_front();
	void push_back(T data);//����� ���������� ��������� � ����� ������
	void clear();
	void pop_back();

	int getSize() { return size; };

	T& operator[](const int index);
	void push_front(T data);

private:
	template<typename T>
	class Node	//����
	{
	public:
		Node* pNext;//��������� �� ��������� �������
		T data;//���������� � ������� ��������
		Node(T data = T, Node* pNext = nullptr)//�����������
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int size;//������ ������
	Node<T>* head;//������ ������� ���c��
};

//------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------

template<typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;//��������� �� ��, ��� ������ ����
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
inline void List<T>::pop_front()
{
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;
	size--;
}

template<typename T>
void List<T>::push_back(T data)//���������� ����� ������
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head; //����������� ��������� ������ ������� �������� �������
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	size++;
}

template<typename T>
inline void List<T>::clear()
{
	while (size)
	{
		pop_front();
	}
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int count = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (count == index)
		{
			return current->data;
		}
		current = current->pNext;
		count++;
	}
}

template<typename T>
inline void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	size++;
}