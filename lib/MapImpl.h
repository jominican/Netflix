#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#ifndef MAPIMPL
#define MAPIMPL

using namespace std;

template <class keyType, class valueType>
Map<keyType, valueType>::Map()//constructor
{
	head = NULL;
	listSize = 0;
}

template <class keyType, class valueType>
Map<keyType, valueType>::Map (const Map<keyType, valueType> & other)
{
	this->head = NULL;
	this->tail = NULL;
	this->listSize = 0;

		MapItem<keyType, valueType>* temp = other.head;
		while(temp != NULL){
			this->add(temp->key, temp->value);
			temp = temp->next;
		}
}

template <class keyType, class valueType>
Map<keyType, valueType>::~Map()
{
		MapItem<keyType, valueType> *p = head, *q = NULL;//deconstructing all the MapItem we created
		while (p!= NULL){
		q=p->next;
		delete p;
		p=q;
	}
	//delete q;
//asdf
}

template <class keyType, class valueType>
int Map<keyType, valueType>::size() const
{
		return listSize;//return listSize
}

template <class keyType, class valueType>
void Map<keyType, valueType>::add(keyType key1, valueType value1)
{

	if (head==NULL){
			MapItem<keyType, valueType>* newMapItem = new MapItem<keyType, valueType>;//create a newMapItem whenever we want to add things
			head = newMapItem;
			newMapItem->key = key1;
			newMapItem->value = value1;
			newMapItem->next = NULL;
			newMapItem->prev = NULL;
			listSize++;//increment listSize
	}
	else{//if list is NOT empty
		//check the entire list to see if we have added the same thing
		MapItem<keyType, valueType>* temp = head;

		while(temp->next != NULL ){//if we find a match for what we have already added, output message
			if(temp->key == key1){
				//cout<<"Name already in map"<<endl;
				//delete newMapItem; //how to deallocate this newMapItem?
				return;//exit immediately so we dont do further check
			}
				temp = temp->next;//move to the next node
				
		}
		if(temp->key != key1){//if we do not find a match, we add a newMapItem to the END of the list
			MapItem<keyType, valueType>* newMapItem = new MapItem<keyType, valueType>;//create a newMapItem whenever we want to add things

			//cout << "Added " << key1 << " " << value1 << endl;
			temp->next = newMapItem;
			newMapItem->key = key1;
			newMapItem->value = value1;
			newMapItem->prev = temp;
			newMapItem->next = NULL;//have that newMapItem be the tail or it's next pointer pointing to NULL
			listSize++;//increment listSize
		}

	}

}

template <class keyType, class valueType>
void Map<keyType, valueType>::remove(keyType key1)
{

	MapItem<keyType, valueType>* temp = head;//create a temp MapItem and point it to head
	int tempInt = listSize;//create a temp listSize

	while (temp != NULL){//loop through the entire thing while list is not empty
		if(temp->key == key1){//if a key matches the one we want to remove
		 	if(temp->next != NULL){//check if it is the last item in map
					if (temp == head){//if it is the first item, we just set head to be the next item;
						head = temp->next;
						temp->next->prev = temp->prev;
					}
					else{//if the mapitem to be removed is not the head, we set the temp->next->prev to point to temp->prev, and the other way around as well
						temp->next->prev = temp->prev;
						temp->prev->next = temp->next;
					}
					listSize--;//decrement listSize
					//cout << "Removed " << key1 << endl;
				delete temp;//delete it 
				return;
			}	
			else{//if it is the last item, we just remove it and have temp->prev->next point to NULL 
				//cout<<"Final item "<<temp->prev<<endl;
				if(temp->prev == NULL){
					//cout << "Removed " << key1 << endl;
					head = NULL;
					listSize--;
					delete temp;
					return;
				}
				else{
					temp->prev->next = NULL;
					//temp = tail;
					//cout << "Removed " << key1 << endl;
					listSize--;
					delete temp;
					return;
				}
			}
		}
		else{
			temp = temp->next;
		}	

	}
	if (tempInt == listSize){//we know the name to be removed is not in the list if the listSize was never decremented
			cout<<"Name was not in map"<<endl;
	}

}

template <class keyType, class valueType>
void Map<keyType, valueType>::remove()
{
	MapItem<keyType, valueType>* temp = head;//create a temp MapItem and point it to head
	int tempInt = listSize;//create a temp listSize

	while (temp != NULL){//loop through the entire thing while list is not empty
		// if(temp->key == key1){//if a key matches the one we want to remove
		 	if(temp->next != NULL){//check if it is the last item in map
					if (temp == head){//if it is the first item, we just set head to be the next item;
						head = temp->next;
						temp->next->prev = temp->prev;
					}
					else{//if the mapitem to be removed is not the head, we set the temp->next->prev to point to temp->prev, and the other way around as well
						temp->next->prev = temp->prev;
						temp->prev->next = temp->next;
					}
					listSize--;//decrement listSize
					//cout << "Removed " << key1 << endl;
				delete temp;//delete it 
				return;
			}	
			else{//if it is the last item, we just remove it and have temp->prev->next point to NULL 
				//cout<<"Final item "<<temp->prev<<endl;
				if(temp->prev == NULL){
					//cout << "Removed " << key1 << endl;
					head = NULL;
					listSize--;
					delete temp;
					return;
				}
				else{
					temp->prev->next = NULL;
					//temp = tail;
					//cout << "Removed " << key1 << endl;
					listSize--;
					delete temp;
					return;
				}
			}
		// }
		// else{
		// 	temp = temp->next;
		// }	

	}
	if (tempInt == listSize){//we know the name to be removed is not in the list if the listSize was never decremented
			//cout<<"Name was not in map"<<endl;
	}
}

