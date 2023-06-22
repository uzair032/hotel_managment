#include<iostream>
#include "Person.h"
using namespace std;

void Person::setperson(int ID,string name,string cnic,string city,string mobile_number,int age)
{
			this->ID=ID;
			this->name=name;
			this->cnic=cnic;
			this->city=city;
			this->mobile_number=mobile_number;
			this->age=age;
}

void Person::getperson(string &name,string &cnic,string &city,string &mobile_number,int &age,int &ID)
{
			name=this->name;
			cnic=this->cnic;
			city=this->city;
			mobile_number=this->mobile_number;
			age=this->age;
			ID=this->ID;
}

void Person::displayperson()
{
			cout<<"Name: "<<this->name<<endl;
			cout<<"CNIC: "<<this->cnic<<endl;
			cout<<"City: "<<this->city<<endl;
			cout<<"Mobile number: "<<this->mobile_number<<endl;
			cout<<"Age: "<<this->age<<endl;
			cout<<"ID: "<<this->ID<<endl;
			cout<<"Total Bill: Rs"<<this->total_bill<<endl;
}
