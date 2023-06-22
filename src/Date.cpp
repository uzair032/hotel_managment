#include<iostream>
#include "Date.h"
using namespace std;

void Date::setvalues(int d,int m,int y)
{
			this->day=d;
			this->month=m;
			this->year=y;
}

void Date::getvalues(int &d,int &m,int &y)
{
			this->day=d;
			this->month=m;
			this->year=y;
}

void Date::displaytime()
{
			cout<<"Date: "<<this->day<<":"<<this->month<<":"<<this->year<<endl;
}
