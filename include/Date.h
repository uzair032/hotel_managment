#ifndef DATE_H
#define DATE_H
#include<Person.h>
using namespace std;

class Date:public Person
{
		int day,month,year;
	public:
	    void setvalues(int d,int m,int y);
		void getvalues(int &d,int &m,int &y);
		void displaytime();

};

#endif // DATE_H
