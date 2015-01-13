#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include "Movie.h"


using namespace std;

Movie::Movie (string title)
{
	this->theTitle = title;
	this->price = 0;
}  

    
Movie::Movie (const Movie & other): movies(other.movies)
{
	///this->movies.merge(other.movies);
	cout<<"Deep Copy"<<endl;
} 

Movie::~Movie ()
{

}

string Movie::getTitle () const
{
	return theTitle;

}

double Movie::getPrice () const
{
	return price;

}


void Movie::addKeyword (string keyword)
{
	movies.add(keyword);//calling map add
}

void Movie::addPrice (double p)
{
	price = p;//calling map add
}
     
Set<string> Movie::getAllKeywords () const
{
	Set<string> temp = movies;
	return temp;
}

//#endif