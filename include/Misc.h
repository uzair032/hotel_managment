#ifndef MISC_H
#define MISC_H
#include<Room.h>

class Misc:public Room
{
	public:
		int tea=250,snacks=400,laundary=500,iron=800,transport=1000,room_service=500,bill=0;
		void displaymisc();
	    friend void addmisc(Misc &,int);
};

#endif // MISC_H
