#ifndef PLAYER_H
#define PLAYER_H
#include "linkedList.h"
#include "stack.h"
#include "item.h"
#include "room.h"

using namespace std;

class LinkedList;

class Player
{
    private:
        Room *currentRoom;
        LinkedList inventory;
        DynIntStack actions;
        LinkedList savedGames;
    public:
        Player();
        Player(Room *startingPtrRoom)
        {
            currentRoom=startingPtrRoom;
        }

        void addToInventory(LinkedList &itemList)
        {
            itemList.addAllItemsToInventory(inventory);
        }
        void undoAction()
        {
            string undoAct;
            if (!actions.isEmptyStack()) {
               actions.pop(undoAct);
               cout<<"Action undone :"<<undoAct<<endl;
               actions.displayTop();
             }
        }
        void addAction(string act)
        {
            actions.push(act);
        }
        void showInventory(){
            inventory.display();
        }
        LinkedList& readInventory()
        {
            return inventory;
        }


};
#endif
