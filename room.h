#ifndef ROOM_H
#define ROOM_H
#include "linkedList.h"
#include "item.h"
#include "mission.h"

using namespace std;

class Room
{
    private:
        string name;
        string description;
        Mission mission;
        LinkedList items;    //items yang ada dalam room
        Room* north=nullptr;
        Room* south=nullptr;
        Room* east=nullptr;
        Room* west=nullptr;
    public:
        Room(string roomName,string roomDesc, Mission &roomMission)
            {
                name=roomName;
                description=roomDesc;
                mission=roomMission;
            }

        ~Room(){}
        string getName() const
        {
            return name;
        }
        string getDesc() const
        {
            return description;
        }
        void printRoomDetails() const
        {
            cout<<"You're right now in "<<getName()<<"."<<endl;
            cout<<getDesc()<<endl;
            cout<<endl;
        }

        void addItem(const Item& item)
        {
            items.appendNode(item);
        }
        void setNeighbour(Room *room, const string &direction)
        {
            if(direction=="north")
                north=room;
            else if(direction=="south")
                south=room;
            else if(direction=="east")
                east=room;
            else if(direction=="west")
                west=room;
        }
        Room* getNorth() const {
        return north;
    }

    Room* getSouth() const {
        return south;
    }

    Room* getEast() const {
        return east;
    }

    Room* getWest() const {
        return west;
    }
        Mission& readMission() {
        return mission;
    }
        LinkedList& getItems()
        {
            return items;
        }

};
#endif
