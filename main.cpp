#include<iostream>
#include<fstream>
#include<sstream>
#include"Person.h"
#include"Room.h"
#include"Employee.h"
#include"Misc.h"
#include"Date.h"
#include"Functions.h"
using namespace std;

int main()
{
    Employee *zptr=NULL;
Room *fptr=NULL;
    string name,cnic,city,mobile_number,shiftt,design,mc;
    int age,opt,id,id_checked,d,m,y,opt2,opt3,flag,sal,bill,bill_file=0;
char s,s2;
    Functions f1;
//Start of Person file
	string b;
   fstream file;

   file.open("saved.person.data.txt",ios::in);

   while(!file.eof())
   {
		   Room *r1;
		   r1=new Room;

			getline(file,b);
			if(b=="\0")
		  {
		  break;
		  }
			else
			{
			name=b;

			getline(file,b);
            cnic=b;
			getline(file,b);
			city=b;
			getline(file,b);
			mobile_number=b;
			getline(file,b);
			age=f1.from_string(b);
				getline(file,b);
			id=f1.from_string(b);
		    getline(file,b);
			bill=f1.from_string(b);
			r1->setperson(id,name,cnic,city,mobile_number,age);
			r1->total_bill=bill;
			if(fptr==NULL)
	        {
			    r1->nptr=NULL;
			    fptr=r1;
		    }
	            	else
	            	{
		        	Room *currentptr=fptr;
		      	    while(currentptr->nptr!=NULL)
			        {
					 currentptr=currentptr->nptr;
				    }
				     r1->nptr=NULL;
				     currentptr->nptr=r1;
		            }
	       }

   }
   file.close();
 //Start of Employee file
   	string a;
   fstream file2;
   file2.open("saved.employee.data.txt",ios::in);
   while(!file2.eof())
   {
   	Employee *e1;
		   e1=new Employee;
			getline(file2,a);
			if(a=="\0")
		  {
		  break;
		  }
			else
		  {
			name=a;

			getline(file2,a);
            cnic=b;
			getline(file2,a);
			city=b;
			getline(file2,a);
			mobile_number=a;
			getline(file2,a);
			age=f1.from_string(a);
				getline(file2,a);
			id=f1.from_string(a);
		getline(file2,a);
			design=a;
				getline(file2,a);
			sal=f1.from_string(a);
				getline(file2,a);
			shiftt=a;

			e1->setperson(id,name,cnic,city,mobile_number,age);
			e1->setvalues(design,sal,shiftt);
			if (zptr == NULL)
			{
				zptr=e1;
				e1->nptr=NULL;
			}
			else
			{
				Employee *current=zptr;
				while (current->nptr!=NULL)
				{
					current=current->nptr;
			    }
				current->nptr=e1;
				e1->nptr=NULL;
			}
	    }

   }
   file2.close();

	while(1)
	{
	cout<<"\n\t\t\t\t  * MAIN MENU *";
		cout<<"\n\n\n\t\t\t1.ADD VISITOR";
		cout<<"\n\t\t\t2.UPDATE VISITOR";
		cout<<"\n\t\t\t3.REMOVE VISITOR";
		cout<<"\n\t\t\t4.TOTAL BILL AND CHECK IN";
		cout<<"\n\t\t\t5.EMPLOYEE ENTRY";
		cout<<"\n\t\t\t6.REMOVAL OF EMPLOYEE";
		cout<<"\n\t\t\t7.UPDATE EMPLOYEE";
		cout<<"\n\t\t\t8.DISPLAY EMPLOYEES ";
		cout<<"\n\t\t\t9.EXIT \n";
		cin>>opt;
		cout<<endl;
		switch(opt)
		{
			case 1:
				{
				    Room *r1;
				    r1=new Room;
					cout<<"Enter ID of Visitor: ";
					cin>>id;
					id_checked=f1.check(id);
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

					}
					else if(c==0);
				    {
				    	r1->total_bill=r2.total_bill+m1.bill;
					}
					 r2.total_bill=0; m1.bill=0;
					 cout<<"*********"<<endl;
					 cout<<"Bill: "<<r1->total_bill<<endl;
					 bill_file=r1->total_bill;
					 f1.record_person(name, cnic, city, mobile_number,age,d,m,y, bill_file);
					if(fptr==NULL)
	            	{
			            r1->nptr=NULL;
			            fptr=r1;
		            }
	            	else
	            	{
		        	Room *currentptr=fptr;
		      	    while(currentptr->nptr!=NULL)
			        {
					 currentptr=currentptr->nptr;
				    }
				     r1->nptr=NULL;
				     currentptr->nptr=r1;
		            }
		            break;
				}
			case 2:
			    {
			    	flag=0;
			    	cout<<"Enter Visitor ID needed to be updated:\n";
			        cin>>id;
			        Room *curr_ptr=fptr;
			        while(curr_ptr!=NULL)
			        {
			        if(id==curr_ptr->ID)
			        {
			    	cout<<"Do you want to update the whole date or just the total bill(room services and miscllaneous)?(y/n)\n";
			    	cin>>s2;
			    	if(s2=='y')
			    	{
			    		f1.entry();
			    		flag=1;
			    		break;
					}
					else if(s2=='n')
					{
						Room r2;
					r2.displayroom_expense();
					cin>>opt2;
					if(opt2>=7)
					{
						cout<<"Invalid Entry"<<endl;
						break;
					}
					else
					{
					add(r2,opt2);
				    }
				    cout<<endl;
				    string c;
				    cout<<"Do you want to add miscllaneous?(Y/N)\n";
				    cin>>c;
				    Misc m1;

				    if(c=="Y")
				    {
				    mc='Y';
				    	while(mc!="N")
				    	{

				    	m1.displaymisc();
				    	cin>>opt3;
					    if(opt3>=7)
				    	{
					    	cout<<"Invalid Entry"<<endl;
					    	break;
				    	}
				    	else
					    {
					       addmisc(m1,opt3);
						   curr_ptr->total_bill=r2.total_bill+m1.bill;

						}

				        cout<<"Do you want to add more?(Y/N)\n";
				        cin>>mc;
		                }
		                c='N';
					}
					else if(c=="N");
				    {
				    	curr_ptr->total_bill=r2.total_bill+m1.bill;
					}
					r2.total_bill=0; m1.bill=0;
					}//end of room
					 cout<<"Bill: "<<curr_ptr->total_bill<<endl;
					flag=1;
					break;
				    }
				    else
				    curr_ptr=curr_ptr->nptr;
				    }
				    if(flag==0)
				    {
				    	cout<<"No Id found"<<endl;
				    	break;
					}
					break;
				}
			case 3:
				{
				    flag=0;
			        cout<<"Enter Visitor ID needed to be removed:\n";
			        cin>>id;
					Room *curr_ptr=fptr;
					while(curr_ptr!=NULL)
					{
						if(id==curr_ptr->ID)
						{
							cout<<"Visitor removed"<<endl;
							curr_ptr->ID=0;
						        f1.finish();
						        delete curr_ptr;
						        flag=1;
						    	break;
						}
						else
						curr_ptr=curr_ptr->nptr;
					}
					if(flag==0)
					{
						cout<<"Invalid Id"<<endl;
					}
					break;
				}

			case 4:
			    {
			    	Room *curr_ptr=fptr;
			    	if(curr_ptr==NULL)
			    	{
			    		cout<<"No record found"<<endl;
					}
					else
					{
			    	while(curr_ptr!=NULL)
			    	{
			    		curr_ptr->displayperson();
			    		cout<<"\n**********\n";
			    		curr_ptr=curr_ptr->nptr;
					}
				    }
					break;
				}
				case 5:
					{
						Employee *ptr;
						ptr=new Employee;
							cout<<"Enter ID of Employee: ";
					cin>>id;
					id_checked=f1.check_emp(id);
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
					Daye:
					cout<<"Enter Date of Day: ";  cin>>d;
					if(d==0||d>=32)
					{
						cout<<"Invalid entry"<<endl;
						goto Daye;
					}
					Monthe:
					cout<<"Enter Date of Month: ";  cin>>m;
					if(m==0||m>=13)
					{
						cout<<"Invalid entry"<<endl;
						goto Monthe;
					}
					Yeare:
					cout<<"Enter Date of Year: ";  cin>>y;
					if(y<=1970||y>=2023)
					{
						cout<<"Invalid entry"<<endl;
						goto Yeare;
					}
					Date d1;
					d1.setvalues(d,m,y);
					cout<<endl;
					f1.record_empl();
							if(zptr==NULL)
	            	{
			            ptr->nptr=NULL;
			            zptr=ptr;
		            }
	            	else
	            	{
		        	Employee *currentptr=zptr;
		      	    while(currentptr->nptr!=NULL)
			        {
					 currentptr=currentptr->nptr;
				    }
				     ptr->nptr=NULL;
				     currentptr->nptr=ptr;
		            }
		            break;
					}
					case 6:
						{
				    flag=0;
			        cout<<"Enter Employee ID needed to be removed:\n";
			        cin>>id;
					Employee *curr_ptr=zptr;
					while(curr_ptr!=NULL)
					{
						if(id==curr_ptr->ID)
						{
							cout<<"Employee removed"<<endl;
							curr_ptr->ID=0;
						        f1.finish_employee();
						        delete curr_ptr;
						        flag=1;
						    	break;

						}
						else
						curr_ptr=curr_ptr->nptr;
					}
					if(flag==0)
					{
						cout<<"Invalid ID"<<endl;
					}
					break;
				}
				case 7:
					{flag=0;
			    	cout<<"Enter Employee ID needed to be updated:\n";
			        cin>>id;
			        Employee *curr_ptr=zptr;
			        while(curr_ptr!=NULL)
			        {
			        if(id==curr_ptr->ID)
			        {
			    	cout<<"Do you want to update the whole date or upgrade?(y/n)\n";
			    	cin>>s2;
			    	if(s2=='y')
			    	{
			    		f1.entry_emp();
					}
					else if(s2=='n')
					{
					cout<<"Enter the salary of employee "<<endl;
					cin>>sal;
					cout<<"Enter the job of employee ";
					cin>>design;
					cout<<"Enter the shift of employee "<<endl;
					cin>>shiftt;
						curr_ptr->setvalues(design,sal,shiftt);
					}
					flag=1;
					break;
					}
					else
					{
						curr_ptr=curr_ptr->nptr;
					}

				}
				if(flag==0)
				{
					cout<<"No ID found "<<endl;
					break;
				}
				break;
			}
					case 8:
						{
							Employee *xptr=zptr;
							if(xptr==NULL)
							{
								cout<<"No data found"<<endl;
							}
							while(xptr!=NULL)
							{
								xptr->displayEmployee();
								cout<<"\n*************\n";
								xptr=xptr->nptr;
							}
							break;
						}

						case 9:
						{
							Date d1;
							int bill;
							fstream file4,file3;
							file4.open("saved.employee.data.txt",ios::out);
							Employee *xptr=zptr;
							while(xptr!=NULL)
							{
								xptr->getperson(name,cnic,city,mobile_number,age,id);
								file<<name<<endl<<cnic<<endl<<city<<endl<<mobile_number<<endl<<age<<endl<<id<<endl;
								xptr->getvalues(design,sal,shiftt);
								file<<design<<endl<<sal<<endl<<shiftt<<endl;
								xptr=xptr->nptr;

							}
							file4.close();
							file3.open("saved.person.data.txt",ios::out);
							Room *curr_ptr=fptr;
							while(curr_ptr!=NULL)
							{

								curr_ptr->getperson(name,cnic,city,mobile_number,age,id);
								file3<<name<<endl<<cnic<<endl<<city<<endl<<mobile_number<<endl<<age<<endl<<id<<endl<<curr_ptr->total_bill<<endl;
								curr_ptr=curr_ptr->nptr;

							}
							file3.close();
							return 0;
						}
		}
		cout<<"Press A to continue\n";
		cin>>s;
		system("CLS");
		if(s=='A')
		continue;
    }
}

void add(Room &r,int opt)
{
	switch(opt)
	{
		case 1:
			{
				r.total_bill=r.total_bill+r.single_breakfast;
				break;
			}
		case 2:
			{
				r.total_bill=r.total_bill+r.single_afternoon;
				break;
			}
		case 3:
			{
				r.total_bill=r.total_bill+r.single_full;
				break;
			}
		case 4:
			{
				r.total_bill=r.total_bill+r.double_breakfast;
				break;
			}
		case 5:
			{
				r.total_bill=r.total_bill+r.double_afternoon;
				break;
			}
		case 6:
			{
				r.total_bill=r.total_bill+r.double_full;
				break;
			}
	}
}

void addmisc(Misc &m,int opt)
{
	switch(opt)
	{
		case 1:
			{
				m.bill=m.bill+m.tea;
				break;
			}
		case 2:
			{
				m.bill=m.bill+m.snacks;
				break;
			}
		case 3:
			{
				m.bill=m.bill+m.laundary;
				break;
			}
		case 4:
			{
				m.bill=m.bill+m.iron;
				break;
			}
		case 5:
			{
				m.bill=m.bill+m.transport;
				break;
			}
		case 6:
			{
				m.bill=m.bill+m.room_service;
				break;
			}
	}
}
