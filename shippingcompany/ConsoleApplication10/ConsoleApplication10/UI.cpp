#include "Company.h"
#include<fstream>
#include<iostream>
using namespace std;
class UI{
public:
	Company* cmp;
	int mode;
	void getmode(){
		cout << "\nChoose the mode:\n1.Interactive Mode\n2.Step by step Mode\n3.Silent Mode\n";
		cin >> mode;
	}
	void getCompanyptr(Company* cm){
		cmp = cm;
	}
	void writeFile(string s){
		ofstream o;
		o.open(s);
		o << " CDT CID PT WT TID\n";
		int avg_wait;
		int nt;
		Node<Cargo*>* nn = cmp->DeliveredC.getHead();
		while (nn != nullptr){
			Cargo* c = nn->getItem();
			if (c->type == 'N')
				cmp->Ncargo++;
			else if (c->type == 'V')
				cmp->Vcargo++;
			else if (c->type == 'S')
				cmp->Scargo++;
			
			o << c->DelvT.getDay() << ":" << c->DelvT.getHour() << " " << c->ID << " " << c->Preparation->getDay() << ":" << c->Preparation->getHour() << " " << (c->MT.getDay()) - (c->Preparation->getDay()) << ":" << (c->MT.getHour()) - (c->Preparation->getHour()) << " " << c->TID << "\n";
			
			
			nt = (c->MT.toInt()) - c->Preparation->toInt();
			nn = nn->getNext();
		}
		o << "\nCargos:" << cmp->Ncargo + cmp->Scargo + cmp->Vcargo << "[N:" << cmp->Ncargo << ",S:" << cmp->Scargo << ",V:" << cmp->Vcargo << "]\n";
		o << "\nAuto Promoted:" << cmp->Autocargo * 100<< "\n";
		avg_wait = nt / (cmp->Ncargo + cmp->Scargo + cmp->Vcargo);
		o << "\n average wait is " << nt / 24 << ":" << nt % 24;
			o << "\nTrucks:" << cmp->N + cmp->S + cmp->V << "[N:" << cmp->N << ",S:" << cmp->S << ",V:" << cmp->V << "]\n";
		o.close();
	}
	void show(){
				if (mode <= 2){
					cout << "\nTIME " << cmp->sysT.getDay() << " : " << cmp->sysT.getHour() << "\n";
					cout << "Waiting Cargos: {";

					cmp->WaitVIP.printQueue();
					cout << "} (";

					cmp->WaitS.printQueue();
					cout << ") [";

					cmp->WaitN.printList();
					cout << "]\n";
					cout << "Moving cargos: ";
					Node<Truck*>*N = cmp->MovingTruck.getHead();
					while (N != nullptr){
						Truck* t = N->getItem();
						cout << t->ID;
						if (t->type == 'N')
						{
							cout << " [ ";
							t->loadCargo.printQueue();
							cout << "]";
						}
						else if (t->type == 'S')
						{
							cout << " ( ";
							t->loadCargo.printQueue();
							cout << ")";
						}
						else if (t->type == 'V')
						{
							cout << " { ";
							t->loadCargo.printQueue();
							cout << "}";
						}
						N = N->getNext();
					}

					cout << "\nLoading Trucks: ";
					if (cmp->LNT != nullptr){ cout << cmp->LNT->ID << " "; }
					if (cmp->LVT != nullptr){ cout << cmp->LVT->ID << " "; }
					if (cmp->LST != nullptr){ cout << cmp->LST->ID << " "; }
					cout << "\nEmpty Trucks: {";
					cmp->VIPT.printQueue();
					cout << "} (";
					cmp->SpecialT.printQueue();
					cout << ") [";
					cmp->NormalT.printQueue();
					cout << "]\n";
					cout << " checkup cargo : "; cmp->CheckupTruck.printQueue(); cout << endl;
					cout << "Delivered cargos: ";
					cmp->DeliveredC.printList();
					cout << "\n______________________\n";
					if (mode == 1){
						cin.get();
					}
					else if (mode == 2){
						Sleep(1000);
					}
				}
				
				
			
		}
			
	
};