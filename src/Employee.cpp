#include<iostream>
#include "Employee.h"
#include"Person.h"
using namespace std;

void Employee::setvalues(string j,int s,string shift)
{
			this->job=j;
			this->salary=s;
			this->shift=shift;
}

void Employee::getvalues(string &j,int &s,string &shift)
{
			j=this->job;
			s=this->salary;
			shift=this->shift;
}

void Employee::displayEmployee()
{
			cout<<"Name: "<<this->name<<endl;
			cout<<"CNIC: "<<this->cnic<<endl;
			cout<<"City: "<<this->city<<endl;
			cout<<"Mobile number: "<<this->mobile_number<<endl;
			cout<<"Age: "<<this->age<<endl;
			cout<<"ID: "<<this->ID<<endl;
			cout<<"Job: "<<this->job<<endl;
			cout<<"Salary: "<<this->salary<<endl;
			cout<<"Shift: "<<this->shift<<endl;
}
