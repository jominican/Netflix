#ifndef QUEUE
#define QUEUE
#include <iostream>


template <class T>
struct QueueItem
{
  T item;
  QueueItem<T> *prev, *next;
};

template <class T>
class Queue {
  public:

    Queue();

    ~Queue();

    void enqueue (const T & item);
      /* adds the item to the end of the queue.
         The same item may be added many times. */

    void dequeue (); 
      /* removes the front element of the queue. 
         Throws an EmptyQueueException when called on an empty queue.
         EmptyQueueException should inherit from std::exception. */

    const T & peekFront ();
      /* returns the front element of the queue. 
         Throws an EmptyQueueException when called on an empty queue.
         EmptyQueueException should inherit from std::exception. */

    bool isEmpty ();
      /* returns whether the queue is empty. */

    void printStack();

  private:
     QueueItem <T> *head, *tail;
     int listSize;
};
#include "QueueImpl.h"
#endif