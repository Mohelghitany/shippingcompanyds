#pragma once
#include "Node.cpp"
template < typename T>
class Stack
{
	Node<T>*Top;
public:

	template < typename T>
	Stack()
	{
		Top = nullptr;
	}

	template < typename T>
	bool isEmpty()const
	{
		return Top == nullptr;
	}

	template < typename T>
	bool pop(T&TopEntry)
	{
		if (isEmpty())
		{
			return false;
		}
		TopEntry = Top->getItem();
		Top = Top->getNext();
		return true;
	}
	template < typename T>
	bool push( T& newEntry)
	{
		//Node<T>* newNodePtr = new Node<T>(newEntry);
		//newNodePtr->setNext(Top);
		newEntry->setNext(Top);
		//Top = newNodePtr;
		Top = newEntry;
		return true;
	}
	template < typename T>
	T peek()const
	{
		return Top->getItem();
	}
};