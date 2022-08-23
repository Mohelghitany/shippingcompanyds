
#pragma once
#include "Node.cpp"


template < typename T>
class PriortyQueue
{
	Node<T>* back;
	Node<T>* front;
public:


	PriortyQueue()
	{
		back = NULL;
		front = NULL;
	}
	
	bool isEmpty() 
	{
		return front == nullptr;
	}


	bool enqueue( T& newEntry, int Priority)
	{
		Node<T>* newNodePtr = new Node<T>(newEntry);
		if (!newNodePtr)
			return false;
		newNodePtr->setPriority(Priority);
		// Insert the new node
		if (isEmpty())
		{
			front = newNodePtr; // The queue is empty
			back = newNodePtr;
			return true;
		}
		else if (back->getPriority() >= Priority)
		{
			back->setNext(newNodePtr);
			back = newNodePtr;
		}
		else if (front->getPriority() < Priority)
		{
			newNodePtr->setNext(front);
			front = newNodePtr;;
		}
		else
		{
			Node<T>* current = front;

			while (current->getNext() != NULL)
			{
				if (current->getNext()->getPriority() < Priority)
					break;

				current = current->getNext();
			}
			newNodePtr->setNext(current->getNext());
			current->setNext(newNodePtr);

		}
		return true;
	}

	bool dequeue(T& frntEntry)
	{
		if (isEmpty())
			return false;

		Node<T>* nodeToDeletePtr = front;
		frntEntry = front->getItem();
		front = front->getNext();
		// Queue is not empty; remove front
		if (nodeToDeletePtr == back)	 // Special case: one node in queue
		{
			back = nullptr;
			front = nullptr;
		}
		// Free memory reserved by the dequeued node
		delete nodeToDeletePtr;


		return true;

	}

	/////////////////////////////////////////////////////////////////////////////////////////



	bool peekFront(T& frntEntry) const
	{
		if (isEmpty())
			return false;

		frntEntry = front->getItem();
		return true;

	}

	///////////////////////////////////////////////////////////////////////////////////

	~PriortyQueue()
	{
	}

	/////////////////////////////////////////////////////////////////////////////////////////


	
};