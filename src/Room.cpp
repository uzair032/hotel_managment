#include "Room.h"
#include<iostream>
void Room::displayroom_expense()
{
			cout<<"Room Charges*\nThere are two types of rooms\n";
			cout<<"**\n";
			cout<<"Single room\t\t"<<"Price"<<endl;
			cout<<"1.With break fast\tRs: "<<this->single_breakfast<<"\n2.With Lunch\t\tRs: "<<this->single_afternoon<<"\n3.With Dinner\t\tRs: "<<this->single_full<<endl;
		    cout<<"**\n";
			cout<<"Double room\t\t"<<"Price"<<endl;
			cout<<"4.With break fast\tRs: "<<this->double_breakfast<<"\n5.With Lunch\t\tRs: "<<this->double_afternoon<<"\n6.With Dinner\t\tRs: "<<this->double_full<<endl;
}
