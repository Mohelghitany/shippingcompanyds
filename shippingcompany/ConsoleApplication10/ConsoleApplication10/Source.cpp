#include<iostream>
#include "Time.h"
#include "Company.h"
#include "UI.cpp"
using namespace std;
int main(){
	Company *x = new Company();
	UI u;
	x->ReadFile("Input.txt");
	u.getmode();
	u.getCompanyptr(x);
	//u.show(x);
	while (!x->Events.isEmpty() || !x->WaitN.isEmpty() || !x->WaitS.isEmpty() || !x->WaitVIP.isEmpty() || !x->MovingCargos.isEmpty() || !x->MovingTruck.isEmpty() || !x->LVT->loadCargo.isEmpty() || !x->LST->loadCargo.isEmpty() || !x->LNT->loadCargo.isEmpty())
	{
		x->executeEvents();
		if (x->sysT.getHour() >= 5 && x->sysT.getHour() <= 11){
			x->work();
		}
		u.show();
		x->sysT.nextT();
	}
	u.writeFile("result.txt");
	system("pause");
	return 0;
}