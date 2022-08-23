
#include "event.h"

event::event(Time* t, int i, Company *c){
		Te=*t;
		ID = i;
		cmp = c;
	
	}

ostream &operator<<(ostream &output, const event &D) {
	output << D.ID;
	return output;
}