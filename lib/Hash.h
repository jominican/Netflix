#ifndef HASH
#define HASH
#include <iostream>
#include "nsee.h"

template <class keyType, class valueType>
struct HashItem{
	keyType key;
	valueType value;
	HashItem<keyType, valueType>* next
};


template <class keyType, class valueType>
class Hash{
	public:
		Hash();
		~Hash();
		int Hash(keyType key);
		void add(keyType key1, valueType value1);
		void printTable();
		valueType & get (const keyType & key1);
		bool contains (const keyType & key1);
		void remove (keyType key1);
	private:
		HashItem<keyType, valueType>* HashTable[size];
		static const int size = 100;

};
#include "HashImpl.h"
#endif