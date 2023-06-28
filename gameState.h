#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <iostream>
#include <fstream>
#include <string>
#include "linkedList.h"
#include "room.h"
#include "item.h"

using namespace std;

class GameState
{
  private:
      Room* currentRoom;
      LinkedList playerInventory;
      bool mission1Completed;

  public:
      GameState(Room* currRoom,bool mission1,const LinkedList& inventory)
      {
        currentRoom=currRoom;
        mission1Completed=mission1;
        playerInventory = inventory;
      }

      LinkedList& getGsInventory()
      {
            return playerInventory;
      }
      Room* getGscurrRoom()
      {
            return currentRoom;
      }
      bool getGsmissionComp()
      {
            return mission1Completed;
      }


};


#endif
