#include "Promotion.h"
#include "Company.h"
Promotion::Promotion(Time* t, int i, int Ex,Company *cm) : event(t, i,cm){
		ExtraMoney = Ex;
}
void Promotion::Execute(){
	Node<Cargo*>* n = cmp->WaitN.getHead();
	//Cargo* c = n->getItem();
	while (n != nullptr){
		if (n->getItem()->getID() != ID){
			break;
		}
		n = n->getNext();
		//c = n->getItem();
	}
	if (n!=NULL){
		Cargo* c = n->getItem();
		c->Cost += ExtraMoney;
		cmp->WaitVIP.enqueue(n->getItem());
		cmp->WaitN.Remove(c);
		cmp->Autocargo++;
		
	}
	}
