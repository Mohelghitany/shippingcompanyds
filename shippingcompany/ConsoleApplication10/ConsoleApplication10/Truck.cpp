#include "Truck.h"
#include<iostream>
using namespace std;
Truck::Truck(char t, int tc, int mt, int s, int n, int i, bool ns){
		type = t;
		TC = tc;
		MT = mt;
		speed = s;
		NJ = n;
		ID = i;
		Ntrips = 0;
		nightshift = ns;
	}
ostream &operator<<(ostream &output, const Truck &D){
	output << D.ID;
	return output;
}