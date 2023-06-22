#ifndef ROOM_H
#define ROOM_H
#include<Person.h>

class Room:public Person
{
	public:
		int single_breakfast=2500,single_afternoon=4000,single_full=6000;
		int double_breakfast=3000,double_afternoon=6000,double_full=9000;
		Room *nptr;
		void displayroom_expense();
        friend void add(Room &,int);
};


#endif // ROOM_H
