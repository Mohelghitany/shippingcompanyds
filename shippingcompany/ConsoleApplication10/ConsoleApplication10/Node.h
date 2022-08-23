#ifndef NODE_H
#define NODE_H

template<typename T>
class Node{
  T Item;
  Node<T>* next;
public:
Node(){next=nullptr;}
Node(T it){Item=it; next=nullptr;}
void setItem(T &it){Item=it;}
T getItem() const {return Item;};
Node<T>* getNext() const {return next;}  
void setNext(Node<T>* ptr){next=ptr;}
~Node(){next=nullptr;}
};

#endif // NODE_H
