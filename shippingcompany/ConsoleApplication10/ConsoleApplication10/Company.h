#ifndef COMPANY_H
#define COMPANY_H


#include "Truck.h"
#include "Cargo.h"
#include "Stack.h"
#include "LinkedList.h"
#include "Queue.h"
#include "LinkedListPriorityQueue.h"
#include "Cancellation.h"
#include "Promotion.h"
#include "Preparation.h"
#include "Node.h"
#include<fstream>
#include<iostream>
#include<Windows.h>
class event;
using namespace std;
class Company{
public:
	int N, S, V;
	int J, CN, CS, CV;
	int AutoP, MaxW;
	int Ncargo, Vcargo, Scargo, Autocargo;
	Time sysT;
	Queue <event*> Events;//events queue
	Queue <Cargo*> WaitVIP;//waiting vip cargos
	Queue <Cargo*> WaitS;//waiting spectial cargos
	LinkedList <Cargo*> WaitN;//waiting normal cargos
	LinkedListPriorityQueue<Cargo*> MovingCargos;//moving cargos with highest priority least remaining time
	Queue <Truck*> VIPT;// vip trunck list
	Queue <Truck*> SpecialT;//special trunck list
	Queue <Truck*> NormalT;//normal trunck list
	LinkedListPriorityQueue<Truck*>CheckupTruck;//checkup trunk list (one list for all) with least remaining time priority
	LinkedList <Cargo*> DeliveredC;
	LinkedList<Truck*> MovingTruck;
	Truck* LVT;//loading vip truck
	Truck* LST;//loading special truck
	Truck* LNT;//loading Normal truck
	int nWCargos;
	Company();
	void MoveTruck(Truck* t);
	void getTruck();
	void work();
	//void printn();
	void executeEvents();
	void ReadFile(string s);
	//void run();
	void chkTruck();
	void autopro();
	void FinMov();
	void checkedTr();
	void typeload();
};
#endif