#include <cmath>
#include <cstdio>
#include <stdlib.h>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
	int value;
	Node* next;
	Node();
	Node(int value);
};

Node::Node()
	: value(0)
	, next(nullptr)
{
}

Node::Node(int value)
	: value(value)
	, next(nullptr)
{
}

class LinkedList
{
private:
	Node* head;
	Node* tail;
	int size;
public:
	LinkedList();
	void push_back(int element);
	void push_front(int element);
	void insert(int element, int position);
	void pop_back();
	void pop_front();
	void remove(int pos);
	int search(int element);	//returns position of the element and -1 if there is no such element
	void print() const;
	
	int count(int X);
};

LinkedList::LinkedList()
	: head(nullptr)
	, tail(nullptr)
	, size(0)
{
}

void LinkedList::push_back(int element)
{
	if (this->head == nullptr)
	{
		this->head = new Node(element);
		this->tail = this->head;
	}
	else
	{
		this->tail->next = new Node(element);
		this->tail = this->tail->next;
	}
	this->size++;
}

void LinkedList::push_front(int element)
{
	if (this->head == nullptr)
	{
		this->head = new Node(element);
		this->tail = this->head;
	}
	else
	{
		Node* node = new Node(element);
		node->next = this->head;
		this->head = node;
	}
	this->size++;
}

void LinkedList::insert(int element, int position)
{
	int pos = 0;
	if (position<0 || position>this->size)
	{
		cout << "Position "<<position<<" is out of reach. Current size is "<<this->size<<"\n";
		return;
	}
	if (position == 0)
	{
		push_front(element);
		return;
	}
	if (position == this->size)
	{
		push_back(element);
		return;
	}
	Node* previous = nullptr;
	Node* node = this->head;
	while (pos < position)
	{
		previous = node;
		node = node->next;
		pos++;
	}
	Node* to_add = new Node(element);
	to_add->next = node;
	previous->next = to_add;
	this->size++;

}

void LinkedList::pop_back()
{
	if (this->head == nullptr) cout<<"The list is empty. No elements to remove\n";
	else if (this->head == this->tail)
	{
		delete this->head;
		this->head = nullptr;
		this->tail = this->head;
		this->size--;
	}
	else
	{
		Node* node = this->head;
		Node* previous = nullptr;
		while (node->next != nullptr)
		{
			previous = node;
			node = node->next;
		}
		delete node;
		if(previous!=nullptr) previous->next = nullptr;
		this->tail = previous;
		this->size--;
	}
}

void LinkedList::pop_front()
{
	if (this->head == nullptr) cout << "The list is empty. No elements to remove\n";
	else if (this->head == this->tail)
	{
		delete this->head;
		this->head = nullptr;
		this->tail = this->head;
		this->size--;
	}
	else
	{
		Node* node = this->head;
		this->head = this->head->next;
		delete node;
		this->size--;
	}
}

void LinkedList::remove(int position)
{
	if (position<0 || position>this->size) cout << "Position " << position << " is out of reach. Current size is " << this->size << '\n';
	else if (position == 0)
	{
		pop_front();
	}
	else if (position == this->size-1)
	{
		pop_back();
	}
	else
	{
		int pos = 0;
		Node* node = this->head;
		Node* previous = nullptr;

		while (pos < position)
		{
			previous = node;
			node = node->next;
			pos++;
		}
		previous->next = node->next;
		delete node;
		this->size--;
	}
}

void LinkedList::print() const
{
	if (size == 0)
	{
		cout << "The list is empty.\n";
		return;
	}
	Node* node = this->head;
	while (node != nullptr)
	{
		cout << node->value << " ";
		node = node->next;
	}
	cout << '\n';
}

int LinkedList::search(int element)
{
	int pos = 0;
	Node* node = this->head;
	while (node != nullptr)
	{
		if (node->value == element) return pos;
		pos++;
		node = node->next;
	}
	return -1;
}

int LinkedList::count(int X)
{
	Node* current = this->head;
	int counter = 0;
	while (current != nullptr)
	{
		if (current->value == X) counter++;
		current = current->next;
	}
	return counter;
}

int main()
{
	LinkedList list;
	list.push_front(1);
	list.push_back(2);
	list.push_front(0);
	list.insert(-1, 0);
	list.insert(4, 4);
	list.insert(3, 4);
	list.print();
	cout << list.search(4) << '\n';

	list.pop_front();
	list.pop_back();
	list.remove(1);
	list.remove(1);
	list.remove(0);
	list.print();

	cout<<list.search(0)<<'\n';
	cout<<list.search(3)<<'\n';
	
	return 0;
}
