#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.h"
using namespace std;

template <class T>
class LinkedList{
    Node<T>*head;
public:
  LinkedList():head(nullptr){}
  void print(){
    if(!head){cout<<"Empty List"<<endl; return;}
    Node<T>* ptr=head;
    while(ptr){
        cout<<ptr->getItem()<<" ";
        ptr=ptr->getNext();
    }cout<<endl;
}
Node<T>* getHead(){
    return head;
}


bool isEmpty(){
    if(!head) return true;
    return false;
}
Node<T>* traverse(){
    Node<T>*ptr=head;
    if(ptr){
        while(ptr->getNext()){
            ptr=ptr->getNext();
        }
    }
    return ptr;
}
void insert(const T& it, int pos){//incomplete
    Node<T>*newNode=new Node<T>(it);
    
}
void insertFirst(const T& it){
    Node<T>* newNode=new Node<T>(it);
    newNode->setNext(head);
    head=newNode;
}
void insertLast(const T& it){
    Node<T>*newNode=new Node<T>(it);
    Node<T>*ptr=traverse();
    if(ptr) ptr->setNext(newNode);
    else{
        head=newNode;
    }
}
void RemoveFirst(){
	Node<T>*ptr = head;
	head = head->getNext();
	delete ptr;
}
void RemoveLast(){
    Node<T>*ptr=head;
    while(ptr->getNext()->getNext()){
        ptr=ptr->getNext();
    }
    delete ptr->getNext();
    ptr->setNext(nullptr);
}
Node<T>* RemoveMin(){
    Node<T>*ptr=head;
    T minItem=ptr->getItem();
    Node<T>*minPtr=ptr;
    while(ptr->getNext()){
        if(ptr->getNext()->getItem()<minItem){
            minItem=ptr->getNext()->getItem();
            minPtr=ptr;//here minPtr points to the node preceding the min Item
        }
        ptr=ptr->getNext();
    }
    
    if(minPtr==head){
        head=head->getNext();
        delete minPtr;
        return minPtr;
    }
    Node<T>*tmp=minPtr->getNext();
    minPtr->setNext(minPtr->getNext()->getNext());
    delete tmp;
    return tmp;
}
void Reverse(){
    Node<T>*ptr=head;
    if(!ptr){
        
    }
    Reverse();
}
void printReversed(Node<T>*ptr){
    if(!ptr) return;
    printReversed(ptr->getNext());
    cout<<ptr->getItem()<<" ";
    if(ptr==head) cout<<endl;
}
void Remove(T& it){
	if (it == head->getItem()){
		head = head->getNext();
		
		return;
	}
	if (it == head->getNext()->getItem()){
		head->setNext(nullptr);

		return;
	}
    Node<T>*ptr=head;
    while(ptr->getNext() && ptr->getNext()->getItem()!=it){
        ptr=ptr->getNext();
    }
    Node<T>*tmp=ptr->getNext();
	if (tmp != nullptr){
		ptr->setNext(ptr->getNext()->getNext());
		delete tmp;
	}
}
  Node<T>* getPointerTo(const T&it) const{
      if(head->getItem()==it) return head;
      Node<T>*ptr=head;
      while(ptr->getNext()){
        if(ptr->getNext()->getItem()==it) return ptr->getNext();
          ptr=ptr->getNext();
      }
      return nullptr;
  }
  void DeleteALL(){
      Node<T>*ptr=head;
      while(ptr){
        ptr=head->getNext();
        delete head;
        head=ptr;
      }
  }
  void Merge(const LinkedList& List){
      Node<T>*ptr=traverse();
      ptr->setNext(List.head);
  }
  void PrintKth(int k){
      if(k<1){cout<<"Invalid Position!"<<endl;}
      if(k==1){cout<<head->getItem()<<endl;return;}
      Node<T>*ptr=head;
      int index=1;
      while(ptr){
        ptr=ptr->getNext();
        if(++index==k){cout<<ptr->getItem()<<endl;return;}
      }
      cout<<"Beyond List Length!"<<endl;
    }
  LinkedList SumLists(LinkedList&L1,LinkedList&L2){
      LinkedList<T>L3;
      Node<T>*ptr1=L1.head;
      Node<T>*ptr2=L2.head;
      while(ptr1 && ptr2){
          L3.insertLast(ptr1->getItem()+ptr2->getItem());
          ptr1=ptr1->getNext();ptr2=ptr2->getNext();
          if((ptr1&&!ptr2) || (ptr2&&!ptr1)) L3.DeleteALL();
      }
      return L3;
  }
  void printList(){
	  Node<T>*ptr = head;
	  while (ptr){
		  cout << *(ptr->getItem()) << " ";
		  ptr = ptr->getNext();
	  }
  }
};
#endif // LINKEDLIST_H

