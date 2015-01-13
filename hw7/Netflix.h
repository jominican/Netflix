#ifndef NETFLIX_H
#define NETFLIX_H

#include <string>
#include <locale>         // std::locale, std::tolower
#include <string.h>
#include "../lib/Map.h"
#include "../lib/Set.h"
#include "../Movie.h"
#include "../User.h"
#include "../lib/nsee.h"
#include "../lib/eqe.h"
#include "../lib/MergeSort.h"
#include "../lib/Queue.h"
#include "../lib/trie.h"

#include <QString>

#include <fstream>
#include <string.h>
#include <cstring>
#include <sstream>
#include <stdexcept>
#include <vector>

class Netflix //class for implementation
{
	public:
		Netflix(int argc, char* argv[]);//constructor for checking command line input
		//Netflix();//constructor without arguements
		~Netflix();
		string DisplayMessageDigest(unsigned *message_digest);
	//login window
		bool loginIn(string login, string password);//log in for user
		void quit();//quit the program
	//new user window
		bool confirm(string login, string name, string password, string address, string card);//createa  new user
		void cancel();//cancel creating a new user
	//main window
		QString Name();//return the user name
		QString ID();//return the user's ID
		void setName(string n);//setting the user's name
		void setID(string n);//setting the user's ID
		QString getCurrentMovieLabel();//returns the current movie title that is checked out
		QString getCurrentQueueLabel();//returns the current queue that is at the top
		QString getCurrentPriceLabel();//returns the current queue that is at the top
		bool returnMovie();//return the movie
		int rentMovie();//rent the movie
		bool deleteFromQueue();//delete the movie fmor queue
		bool moveToBack();//move a movie to the back of queue
		bool searchByTitle(string title);//searching a movie by title
		int searchByKeyword(string title);//searching a movie by keyword
		int searchByActor(string title);
		bool needsRating();
		bool changingPassword(string changed);
		double calculateSimilarity();
	//rating window
		void one();
		void two();
		void three();
		void four();
		void five();
	//queue window
		QString getCurrentMovieTitleLabel();//get the current movie title label for the queue display when searched by title
		QString getCurrentMovieTitleLabel2();//get the current movie title label for the queue display when searched by keyword
		QString getCurrentMovieTitleLabel3();//get the current movie title label for the  display when trying to rate
		void setIterator();//set the start of the iterator
		void mapIterator();
		void addToMyQueue();//add to queue for search by title
		void addToMyQueue2();//add to queue for search by keyword
		QString next();//return the text when we want to see the next movie
		QString next2();//return the text when we want to see the next movie
		int setNumKeywords();//sets the number of keywords in a movie
		int numKeywords();//returns the number of keywords in a movie
		Set<string> getAllKeywords();//return a set of all the keywords when serach by title
		Set<string> getAllKeywords1();//return a set of all the keywords when searched by keyword (version 1)
		Set<string> getAllKeywords2();//return a set of all the keywords when searched by keyword (version 2)

	private:

		Map<string, Movie*> lowercaseMovieTitle;// Maps and Sets of Users, keywords, Movies
		Map<string, User*> userInfo;
		Map<string, Movie*> movieInfo;
		Map<string, Set<Movie*>* > mapKeywords;
		Map<string, Set<Movie*>* > mapActors;
		Map<string, string> passwordInfo;		

		string name; //useful private variables that store some data
		string movieTitle;
		string movieTitle1;
		string keyword;
		string getName;
		string getID;
		string lala;
		string filenames1;
		string current;

		Movie* currentMovie;
		Movie* currentMovie2;

		int size;

		bool flag;

		Map<Movie*, int> *temp;
		Map<Movie*, int>::Iterator mapIter;
		Set<Movie*> *tempMapKeyWords; //iterators variables
		Set<Movie*>::Iterator setIter;





};

#endif