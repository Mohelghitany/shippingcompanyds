#ifndef CANCELLATION_H
#define CANCELLATION_H
#include"event.h"

class Cancellation :public event{
public:
	Cancellation(Time* t, int i, Company *c);
	void Execute();

};
#endif