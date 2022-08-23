#ifndef CARGO_H
#define CARGO_H
#include "Time.h"
#include "Cargo.h"
class Cargo{
public:
	int ID;
	Time *Preparation;
	Time MT;
	int loadT;
	char type;
	int Distance;
	int Cost;
	int WT;
	Time DelvT;
	int rt = 0;
	int TID;

	Cargo(int I, Time* P, int L, char t, int D, int C);
	int getID();
	
	friend ostream &operator<<(ostream &output, const Cargo &D);
};
#endif