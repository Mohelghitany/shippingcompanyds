#ifndef EVENT_H
#define EVENT_H
#include "Time.h"
#include"Cargo.h"
class Company;
class event{
public:
	Company *cmp;
	Time Te;
	int ID;
	event(Time *t, int i, Company *c);
	virtual void Execute() = 0;
	friend ostream &operator<<(ostream &output, const event &D);
	
};
#endif