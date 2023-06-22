#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include<Person.h>
#include<Room.h>
#include<Employee.h>
#include<Misc.h>
#include<Date.h>

class Functions
{
    public:
    void finish();
    void finish_employee();
    void entry();
    void entry_emp();
    int check_emp(int item_id);
    int check(int item_id);
    int from_string(string);
    void record_person(string name,string cnic,string city,string mobile_number,int age,int d,int m,int y,string bill_file);
    void record_empl();
};

#endif // FUNCTIONS_H
