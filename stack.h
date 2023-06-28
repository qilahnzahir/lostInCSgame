#ifndef STACK_H
#define STACK_H
#include<iostream>
#include<string>
using namespace std;

class DynIntStack
{
  private :
      struct StackNode
      {
        string action;
        StackNode *next;
      };
      StackNode *stackTop;
  public :
     DynIntStack ()
     {
       stackTop=nullptr;
     }
     ~ DynIntStack ()
     {
        StackNode *nodePtr = nullptr, *nextNode = nullptr;
        // Position nodePtr at the top of the stack.
        nodePtr = stackTop;
        //Traverse the list deleting each node.
        while (nodePtr != nullptr)
        {
            nextNode = nodePtr->next;
            delete nodePtr;
            nodePtr = nextNode;
        }
      }
     void push (string a)
      {
          StackNode *newNode =nullptr;
          newNode = new StackNode;

          newNode->action = a;

          if (isEmptyStack())
          {
            stackTop=newNode;
            newNode->next=nullptr;
          }
          else
          {
            newNode-> next =stackTop;
            stackTop = newNode;
          }
      }
     void pop (string &a)
     {
      StackNode *temp = nullptr;

      if (isEmptyStack())
      {
        cout<<"No actions performed yet.\n";
      }
      else
      {
        a = stackTop->action;
        temp = stackTop->next;
        delete stackTop;
        stackTop = temp;
      }
     }
     bool isEmptyStack ()
     {
        bool status;
        if (!stackTop)
         status = true;
        else
         status = false;
        return status;
     }
     void displayTop(){
      if (isEmptyStack())
      {
        cout<<"No actions performed yet.\n";
      }
      else {
        cout<<"Action before is "<<stackTop->action<<endl;}
     }


};
#endif
