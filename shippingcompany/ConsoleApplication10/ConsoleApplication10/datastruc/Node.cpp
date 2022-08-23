
//#ifndef __NODE_H_
//#define __NODE_H_

template < typename T>
class Node
{
private:
	T item;
	int Priority;
	Node<T>* next;
public:
	//	Node();
	//	Node(  T & r_Item);	
	//	void setItem(  T & r_Item);
	//	void setNext(Node<T>* nextNodePtr);
	//	T getItem()  ;
	//	Node<T>* getNext()  ;
	//	int getPriority();
	//	void setPriority(int P);
	//}; // end Node


	template < typename T>
	Node()
	{
		next = nullptr;
	}

	template < typename T>
	Node(T& r_Item)
	{
		item = r_Item;
		next = nullptr;
	}


	template < typename T>
	void setItem(T& r_Item)
	{
		item = r_Item;
	}

	template < typename T>
	void setNext(Node<T>* nextNodePtr)
	{
		next = nextNodePtr;
	}

	template < typename T>
	T getItem()
	{
		return item;
	}

	template < typename T>
	Node<T>* getNext()
	{
		return next;
	}
	template < typename T>
	int Node<T>::getPriority(){
		return Priority;
	}
	template < typename T>
	void setPriority(int P){
		Priority = P;
	}
};
//#endif