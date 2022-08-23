#ifndef LINKEDLISTPRIORITYQUEUE_H
#define LINKEDLISTPRIORITYQUEUE_H

template<typename T>
class pqNode{
  T Item;
  int priority;
  pqNode<T>* next;
public:
pqNode(){next=nullptr;}
pqNode(T it){Item=it; next=nullptr;}
pqNode(T it,int p){Item=it; priority=p; next=nullptr;}
void setItem(T &it){Item=it;}
T getItem() const {return Item;};
void setPriority(const int p){priority=p;}
int getPriority()const{return priority;}
pqNode<T>* getNext() const {return next;}  
void setNext(pqNode<T>* ptr){next=ptr;}
~pqNode(){next=nullptr;}
};
template<class T>
class LinkedListPriorityQueue
{
    
public:
	pqNode<T>*front;
	pqNode<T>*rear;
    LinkedListPriorityQueue(){front=nullptr;rear=nullptr;}
    ~LinkedListPriorityQueue(){}
    bool isEmpty(){
        return front==NULL;
    }
    bool enqueue(const T&item, const int p){
        pqNode<T>*newpqNode=new pqNode<T>(item,p);

        if(isEmpty()){
            front=newpqNode;
            rear=newpqNode;
            return true;
        }
        pqNode<T>*ptr=front;
        while(ptr->getNext() && ptr->getNext()->getPriority()>=newpqNode->getPriority())
            ptr=ptr->getNext();
        if(ptr==front && ptr->getPriority()<newpqNode->getPriority()){
            newpqNode->setNext(front);
            front=newpqNode;
            return true;
        }
        newpqNode->setNext(ptr->getNext());
        ptr->setNext(newpqNode);
        return true;
        
    }
    bool dequeue(T&item){
        if(isEmpty()) return false;
        item=front->getItem();
        pqNode<T>*tmp=front;
        if(rear==front) rear=nullptr;
        front=front->getNext();
        delete tmp;
        return true;
    }
    
      T peek(){
        if(isEmpty()) return NULL;
        return front->getItem();
    }
    
    bool enqueueFront(const T&item){
        pqNode<T>*newpqNode=new pqNode<T>(item); 

        if(front) newpqNode->setNext(front);
        front=newpqNode;
        if(!rear) rear=newpqNode;
        return true;
    }
	void printQueue(){
		pqNode<T>*ptr = front;
		while (ptr){
			cout << *(ptr->getItem()) << " ";
			ptr = ptr->getNext();
		}
	}

};

#endif // LINKEDLISTPRIORITYQUEUE_H
