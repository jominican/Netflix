#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include "eqe.h"
#ifndef QUEUEIMPL
#define QUEUEIMPL

using namespace std;

template <class T>
Queue<T>::Queue ()
{
	head = NULL;//setting head and tail to NULL. Listsize to 0
	tail = NULL;
	listSize=0;
}  

template <class T>
Queue<T>::~Queue ()
{
	QueueItem<T> *p = head, *q = NULL;//deconstructing all the StackItem we created
		while (p!= NULL){
		q=p->next;
		delete p;
		p=q;
	}
//	delete q;
}


template <class T>
void Queue<T>::enqueue (const T & item)
{
	QueueItem<T>* newQueueItem = new QueueItem<T>;//create a newStackItem whenever we want to add things
	if (head==NULL){//if list is empty
			head = newQueueItem;//allocating space for a stackitem to be head
			newQueueItem->item = item;
			newQueueItem->next = NULL;
			newQueueItem->prev = NULL;
			tail = newQueueItem;
			listSize++;//increment listSize
	}
	else{//if list is NOT empty
			tail->next = newQueueItem;//the next tail would be the new item
			tail->next->prev = tail;
			newQueueItem->item = item;
			tail = tail->next;
			newQueueItem->next = NULL;//have that newMapItem be the tail or it's next pointer pointing to NULL
			listSize++;//increment listSize
	}
}

template <class T>
void Queue<T>::dequeue()
{
	QueueItem<T>* temp = head;//create a temp QueueItem and point it to head
	//int tempInt = listSize;//create a temp listSize

	if (temp != NULL){//loop through the entire thing while list is not empty
		if(tail == head){//if there are only 1 item, we remove it and set head and tail to NULL. Empty
			head = NULL;
			tail = NULL;
			listSize--;
			delete temp;
		}
		else{//remove current temp that points to head, and shift the head pointer to head-next
			head = head->next;
			head->prev = NULL;
			listSize--;
			delete temp;
		}
	}
	else{
		throw EmptyQueueException("Empty Queue!");//throwing exception
	}
}


template <class T>
const T & Queue<T>::peekFront ()
{
		if(listSize!= 0){
			return head->item;
		}
		else{
			throw EmptyQueueException("Empty Queue!");//throwing exception
		}
}

template <class T>
bool Queue<T>::isEmpty ()
{
	if(listSize>0){//check for listSize
		return false;
	}
	return true;

}
template <class T>
void Queue<T>::printStack()//printing the stack
{
	QueueItem<T>* temp = this->head;
	for (int i=0; i<listSize; i++){//iterate through the map to print out every key and value
  	cout<<temp->item<<endl;
  	temp = temp->next;
  }
  //cout<<listSize<<endl;

}

#endif
