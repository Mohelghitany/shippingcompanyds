#include "Cargo.h"
#include<iostream>
using namespace std;
Cargo::Cargo(int I, Time* P, int L, char t, int D, int C){

		ID = I;
		Preparation = P;
		loadT = L;
		type = t;
		Distance = D;
		Cost = C;
	}
int Cargo::getID(){
		return ID;
	}

 ostream &operator<<(ostream &output, const Cargo &D) {
	 output << D.ID;
	return output;
}