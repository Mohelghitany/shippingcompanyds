#ifndef PROMOTION_H
#define PROMOTION_H
#include "event.h"

class Promotion :public event{
public:
	int ExtraMoney;
	Promotion(Time* t, int i, int Ex, Company *cm);
	void Execute();
};
#endif