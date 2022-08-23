#ifndef TRUCK_H
#define TRUCK_H
#include<string>
#include"Cargo.h"
#include"LinkedListPriorityQueue.h"
#include<iostream>
using namespace std;
class Truck{
public:
	Time LoadT;// time start loading
	int ID;
	char type;
	int TC;
	Time lastDl;
	int Ntrips;
	Time ChkStart;
	int MT;
	int speed;
	float DI;
	int NJ;
	bool nightshift;
	LinkedListPriorityQueue <Cargo*> loadCargo;
	Truck(char t, int tc, int mt, int s, int n,int i,bool nightshift);
	friend ostream &operator<<(ostream &output, const Truck &D);
};

#endif