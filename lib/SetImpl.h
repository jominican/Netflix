#ifndef SETIMPL
#define SETIMPL
#include <iostream>
#include <stdexcept>
#include "nsee.h"
#include <vector>

//using namespace std;

template <class T>//constructor
Set<T>::Set()
{
	//listSize=0;
}

template <class T>//constructor
Set<T>::Set (const Set<T> & other):internalStorage(other.internalStorage)//deep copy special syntax
{
	//this->internalStorage = other.internalStorage;
}

template <class T>//deconstructor
Set<T>::~Set()
{

}

template <class T>
int Set<T>::size() const
{
	return this->internalStorage.size();//calling map.size
}

template <class T>
void Set<T>::add(T item)
{
	this->internalStorage.add(item, item);//calling map.add
}

template <class T>
void Set<T>::remove(T item)
{
		this->internalStorage.remove(item);//calling map.remove
}

template <class T>
bool Set<T>::contains(T item) const
{
	return internalStorage.contains(item);//callling map.contain
	
}

template <class T>
void Set<T>::merge(const Set<T> & other)
{
		this->internalStorage.merge(other.internalStorage);//calling map.merge
}

template <class T>
void Set<T>::printSet()
{

	internalStorage.printMapSet();//printMapSet
}

template <class T>
Set<T> Set<T>::setUnion (const Set<T> & other) const
{
	vector<T> A, B;

	Set<T>::Iterator itA, itB;
	Set<T> u;

	for(itA = this->begin(); itA != this->end(); itA++) {
    A.push_back(*itA);
  }

  for(itB = other.begin(); itB != other.end(); itB++) {
    B.push_back(*itB);
  }

	vector<T> sortedA = MergeSort::sort(A);
	vector<T> sortedB = MergeSort::sort(B);

	for(int i=0; i<sortedB.size(); i++){
		sortedA.push_back(sortedB[i]);
	}
	sortedA = MergeSort::sort(sortedA);

	for(int i=0; i<sortedA.size(); i++){
		u.add(sortedA[i]);
	}
	return u;
}

template <class T>
Set<T> Set<T>::setIntersection (const Set<T> & other) const
{
	vector<T> A, B, u;

	Set<T>::Iterator itA, itB;
	Set<T> in;

	for(itA = this->begin(); itA != this->end(); itA++) {
    A.push_back(*itA);
  }

  for(itB = other.begin(); itB != other.end(); itB++) {
    B.push_back(*itB);
  }

	vector<T> sortedA = MergeSort::sort(A);
	vector<T> sortedB = MergeSort::sort(B);

	for(int i=0,j=0; i<sortedA.size()&&j<sortedB.size();){
		if(sortedA[i] == sortedB[j]){
			u.push_back(sortedA[i]);
			i++;
			j++;
		}
		else if(sortedA[i] > sortedB[j]){
			j++;
		}
		else{
			i++;
		}	
	}
	for(int i=0; i<u.size(); i++){
		in.add(u[i]);

	}
	return in;

}

template <class T>
T Set<T>::Iterator::operator*() const{
  Pair<T, T> pair = *internalIterator;
  return pair.first;
}

template <class T>
typename Set<T>::Iterator Set<T>::Iterator::operator++(){
  ++internalIterator;
  return *this;
}

template <class T>
typename Set<T>::Iterator Set<T>::Iterator::operator++(int dummy){
	dummy = 0;
	Set<T>::Iterator si(internalIterator);	
	++(*this);
	return si;
}

template <class T>
typename Set<T>::Iterator Set<T>::Iterator::operator=(const Set<T>::Iterator & other){
	this->internalIterator = other.internalIterator;
  return *this;
}

template <class T>
bool Set<T>::Iterator::operator==(const Set<T>::Iterator & other) const{
  return (this->internalIterator == other.internalIterator);
}

template <class T>
bool Set<T>::Iterator::operator!=(const Set<T>::Iterator & other) const{
  return (this->internalIterator != other.internalIterator);
}

template<class T>
Set<T>::Iterator::Iterator(const typename Map<T, T>::Iterator mi) : internalIterator(mi) {
  
}

template<class T>
Set<T>::Iterator::Iterator() {
}

template <class T>
typename Set<T>::Iterator Set<T>::begin() const{
  Set<T>::Iterator si(internalStorage.begin());
  return si;
}

template <class T>
typename Set<T>::Iterator Set<T>::end() const{
  Set<T>::Iterator si(internalStorage.end());
  return si;
}

template <class T>
Set<T> & Set<T>::operator = (const Set<T>& otherSet){

	if(this == &otherSet){//uses = operator from map
		return *this;
	}
	this->internalStorage = otherSet.internalStorage;

	this->listSize = otherSet.listSize;//also copy the listSize

	return *this;
}


#endif
