#include "Functions.h"
#include"Person.h"
#include"Room.h"
#include"Employee.h"
#include"Misc.h"
#include"Date.h"
#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;
Employee *eptr=NULL;
Room *rptr=NULL;
string name,cnic,city,mobile_number,mc,shiftt,design;
int age,opt,id,id_checked,d,m,y,opt2,opt3,flag,sal,bill,bill_file=0;
char s,s2;

void Functions::finish()
{

    Room *curr_ptr=rptr;
    if(rptr->ID==0)
    {
        rptr=rptr->nptr;
    }

    else
    {
        while(curr_ptr->nptr!=NULL)
        {
            if(curr_ptr->nptr->ID==0)
            {
                curr_ptr->nptr=curr_ptr->nptr->nptr;
                break;
            }

            else
            {
                curr_ptr=curr_ptr->nptr;
            }
        }
    }
}
void Functions::finish_employee()
{

    Employee *curr_ptr=eptr;
    if(eptr->ID==0)
    {
        eptr=eptr->nptr;
    }

    else
    {
        while(curr_ptr->nptr!=NULL)
        {
            if(curr_ptr->nptr->ID==0)
            {
                curr_ptr->nptr=curr_ptr->nptr->nptr;
                break;
            }

            else
            {
                curr_ptr=curr_ptr->nptr;
            }
        }
    }
}
void Functions::entry()
{
Room *r1;
 r1=new Room;
					cout<<"Enter ID of Visitor: ";
					cin>>id;
					id_checked=check(id);
					cin.ignore();
					cout<<"Enter Name of Visitor: ";  getline(cin,name);
					cout<<"Enter CNIC of Visitor: ";  cin>>cnic;
					cout<<"Enter City of Visitor: ";  cin>>city;
					cout<<"Enter Mobile Number of Visitor: ";  cin>>mobile_number;
					cout<<"Enter age of Visitor: ";  cin>>age;

					r1->setperson(id_checked,name,cnic,city,mobile_number,age);
					cout<<"Enter Date of arrival\n";
					Day:
					cout<<"Enter Date of Day: ";  cin>>d;
					if(d==0||d>=32)
					{
						cout<<"Invalid entry"<<endl;
						goto Day;
					}
					Month:
					cout<<"Enter Date of Month: ";  cin>>m;
					if(m==0||m>=13)
					{
						cout<<"Invalid entry"<<endl;
						goto Month;
					}
					Year:
					cout<<"Enter Date of Year: ";  cin>>y;
					if(y<=1970||y>=2023)
					{
						cout<<"Invalid entry"<<endl;
						goto Year;
					}
					Date d1;
					d1.setvalues(d,m,y);
					cout<<endl;
					Room r2;
					r1->displayroom_expense();
					OPTION2:
					cin>>opt2;
					if(opt2>=7)
					{
						cout<<"Invalid Entry"<<endl;
						goto OPTION2;
					}
					else
					{
					add(r2,opt2);
				    }
				    cout<<endl;
				    int c;
				    cout<<"Do you want to add miscllaneous?(1 or 0)\n";
				    cin>>c;
				    Misc m1;
				    mc='Y';
				    if(c==1)
				    {
				    	while(mc!="N")
				    	{
				    	m1.displaymisc();
				    	OPTION3:
				    	cin>>opt3;
					    if(opt3>=7)
				    	{
					    	cout<<"Invalid Entry"<<endl;
					    	goto OPTION3;
				    	}
				    	else
					    {
					       addmisc(m1,opt3);
						   r1->total_bill=r2.total_bill+m1.bill;
						}

				        cout<<"Do you want to add more?(Y/N)\n";
				        cin>>mc;
		                }
		                c=0;
					}
					else if(c==0);
				    {
				    	r1->total_bill=r2.total_bill+m1.bill;
					}
					 r2.total_bill=0; m1.bill=0;
					 cout<<"Bill: "<<r1->total_bill<<endl;
}
int Functions::check(int visitor_id)
{
	Room *cptr=rptr;
	if(rptr!=NULL)
	                {

	                	while(cptr!=NULL)
	                	{
	                		if(visitor_id==cptr->ID)
	                		{
	                			cout<<"ID already exists.\nTry again"<<endl;
	                			cout<<"Enter ID:";
	                			cin>>visitor_id;
							}
							else
							cptr=cptr->nptr;
						}
					}
    return visitor_id;
}
int Functions::check_emp(int emp_id)
{
	Employee *cptr=eptr;
	if(eptr!=NULL)
	                {

	                	while(cptr!=NULL)
	                	{
	                		if(emp_id==cptr->ID)
	                		{
	                			cout<<"ID already exists.\nTry again"<<endl;
	                			cout<<"Enter id:";
	                			cin>>emp_id;
							}
							else
							cptr=cptr->nptr;
						}
					}
    return emp_id;
}
void Functions::entry_emp()
{
	Employee *ptr;
						ptr=new Employee;
							cout<<"Enter ID of Employee: ";
					cin>>id;
					id_checked=check_emp(id);
					cin.ignore();
					cout<<"Enter Name of Employee: ";  getline(cin,name);
					cout<<"Enter CNIC of Employee: ";  cin>>cnic;
					cout<<"Enter City of Employee: ";  cin>>city;
					cout<<"Enter Mobile Number of Employee: ";  cin>>mobile_number;
					cout<<"Enter age of Employee: ";  cin>>age;
					ptr->setperson(id_checked,name,cnic,city,mobile_number,age);

					cout<<"Enter the salary of employee "<<endl;
					cin>>sal;
					cout<<"Enter the job of employee "<<endl;
					cin>>design;
					cout<<"Enter the shift of employee "<<endl;
					cin>>shiftt;
						ptr->setvalues(design,sal,shiftt);
					cout<<"Enter Date of joining: ";
					Day:
					cout<<"Enter Date of Day: ";  cin>>d;
					if(d==0||d>=32)
					{
						cout<<"Invalid entry"<<endl;
						goto Day;
					}
					Month:
					cout<<"Enter Date of Month: ";  cin>>m;
					if(m==0||m>=13)
					{
						cout<<"Invalid entry"<<endl;
						goto Month;
					}
					Year:
					cout<<"Enter Date of Year: ";  cin>>y;
					if(y<=1970||y>=2023)
					{
						cout<<"Invalid entry"<<endl;
						goto Year;
					}
					Date d1;
					d1.setvalues(d,m,y);
					cout<<endl;
					record_empl();
							if(eptr==NULL)
	            	{
			            ptr->nptr=NULL;
			            eptr=ptr;
		            }
	            	else
	            	{
		        	Employee *currentptr=eptr;
		      	    while(currentptr->nptr!=NULL)
			        {
					 currentptr=currentptr->nptr;
				    }
				     ptr->nptr=NULL;
				     currentptr->nptr=ptr;
		            }
}
int Functions::from_string(string a)
   {
	int b;
	stringstream ss;
	ss<<a;
	ss>>b;
	return b;
}
void Functions::record_person(string name,string cnic,string city,string mobile_number,int age,int d,int m,int y,string bill_file)
{
	fstream file;
					 file.open("Record of Visitors.txt",ios::app);
					 file<<endl;
					 file<<"Name: "<<name<<endl;
					 file<<"Cnic: "<<cnic<<endl;
					 file<<"City: "<<city<<endl;
					 file<<"Mobile number: "<<mobile_number<<endl;
					 file<<"Age: "<<age<<endl;
					 file<<"Date of Entry:"<<endl;
					 file<<d<<":"<<m<<":"<<y<<endl;
					 file<<"Total Bill: Rs "<<bill_file<<endl;
					 file.close();
}
void Functions::record_empl()
{
	fstream file;
					 file.open("Record of Employee.txt",ios::app);
					 file<<endl;
					 file<<"Name: "<<name<<endl;
					 file<<"Cnic: "<<cnic<<endl;
					 file<<"City: "<<city<<endl;
					 file<<"Mobile number: "<<mobile_number<<endl;
					 file<<"Age: "<<age<<endl;
					 file<<"Date of Joining:"<<endl;
					 file<<d<<":"<<m<<":"<<y<<endl;
					 file<<"Salary of employee: Rs "<<sal<<endl;
					 file<<"Enter the job of employee: "<<design<<endl;
					 file<<"Enter the shift of employee: "<<shiftt<<endl;
					 file.close();
}
