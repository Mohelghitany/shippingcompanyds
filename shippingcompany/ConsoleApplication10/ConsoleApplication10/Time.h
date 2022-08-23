#ifndef TIME_H
#define TIME_H
#include<iostream>

#include <string>
#include <sstream>
using namespace std;


class Time
{
private:
	int day, hour;
public:
	Time();
	Time(std::string s);
	Time(int d, int h);
	void nextT();
	void setTime(int d, int h);
	int getDay();
	int getHour();
	int toInt();
	

};
#endif
