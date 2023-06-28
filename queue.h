#ifndef DYN_QUE_H
#define DYN_QUE_H
#include <iostream>
using namespace std;

template <class T>
class Dynque
{
  private:
    struct QueueNode
    {
      T instruction;
      QueueNode *next;
    };
    QueueNode *front;
    QueueNode *rear;
    int numItems;

  public:
    Dynque();
    ~Dynque();
    void enqueue(T);
    void dequeue(T &);
    bool isEmpty();
    void clear();
};

//************************************************
// Constructor                                   *
//************************************************

template <class T>
Dynque<T>::Dynque()
{
    front = nullptr;
    rear = nullptr;
    numItems = 0;
}

//************************************************
// Destructor                                    *
//************************************************

template <class T>
Dynque<T>::~Dynque()
{
    clear();
}

//************************************************
// Function enqueue inserts the value in num     *
// at the rear of the queue.                     *
//************************************************

template <class T>
void Dynque<T>::enqueue(T ch)
{
    QueueNode *newNode = nullptr;

    newNode = new QueueNode;
    newNode->instruction = ch;
    newNode->next = nullptr;
    if (isEmpty())
        front = rear = newNode;
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    numItems++;
}

template <class T>
void Dynque<T>::clear()
{
    T value;
    while (!isEmpty())
        dequeue(value);
}

//************************************************
// Function dequeue removes the value at the     *
// front of the queue, and copies it into num.   *
//************************************************

template <class T>
void Dynque<T>::dequeue(T &ch)
{
    QueueNode *temp = nullptr;

    if (isEmpty())
        cout << "No instruction available.\n";
    else
    {
        ch= front->instruction;
        temp = front->next;
        delete front;
        front = temp;
        numItems--;
    }
}

//************************************************
// Function isEmpty returns true if the queue    *
// is empty, and false otherwise.                *
//************************************************

template <class T>
bool Dynque<T>::isEmpty()
{
    bool status = true;

    if (numItems)
    {
        status = false;
    }

    return status;
}

#endif
