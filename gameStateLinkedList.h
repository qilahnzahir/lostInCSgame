#ifndef GAMELINKEDLIST_H
#define GAMELINKEDLIST_H
#include <iostream>
#include <fstream>
#include <string>
#include "gameState.h"

using namespace std;

class GameStateLinkedL
{
  private:
      struct GameStateNode
      {
      GameState* state;
      GameStateNode* next=nullptr;
      };
      GameStateNode* head;

  public:
  GameStateLinkedL()
  {
     head=nullptr;
  }
  ~GameStateLinkedL() { };
  void savedGame(GameState* state) {
        GameStateNode* newNode = new GameStateNode;
        newNode->state = state;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
        } else {
            GameStateNode* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        cout<<"Game saved";
    }
    GameState* loadGame() {
        if (head == nullptr)
        {
            cout<<"\nThe previous game do not saved yet";
        }
        else
        {
            GameStateNode* current = head;

            while (current->next != nullptr)
            {
                current = current->next;
            }
            return current->state;
        }
        return nullptr;
     }


};


#endif
