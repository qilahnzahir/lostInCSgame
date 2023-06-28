#ifndef ITEM_H
#define ITEM_H
#include<iostream>
#include <string>
using namespace std;

class Item
{
	private:
		string name;
		string desc;
	public:
		//Default constructor
		Item(){
			name = "";
			desc = "";

		}
		Item(const string &itemName)
		{
			name=itemName;
		}

		//Constructor overloading use for counting key
		Item(const string &itemName, const string &description)
		{
			name=itemName;
			desc=description;
		}
		string getName() const {
			return name;
		}
		string getDesc() const
		{
			return desc;
		}


};
#endif
