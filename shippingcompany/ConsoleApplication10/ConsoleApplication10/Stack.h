#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "Node.h"
using namespace std;

template <class T>
class Stack
{
    Node<T>*top;
public:
    Stack(){top=nullptr;}
    ~Stack(){}
    bool isEmpty(){
        if(top==NULL) return true;
        return false;
    }
    bool push(const T& it){
        Node<T>*newNode;
        if(newNode){
            newNode=new Node<T>(it);
            newNode->setNext(top);
            top=newNode;
            return true;
        }
        return false;
    }
    bool pop(T& item){
        if(top==nullptr) return false;
        item = top->getItem();
        Node<T>*tmp=top;
        top=top->getNext();
        delete tmp;
        return true;
    }
    T peek(){
        if(top!=NULL) return top->getItem();
        return NULL;//Stack Underflow
    }
    void printStack(){
        if(isEmpty()) return;
        Node<T>*ptr=top;
        while(ptr){
            cout<<ptr->getItem();
            ptr=ptr->getNext();
        }
    }
};

#endif // STACK_H
