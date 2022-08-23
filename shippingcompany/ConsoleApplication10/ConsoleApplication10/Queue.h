#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include"Node.h"
using namespace std;


template <class T>
class Queue{
    
    Node<T>*front;
    Node<T>*rear;
public:
    Queue(){front=nullptr;rear=nullptr;}
    ~Queue(){}
    bool isEmpty(){
        return front==NULL;
    }
    bool enqueue(const T&item){
        Node<T>*newNode=new Node<T>(item);
        if(rear) rear->setNext(newNode);
        rear=newNode;
        if(!front) front=newNode;
        return true;
    }
    bool dequeue(T&item){
        if(isEmpty()) return false;
        item=front->getItem();
        Node<T>*tmp=front;
        if(rear==front) rear=nullptr;
        front=front->getNext();
        delete tmp;
        return true;
    }
    
    T peek(){
        if(isEmpty()) return NULL;
        return front->getItem();
    }
    void printQueue(){
        Node<T>*ptr=front;
        while(ptr){
            cout<<*(ptr->getItem())<<" ";
            ptr=ptr->getNext();
        }
    }
};


#endif 
