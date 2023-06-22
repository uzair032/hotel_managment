#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<Person.h>

class Employee:public Person
{
		int salary;
		string job,shift;
	public:
		Employee *nptr;
	    void setvalues(string j,int s,string shift);
		void getvalues(string &j,int &s,string &shift);
		void displayEmployee();
};


#endif // EMPLOYEE_H
