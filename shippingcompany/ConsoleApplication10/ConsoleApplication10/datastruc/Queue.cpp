

#include "Node.cpp"

template <typename T>
class Queue
{
private:

	Node<T>* backPtr;
	Node<T>* frontPtr;
public:

	Queue()
	{
		backPtr = nullptr;
		frontPtr = nullptr;

	}
	/////////////////////////////////////////////////////////////////////////////////////////

	bool isEmpty() const
	{
		if (frontPtr == nullptr)
			return true;
		else
			return false;
	}

	/////////////////////////////////////////////////////////////////////////////////////////


	bool enqueue(const T& newEntry)
	{
		Node<T>* newNodePtr = new Node<T>(newEntry);
		// Insert the new node
		if (isEmpty())
			frontPtr = newNodePtr; // The queue is empty
		else
			backPtr->setNext(newNodePtr); // The queue was not empty
		backPtr = newNodePtr; // New node is at back
		return true;
	} 


	bool dequeue(T& frntEntry)
	{
		if (isEmpty())
			return false;

		Node<T>* nodeToDeletePtr = frontPtr;
		frntEntry = frontPtr->getItem();
		frontPtr = frontPtr->getNext();
		// Queue is not empty; remove front
		if (nodeToDeletePtr == backPtr)	 // Special case: one node in queue
			backPtr = nullptr;

		// Free memory reserved by the dequeued node
		delete nodeToDeletePtr;


		return true;

	}

	/////////////////////////////////////////////////////////////////////////////////////////

	bool peekFront(T& frntEntry) const
	{
		if (isEmpty())
			return false;

		frntEntry = frontPtr->getItem();
		return true;

	}
	///////////////////////////////////////////////////////////////////////////////////

	~Queue()
	{
	}

	/////////////////////////////////////////////////////////////////////////////////////////

	

};
