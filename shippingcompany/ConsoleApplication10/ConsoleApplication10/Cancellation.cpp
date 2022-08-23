#include"Cancellation.h"
#include "Company.h"
Cancellation::Cancellation(Time* t, int i, Company *c) :event(t, i,c){

	}
void Cancellation::Execute(){
	
	if (!cmp->WaitN.isEmpty()){
		Node<Cargo*>* n = cmp->WaitN.getHead();
		Cargo* c = n->getItem();
		while (c != nullptr&c->getID() != ID){
			n = n->getNext();
			c = n->getItem();
		}
		if (c->getID() == ID)
			cmp->WaitN.Remove(c);
	}
}

