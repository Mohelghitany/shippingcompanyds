#include"Time.h"

Time::	Time(){

	}
Time::Time(std::string s){
		stringstream sss(s);
		string i;
		getline(sss, i, ':');
		day = stoi(i);
		getline(sss, i, ' ');
		hour = stoi(i);
	}
Time::Time(int d, int h){
		day = d;
		hour = h;
	}
void Time::setTime(int d, int h){
		day = d;
		hour = h;
	}
int Time::getDay(){
		return day;
	}
int Time::getHour(){
		return hour;
	}
void Time::nextT(){
	int d, h;
	d = getDay();
	h = getHour();
	if (h >= 23){
		d = d + 1;
		h = 0;
	}
	else{
		h = h + 1;
	}
	setTime(d, h);
}
int Time::toInt(){
	return day * 24 + hour;
}