template <class keyType, class valueType>
valueType & Map<keyType, valueType>::get (const keyType & key1)
{

	MapItem<keyType, valueType>* temp = head;
	while (temp != NULL){//loop through the entire thing and check if the key is equal to the key we are trying to find
		if(temp->key == key1){
			return temp->value;
		}
		
		temp = temp->next;
	}
	
		throw NoSuchElementException("No Such Element Exist!");

}

template <class keyType, class valueType>
void Map<keyType, valueType>::merge(const Map<keyType, valueType> & other)
{

	MapItem<keyType, valueType>* thisTemp = this->head;//don't really need this, but whatever
	MapItem<keyType, valueType>* otherTemp = other.head;
	while (otherTemp != NULL){//loop through other map
	 	while (thisTemp != NULL){//;oop through this map
	 		if (otherTemp->key == thisTemp->key){//if a key in other map equals a key in this map
	 			thisTemp->value = thisTemp->value;//do nothing
	 		}
	 		else{//otherwise, we add this key and its value in other map to this map
	 			this->add(otherTemp->next->key, otherTemp->next->value);
	 		}
	 		thisTemp  = thisTemp->next;
	 	}
	 	this->add(otherTemp->key, otherTemp->value);
	 	otherTemp = otherTemp->next;
	 }
    

}


template <class keyType, class valueType>
void Map<keyType, valueType>::printMap()
{
	MapItem<keyType, valueType>* temp = this->head;
	for (int i=0; i<this->size(); i++){//iterate through the map to print out every key and value
  	cout<<temp->key<<" "<<temp->value<<endl;
  	temp = temp->next;
  }
  //cout<<listSize<<endl;

}

template <class keyType, class valueType>
void Map<keyType, valueType>::printMapSet()//function for printing JUST the key
{
	MapItem<keyType, valueType>* temp = this->head;
	for (int i=0; i<this->size(); i++){
  	cout<<temp->value<<endl;
  	temp = temp->next;
  }
  //cout<<listSize<<endl;
}


template <class keyType, class valueType>
Pair<keyType, valueType> Map<keyType, valueType>::Iterator::operator*() const{
	Pair<keyType, valueType> pair(this->curr->key, this->curr->value);
	return pair;
}

template <class keyType, class valueType>
typename Map<keyType, valueType>::Iterator Map<keyType, valueType>::Iterator::operator++(){
	curr = curr->next;
	return (*this);
}

template <class keyType, class valueType>
typename Map<keyType, valueType>::Iterator Map<keyType, valueType>::Iterator::operator++(int dummy){
	dummy = 0;
	Map<keyType, valueType>::Iterator mi(WhoIBelongTo, curr);	
	++(*this);
	return mi;
}

template <class keyType, class valueType>
typename Map<keyType, valueType>::Iterator Map<keyType, valueType>::Iterator::operator=(const Map<keyType,valueType>::Iterator & other){
	if(*this == other){
		return *this;
	}
	this->curr = other.curr;
	this->WhoIBelongTo = other.WhoIBelongTo;
	return *this;
}


template <class keyType, class valueType>
bool Map<keyType, valueType>::Iterator::operator==(const Map<keyType,valueType>::Iterator & other) const{
	return ((curr == other.curr) && (WhoIBelongTo == other.WhoIBelongTo));
}

template <class keyType, class valueType>
bool Map<keyType, valueType>::Iterator::operator!=(const Map<keyType,valueType>::Iterator & other) const{
	return !(*this == other);
}

template<class keyType, class valueType>
Map<keyType, valueType>::Iterator::Iterator(const Map<keyType, valueType>* w, MapItem<keyType, valueType>* l) {
  this->WhoIBelongTo = w;
  this->curr = l;
}

template<class keyType, class valueType>
Map<keyType, valueType>::Iterator::Iterator() {
  this->WhoIBelongTo = NULL;
  this->curr = NULL;
}


template <class keyType, class valueType>
typename Map<keyType, valueType>::Iterator Map<keyType, valueType>::begin() const{
	Map<keyType, valueType>::Iterator mi(this, head);
	return mi;
}

template <class keyType, class valueType>
typename Map<keyType, valueType>::Iterator Map<keyType, valueType>::end() const{
	Map<keyType, valueType>::Iterator mi(this, NULL);
	return mi;
}

template <class keyType, class valueType>
Map<keyType, valueType> & Map<keyType, valueType>::operator = (const Map<keyType, valueType>& otherMap){

	MapItem<keyType, valueType>* temp = otherMap.head;
	if(this == &otherMap){//if they are equal
		return *this;
	}
	while (this->head != NULL){//while this doenst point to null
		//cout<<this->head<<endl;
		this->remove(this->head->key);//remove everything in this
	}
	//delete this->key;
	for(int i=0; i<otherMap.size(); i++){//iterate through other
		this->add(temp->key, temp->value);//add everything to this
		temp = temp->next;
	}
	return *this;
}

template <class keyType, class valueType>
bool Map<keyType, valueType>::contains(keyType key1) const
{

	MapItem<keyType, valueType>* temp = head;
	while (temp != NULL){//loop through the entire thing and check if the key is equal to the key we are trying to find
		if(temp->key == key1){//basically the same as get
			return true;
		}
		
		temp = temp->next;
	}
		return false;
		//throw NoSuchElementException("No Such Element Exist!");
}

#endif