#ifndef PREPARATION_H
#define PREPARATION_H
#include "event.h"

class Preparation :public event{
public:
	char TYP;
	float DIST;
	int LT;
	int cost;
	Preparation(Time* t, int i, char T, float D, int L, int c,Company* cm) ;
	void Execute();
};
#endif