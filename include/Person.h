#ifndef PERSON_H
#define PERSON_H
#include<string>
using namespace std;

class Person
{
    protected:
		string name,cnic,city,mobile_number;
		int age;

	public:
		int ID;
	int total_bill=0;
	    void setperson(int ID,string name,string cnic,string city,string mobile_number,int age);
		void getperson(string &name,string &cnic,string &city,string &mobile_number,int &age,int &ID);
		void displayperson();
};

#endif // PERSON_H
