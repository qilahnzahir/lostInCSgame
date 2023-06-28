#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include "queue.h"
#include "stack.h"
#include "linkedList.h"
#include "room.h"
#include "player.h"
#include "mission.h"
#include "item.h"
#include "gameState.h"
#include "gameStateLinkedList.h"
using namespace std;

int main()
{
    string fileName;
    cout << "Enter your desire file  : " ;
    cin >> fileName;
    ifstream inputFile;
    inputFile.open(fileName);

   int choice;
   char menu, save;
   Dynque<string> queIns;

    GameStateLinkedL gameStatesL;
    GameState* gameState;
    string currentRoom;


    // Create missions for each room
    Mission mission1("Solve the math problem :3 + 2 * 4 - 6 = ?", "5");
    Mission mission2("Arrange these books according the correct order: \n1.Phyton Data Science Handbook (2018)\n2.Starting out with C++ 10th Edition(2022)\n3.Discrete Mathematics for Computer Scientist(1998)\nEnter the arrangement (e.g 123)", "312");
    Mission mission3("Choose the compartment that you think contain key: \nWhite locker(w) \nRed locker(r)\nBlue locker(b)", "b");
    Mission mission4("Find the missing part of this coding: \nint x = 5;\nint* ptr;\n\ncout << Value pointed by ptr: << *ptr ;", "ptr=&x;");
    Mission mission5("Guess any number from 1-10", "9");
    Mission finMission;

    // Create rooms
    Room LecturerRoom("Lecturer's Room", "A room filled with desks and a whiteboard.", mission1);
    Room library("Library", "A quiet room filled with computer science books.", mission2);
    Room tutorialClass("Tutorial Class", "A room with seats and tables and a cupboard with 3 compartment(white,black,blue) where the key may hidden in one of it.", mission3);
    Room computerLab("Computer Lab", "A room with computers and programming books.", mission4);
    Room studentLounge("Student Lounge", "A cozy room with couches and a TV.", mission5);
    Room Door("Door","You can come here after getting all the keys",finMission);

    // Link the rooms together
    LecturerRoom.setNeighbour(&studentLounge, "south");
    LecturerRoom.setNeighbour(&library, "east");

    library.setNeighbour(&tutorialClass, "south");
    library.setNeighbour(&LecturerRoom, "west");

    tutorialClass.setNeighbour(&computerLab, "south");
    tutorialClass.setNeighbour(&library, "north");
    tutorialClass.setNeighbour(&studentLounge, "west");

    computerLab.setNeighbour(&tutorialClass, "north");

    studentLounge.setNeighbour(&tutorialClass, "east");
    studentLounge.setNeighbour(&LecturerRoom, "north");

    // Add items to the rooms
    LecturerRoom.addItem(Item("Key", "Unlocks doors"));
    LecturerRoom.addItem(Item("Torchlight", "Light up the journey"));
    library.addItem(Item("Book", "Contains valuable information"));
    library.addItem(Item("Key", "Unlocks doors"));
    tutorialClass.addItem(Item("Notebook", "Used for taking notes"));
    tutorialClass.addItem(Item("Key", "Unlocks doors"));
    computerLab.addItem(Item("USB Drive", "Stores digital files"));
    computerLab.addItem(Item("Key", "Unlocks doors"));
    studentLounge.addItem(Item("Snack", "Provides a quick energy boost"));

    do{
    cout<<" ------------------------------------------------------------"<<endl;
    cout<<"|  Welcome to Lost in School of Computer Sciences Game       |"<<endl;
    cout<<" ------------------------------------------------------------"<<endl;
    cout<<"|      Map:                                      north       |"<<endl;
    cout<<"|                                           west---|---east  |"<<endl;
    cout<<"|                                                  |         |"<<endl;
    cout<<"|                                                south       |"<<endl;
    cout<<"|                                                            |"<<endl;
    cout<<"|      Lecturer'r Room             Library                   |"<<endl;
    cout<<"|      Student Lounge              Tutorial Class            |"<<endl;
    cout<<"|                                  Computer Lab              |"<<endl;
    cout<<" ------------------------------------------------------------ "<<endl;
    cout<<"     --------      --------------    -------------          "<<endl;
    cout<<"    |Start(1)| or |How To Play(2)|  | Load Game(3)|         "<<endl;
    cout<<"     --------      --------------    -------------          "<<endl;
    cout<<"\nChoice: ";
    inputFile >> choice;
    cout << "Your choice: " << choice << endl;
    cout<<endl;

    if(choice==1)
    {
      queIns.enqueue("                    Oh no you have been trapped in CS School! No worry, don't panic. There is still a hope to find a way out.");
      queIns.enqueue("Now, take a deep breath and try to find 4 keys in the different rooms namely Lecturer Room, Library, Tutorial Class, Computer Lab and Student Lounge.");
      queIns.enqueue("                                  Each rooms has its own mission to complete in order to get the items. ");
      while (!queIns.isEmpty())
      {
        string ch;
        queIns.dequeue(ch);
        cout << ch << endl;
      }

      // Player movement actions
      Room* currentRoom = &studentLounge; // Start in the studentLounge

      Player P(currentRoom);
      cout<<"\n                                                         Your journey is starting now..."<<endl;
      cout<<"\nYou right now in "<<currentRoom->getName()<<"."<<endl;
      cout<<"You need to do the mission in this room."<<endl;
      cout<<"\nPress 'm' for your action later.\n";//instruction
      string action;
      bool actionStatus=true;
      while (actionStatus) {
        cout << "Enter your action (f->forward, b->backward, l->left, r->right, u->use, undo->undo Action, q->quit, k->check key, o->open inventory, m->do mission): ";
        inputFile >> action;
        cout << "Your action: "<< action << endl;

        if (action == "f" || action == "F") {
            P.addAction(action);
            if (currentRoom->getNorth() != nullptr) {
                currentRoom = currentRoom->getNorth();
                cout << "You moved forward to the " << currentRoom->getName() << "." << endl;
                cout<<endl;
                currentRoom->printRoomDetails();}
            else {
                cout << "There is no room in that direction." << endl;}
        }
        else if (action == "b"||action == "B" ) {
            P.addAction(action);
            if (currentRoom->getSouth() != nullptr) {
                currentRoom = currentRoom->getSouth();
                cout << "You moved backward to the " << currentRoom->getName()<< "." << endl;
                cout<<endl;
                currentRoom->printRoomDetails();}
            else {
                cout << "There is no room in that direction." << endl;}
        }
        else if (action == "l"||action == "L") {
            P.addAction(action);
            if (currentRoom->getWest()!= nullptr) {
                currentRoom = currentRoom->getWest();
                cout << "You moved left to the " << currentRoom->getName()<< "." << endl;
                cout<<endl;
                currentRoom->printRoomDetails();}
            else {
                cout << "There is no room in that direction." << endl;}
        }
        else if (action == "r"||action == "R" ) {
            P.addAction(action);
            if (currentRoom->getEast() != nullptr) {
                currentRoom = currentRoom->getEast();
                cout << "You moved right to the " << currentRoom->getName()<< "." << endl;
                cout<<endl;
                currentRoom->printRoomDetails();}
            else {
                cout << "There is no room in that direction." << endl;}
        }
        else if (action == "m"||action == "M" ) {
          if(currentRoom->readMission().isMissionCompleted()){
            cout<<"\nYou have already completed the mission in this room. Please go to another room." << endl;
            cout<<endl;}
          else{
            P.addAction(action);
            cout << "\nCurrent Mission: " << currentRoom->readMission().getMission() << endl;
            int attempt=0;
            string answer;
            do{
              cout << "\nEnter your answer: ";
              inputFile >> answer;
              cout << "Your answer: " << answer << endl;
              attempt++;
                if (currentRoom->readMission().checkAnswer(answer)==1)
                {
                  cout<<"\nGood Job! Your answer is correct. You got the key!"<<endl;
                  cout<<"Open your inventory to look for the special items and total keys you're already got."<<endl;
                  cout<<"Please exit this room."<<endl;
                  cout<<endl;
                  currentRoom->readMission().markMissionCompleted(); //mark that we have complete mission in this room
                  P.addToInventory(currentRoom->getItems());
                  gameState= new GameState(currentRoom,currentRoom->readMission().isMissionCompleted(),P.readInventory());
                  gameStatesL.savedGame(gameState);
                  break;
                }
                else{
                  cout<<"\nYour answer is wrong.Try again..."<<endl;}
              }while(attempt<=3);
              if(attempt==3)
              {
                cout<<"\nYour already use all attempt. Please go to other room first\n";
              }
           }
          }
        else if (action == "o"||action == "O" ) {
            P.addAction(action);
            P.showInventory();
        }
        else if (action == "k"||action == "K" ) {
            P.addAction(action);
            int numKey= P.readInventory().countIn(Item("Key"));//ni pun tak sure
            if(numKey==4){
               cout<<"\nYou already collected all 4 keys.If you want to go to the door, you can go now\n";
               currentRoom = &Door;
               cout<<"\nYou were moved to the " << currentRoom->getName() << "." << endl;
               cout<<"Congratulations! You success to escape the School of Computer Science.\n ";
               cout<<"-----------------------------------------------Game End--------------------------------------------------------------";
               actionStatus=false;
              }
            else{
               cout<<"\nYou do not get all keys yet. Current key: "<<numKey<< "\nPlease continue playing....\n";
               cout<<endl;
               }
        }
        else if (action == "undo"||action == "UNDO" ) {
            P.undoAction();

        }
        else if (action == "u"||action == "U" ) {
            P.addAction(action);
            string itemName;
            cout << "\nEnter the name of the item you want to use: ";
            inputFile >> itemName;
            cout << "Item Name : " << itemName << endl;
            if(itemName=="Key")
            {
              cout<<"\nYou cannot use the key!"<<endl;
            }
            else {
              Item itemToUse(itemName);
              P.readInventory().deleteNode(itemToUse);
              cout<<itemName<<"is not longer in your inventory as you were using it.\n";
            }

        }
        else if (action == "q"||action == "Q" ) {
            P.addAction(action);
            cout << "\nYou quit the game. Goodbye!" << endl;
            cout << "Thank you for playing! Goodbye." << endl;
            actionStatus=false;

        }
        else {
            cout << "\nInvalid action. Please try again." << endl;
        }
      }
    }

    else if(choice==2)
    {
      cout<<"\nHOW TO PLAY "<<endl;
      cout<<" --------------------------------------------------------------------  "<<endl;
      cout<<"|1. F/f: Forward                                                     | "<<endl;
      cout<<"|2. B/b: Backward                                                    | "<<endl;
      cout<<"|3. L/l: Left                                                        | "<<endl;
      cout<<"|4. R/r: Right                                                       | "<<endl;
      cout<<"|5. M/m: Do mission in room                                          | "<<endl;
      cout<<"|6. O/o: Open player inventory                                       | "<<endl;
      cout<<"|7. undo/UNDO: Undo action to the previous one                       | "<<endl;
      cout<<"|8. K/k: To see total number of key in player's inventory            | "<<endl;
      cout<<"|9. U/u: Use                                                        | "<<endl;
      cout<<"|10. Q/q: Quit                                                       | "<<endl;
      cout<<" --------------------------------------------------------------------"<<endl;
    }
    else if(choice==3)
    {
        GameState* loadedState=gameStatesL.loadGame();
        if (loadedState != nullptr) {
        // Update the game state based on the loaded state
        Room* currentRoom = loadedState->getGscurrRoom();
        bool mission1Completed = loadedState->getGsmissionComp();
        LinkedList &inventory= loadedState->getGsInventory();
        Player p(currentRoom);
        p.addToInventory(currentRoom->getItems());
        // Continue the game with the loaded state

        cout << "\nLoaded game state: " << endl;
        cout << "Current Room: " << currentRoom->getName() << endl;
        cout << "Mission Completed: " << (mission1Completed ? "Yes" : "No") << endl;
        cout << "Player's Inventory: ";
        p.showInventory();
        }

    }
    else
    {
      cout<<"Invalid input.";
    }
    cout<<"\nGo back to menu (Y/N): ";
    inputFile>>menu;
    cout << "(Y/N) : " << menu << endl;
    if(menu=='N'||menu=='n')
    {
      return 0;
    }
  }while(menu=='Y'||menu=='y');
    delete gameState;
    return 0;
}
