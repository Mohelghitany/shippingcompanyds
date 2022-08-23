#include "Company.h"

Company::Company(){
	sysT.setTime(1, 0);
	Ncargo = 0;
	Vcargo = 0; Scargo = 0; Autocargo = 0;
}



void  Company::ReadFile(string s){
	ifstream myfile;
	myfile.open(s);

	
	int NS, SS, VS;
	int NTC, STC, VTC;
	
	
	int Nevents;
	char ETYP;
	char TYP;
	string ET;
	int ID;
	float DIST;
	int LT;
	int ExtraMoney;
	int cost;
	myfile >> N >> S >> V >> NS >> SS >> VS >> NTC >> STC >> VTC >> J >> CN >> CS >> CV >> AutoP >> MaxW;
	myfile >> Nevents;


	for (int i = 0; i<Nevents; i++){
		myfile >> ETYP;
		if (ETYP == 'R'){
			myfile >> TYP >> ET >> ID >> DIST >> LT >> cost;
			Time ETime(ET);
			event* e = new Preparation(&ETime, ID, TYP, DIST, LT, cost,this);
		
			Events.enqueue(e);
			
		}
		else if (ETYP == 'X'){
			myfile >> ET >> ID;
			Time ETime(ET);
			event* e = new Cancellation(&ETime, ID, this);
			Events.enqueue(e);
			
		}
		else if (ETYP == 'P'){
			myfile >> ET >> ID >> ExtraMoney;
			Time ETime(ET);
			event*e = new Promotion(&ETime, ID, ExtraMoney, this);
			Events.enqueue(e);
	
		}
	}
	for (int i = 0; i<V; i++){
		Truck* VIPTruck = new Truck('V', VTC, CV, VS, J,i+1,false);
		VIPT.enqueue(&*VIPTruck);
	}
	for (int i = 0; i<S; i++){
		Truck* SpecialTruck = new Truck('S', STC, CS, SS, J,i+1,true);
		SpecialT.enqueue(&*SpecialTruck);
	}
	for (int i = 0; i<N; i++){
		Truck* NormalTruck = new Truck('N', NTC, CN, NS, J,i+1,false);
		NormalT.enqueue(&*NormalTruck);
	}

}
void Company::executeEvents(){

		while (!Events.isEmpty() && Events.peek()->Te.getDay() == sysT.getDay() && Events.peek()->Te.getHour() == sysT.getHour()){
			event* e;
			Events.dequeue(e);
			e->Execute();
			
		}
		
	
}
void Company::getTruck(){
	Truck* t;
	if (LVT == nullptr){
		if (VIPT.dequeue(t))
		{
			LVT = t;
		
		}
	}
	if (LST == nullptr){
		if (SpecialT.dequeue(t))
		{
			LST = t;
			
		}
	}
	if (LNT == nullptr){
		if (NormalT.dequeue(t))
		{
			LNT = t;
		
		}
	}
}
void Company::MoveTruck(Truck* t){
	t->lastDl = sysT;
	MovingTruck.insertFirst(t);
	pqNode<Cargo*>*N = t->loadCargo.front;
	
	while (N != NULL){
		Cargo* c = N->getItem();
		c->MT = sysT;// moving time
		c->TID = t->ID;// make truck id in cargo the same as truck id
		N = N->getNext();
	
	}
}
void Company::chkTruck(){// if the truck wait for a long time >= maximum waiting time ->> moving
	if (!LVT->loadCargo.isEmpty())
	if (sysT.toInt() - LVT->LoadT.toInt() >= MaxW){
		MoveTruck(LVT);
		LVT = nullptr;
		getTruck();
	}
	if (!LNT->loadCargo.isEmpty())
	if (sysT.toInt() - LNT->LoadT.toInt() >= MaxW){
		MoveTruck(LNT);
		LNT = nullptr;
		getTruck();

	}
	if (!LST->loadCargo.isEmpty())
	if (sysT.toInt() - LST->LoadT.toInt() >= MaxW){
		MoveTruck(LST);
		LST = nullptr;
		getTruck();

	}
	
}
void Company::autopro(){
	Node < Cargo*>*N = WaitN.getHead();
	while (N != nullptr){
		Cargo* c = N->getItem();
		if (sysT.toInt() - c->Preparation->toInt() >= (AutoP*24)){
			WaitVIP.enqueue(c);
			WaitN.Remove(c);
		}
		N = N->getNext();
	}
	
}
void Company::FinMov(){
	if (!MovingTruck.isEmpty()){
		Node<Truck*>* tt = MovingTruck.getHead();
		while (tt != nullptr){
			Truck* t = tt->getItem();
			if (!t->loadCargo.isEmpty()){
				
				Cargo *c = t->loadCargo.peek();
				
				if (sysT.toInt() >= ((c->Distance / t->speed) + t->lastDl.toInt())){
					
					t->loadCargo.dequeue(c);
					DeliveredC.insertFirst(c);
					c->DelvT = sysT;
					t->lastDl = sysT;
				}
				
			}
			else{
				t->Ntrips++;
				if (t->Ntrips >= t->NJ){
					CheckupTruck.enqueue(t, t->MT);
					MovingTruck.Remove(t);
					t->ChkStart = sysT;

				}
				else{
					
					
					if(t->type == 'V')
					{
						VIPT.enqueue(t);
						t->TC = CV;
					}
					else if (t->type == 'N'){
						NormalT.enqueue(t);
						t->TC = CN;
					}
					else if (t->type == 'S'){
						SpecialT.enqueue(t);
						t->TC = CS;
					}
					MovingTruck.Remove(t);
				}
			}
			tt = tt->getNext();
		}
	}
}
void Company::checkedTr(){// to check trucks in maint.
	Truck* t = CheckupTruck.peek();
	if (t != nullptr){
		if (sysT.toInt() >= (t->ChkStart.toInt() + t->MT))
		{
			CheckupTruck.dequeue(t);
			if (t->type == 'V')
			{
				VIPT.enqueue(t);
				t->TC = CV;
			}
			else if (t->type == 'N'){
				NormalT.enqueue(t);
				t->TC = CN;
			}
			else if (t->type == 'S'){
				SpecialT.enqueue(t);
				t->TC = CS;
			}
		}

	}
}
void Company::work(){
	Cargo* nd;
	Truck* t;
	getTruck();
	chkTruck();
	autopro();
	//if (MovingCargos.dequeue(nd)){
	//	DeliveredC.insertFirst(nd);
	//}
	int st = sysT.getDay() * 24 + sysT.getHour();//system time to int
	int tt;//truck loading time to int
	
	
		while (!WaitVIP.isEmpty()){
			if (LVT != nullptr){
				int tt = LVT->LoadT.getDay() * 24 + LVT->LoadT.getHour();
				if (WaitVIP.dequeue(nd)){
					nd->rt = nd->loadT;
					if (LVT->loadCargo.isEmpty()){
						LVT->LoadT = sysT;
					}
					LVT->loadCargo.enqueue(nd, nd->Distance / LVT->speed);
					LVT->TC--;
					
					if (LVT->TC == 0 ){
						MoveTruck(LVT);
						LVT = nullptr;
						getTruck();
						
					}
					//MovingCargos.enqueue(nd, 1);
				}
				else if (LNT != nullptr){
					if (WaitVIP.dequeue(nd)){
						int tt = LNT->LoadT.toInt();
						nd->rt = nd->loadT;
						if (LNT->loadCargo.isEmpty()){
							LNT->LoadT = sysT;
						}
						LNT->loadCargo.enqueue(nd, nd->Distance / LNT->speed);
						WaitN.Remove(nd);
						LNT->TC--;
						if (LNT->TC == 0){
							MoveTruck(LNT);
							LNT = nullptr;
							getTruck();
							
						}
					}
				}
				else if (LST != nullptr){
					if (WaitVIP.dequeue(nd)){
						int tt = LST->LoadT.toInt();
						nd->rt = nd->loadT;
						if (LST->loadCargo.isEmpty()){
							LST->LoadT = sysT;
						}
						LST->loadCargo.enqueue(nd, nd->Distance / LST->speed);
						LST->TC--;
						if (LST->TC == 0 ){
							MoveTruck(LST);
							LST = nullptr;
							getTruck();
						
						}
					}
				}

				else
					break;
			}
		}
		while (!WaitS.isEmpty()){

			if (LST != nullptr){
				int tt = LST->LoadT.toInt();
				if (WaitS.dequeue(nd)){
					nd->rt = nd->loadT;
					if (LST->loadCargo.isEmpty()){
						LST->LoadT = sysT;
					}
					LST->loadCargo.enqueue(nd, nd->Distance / LST->speed);
					LST->TC--;
					if (LST->TC == 0 ){
						MoveTruck(LST);
						LST = nullptr;
						getTruck();
					
					}
				}
			}

			else
				break;
		}
		while (!WaitN.isEmpty()){
			if (LNT != nullptr){
				int tt = LNT->LoadT.toInt();
				nd = WaitN.getHead()->getItem();
				
				nd->rt = nd->loadT;
				if (LNT->loadCargo.isEmpty()){
					LNT->LoadT = sysT;
				}
				LNT->loadCargo.enqueue(nd, nd->Distance / LNT->speed);
				WaitN.Remove(nd);
				LNT->TC--;
				
				if (LNT->TC == 0 ){
					MoveTruck(LNT);
					LNT = nullptr;
					getTruck();
					
				}
			}

			else if (LVT != nullptr){
				int tt = LVT->LoadT.toInt();
				nd = WaitN.getHead()->getItem();
				nd->rt = nd->loadT;
				if (LVT->loadCargo.isEmpty()){
					LVT->LoadT = sysT;
				}
				LVT->loadCargo.enqueue(nd, nd->Distance / LVT->speed);
				LVT->TC--;
				if (LVT->TC == 0 ){
					MoveTruck(LVT);
					LVT = nullptr;
					getTruck();
					
				}

			}


			else
				break;
		}
	
	FinMov();
	checkedTr();
}
void Company::typeload(){
	if (LST != nullptr){
		pqNode<Cargo*> * p = LST->loadCargo.front;
		Cargo* cc = p->getItem();
		if (cc->type == 'V'&&LVT != nullptr){
			LST->TC++;
			LVT->TC--;
			LST->loadCargo.dequeue(cc);
			LVT->loadCargo.enqueue(cc, cc->Cost);
		}
		
	}
	 if (LVT != nullptr){
		pqNode<Cargo*> * p = LVT->loadCargo.front;
		Cargo* cc = p->getItem();
		 if (cc->type == 'N'&&LNT != nullptr){
			LVT->TC++;
			LNT->TC--;
			LVT->loadCargo.dequeue(cc);
			LNT->loadCargo.enqueue(cc, cc->Cost);
		}
		
	}
	 if (LNT != nullptr){
		 pqNode<Cargo*> * p = LNT->loadCargo.front;
		 Cargo* cc = p->getItem();
		 if (cc->type == 'V'&&LNT != nullptr){
			 LNT->TC++;
			 LVT->TC--;
			 LNT->loadCargo.dequeue(cc);
			 LVT->loadCargo.enqueue(cc, cc->Cost);
		 }

	 }
}
