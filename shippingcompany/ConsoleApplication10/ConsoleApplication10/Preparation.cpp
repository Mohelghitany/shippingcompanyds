#include "Preparation.h"
#include "Company.h"
#include<iostream>
using namespace std;
Preparation::Preparation(Time* tt, int i, char T, float D, int L, int c,Company *cm) : event(tt, i,cm){
		 TYP=T;
		 DIST=D;
		 LT=L;
		 cost=c;

}
void Preparation::Execute(){
	Cargo *c = new Cargo(ID, &Te, LT, TYP, DIST, cost);

		if (TYP == 'N'){
			cmp->WaitN.insertFirst(c);
			
		}
		else if (TYP == 'S'){
			cmp->WaitS.enqueue(c);
		}
		else if (TYP == 'V'){
			cmp->WaitVIP.enqueue(c);
		}
	}
