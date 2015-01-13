#include <cstdlib>
#include <iostream>
#include <string>
#include <stdexcept>
#ifndef HASHIMPL
#define HASHIMPL


using namespace std;

template <class keyType, class valueType>
Hash<keyType, valueType>::Hash(){
	for(int i=0; i<size; i++){
		HashTable[i] = new HashItem;
		HashTable[i]->key = NULL;
		HashTable[i]->value = NULL;
		HashTable[i]->next = NULL;
	}
}


template <class keyType, class valueType>
int Hash<keyType, valueType>::Hash(keyType key){
	int hash = 0;
	int index;

	index = key.length();
	return index;
}

template <class keyType, class valueType>
void Hash<keyType, valueType>::add(keyType key1, valueType value1)
{
	int index = Hash(key1);

	if(HashTable[index]->key == NULL){
		HashTable[index]->key = key1;
		HashTable[index]->value = value1;
	}
	else{
		HashItem* ptr = HashTable[index];
		HashItem* newHashItem = new HashItem;
		newHashItem->key = key1;
		newHashItem->value = value1;
		newHashItem->next = NULL;
		while(ptr->next != NULL){
			ptr = ptr->next;
		}
		ptr->next = newHashItem;
	}
}

template <class keyType, class valueType>
void Hash<keyType, valueType>::printTable()
{
	HashItem<keyType, valueType>* temp = this->next;
	for (int i=0; i<size; i++){//iterate through the map to print out every key and value
  	cout<<temp->key<<" "<<temp->value<<endl;
  	temp = temp->next;
  }
}

template <class keyType, class valueType>
valueType & Hash<keyType, valueType>::get (const keyType & key1)
{
	int index = Hash(key1);
	bool found = false;
	valueType v;

	HashItem* ptr = HashTable[index];
	while(ptr != NULL){
		if(ptr->key == key1){
			found = true;
			v = ptr->value;
		}
		ptr = ptr->next;
	}
	return v;
}

template <class keyType, class valueType>
bool Hash<keyType, valueType>::contains (const keyType & key1)
{
	int index = Hash(key1);
	bool found = false;
	valueType v;

	HashItem* ptr = HashTable[index];
	while(ptr != NULL){
		if(ptr->key == key1){
			found = true;
			v = ptr->value;
		}
		ptr = ptr->next;
	}
	return found;
}

template <class keyType, class valueType>
void Hash<keyType, valueType>::remove (keyType & key1)
{
	int index = Hash(key1);

	HashItem* ptr;
	HashItem* temp1;
	HashItem* temp2;

	if(HashTable[index]->key == NULL){
		throw NoSuchElementException("No Such Element Exist!");
	}
	else if(HashTable[index]->key == key1){
		ptr = HashTable[index];
		HashTable[index] = HashTable[index]->next;
		delete ptr;
	}
	else{
		temp1 = HashTable[index]->next;
		temp2 = HashTable[index];

		while(temp1 != NULL && temp1->key != key1){
			temp2 = temp1;
			temp1 = temp1->next;
		}

		if(temp1 == NULL){
			throw NoSuchElementException("No Such Element Exist!");		}
		}

		else{
			ptr = temp1;
			temp1 = temp1->next;
			temp2->next = temp1;

			delete ptr;
		}
	}

}