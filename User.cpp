#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include "User.h"


using namespace std;

User::User (string ID, string name, string a, string c)
{
	idname = ID;
	username = name;
	address = a;
	card = c;
	charges = 0;
	theQueue = new Queue<Movie*>;//creating a new queue when a user is constructed
	ratings = new Map<Movie*, int>;
	current = NULL;
}

User::User (const User & other)//:username(other.username)
{
	username = other.username;
	idname = other.idname;
	address = other.address;
	card = other.card;
	charges = other.charges;
	theQueue = other.theQueue;

}

User::~User ()
{
	delete theQueue;
}
   
string User::getID () const
{
	return idname;

}   

string User::getName () const
{
	return username;
}

string User::getAddress () const
{
	return address;

}   

string User::getCard () const
{
	return card;
} 

double User::getCharges () const
{
	return charges;
} 

Queue<Movie*> * User::movieQueue ()
{
	return theQueue;
}


Map<Movie*, int> * User::getRatings ()
{
	return ratings;
}

void User::addCharges(double n)
{
	charges = charges + n;
}

void User::addRating (Map<Movie*, int>* rate)
{
	ratings = new Map<Movie*, int>;
}


void User::rentMovie(Movie *m)
{
	current = m;
	// if(current == NULL){
	// 	try{
	// 		current = theQueue->peekFront();
	// 	}catch(const EmptyQueueException& le){}
	// }

}

//create a set current movie

void User::returnMovie()
{
	current = NULL;
}

Movie* User::currentMovie ()
{
	if(current != NULL){
		return current;
	}
	return NULL;
}