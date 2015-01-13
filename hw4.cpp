#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <stdexcept>
#include <locale>         // std::locale, std::tolower
#include "lib/Map.h"
#include "lib/Set.h"
#include "Movie.h"
#include "User.h"
#include "lib/nsee.h"
#include "lib/eqe.h"
#include "lib/MergeSort.h"
#include "lib/Queue.h"
#include <vector>


/*
 *  shatest.cpp
 *
 *  Copyright (C) 1998, 2009
 *  Paul E. Jones <paulej@packetizer.com>
 *  All Rights Reserved
 *
 *****************************************************************************
 *  $Id: shatest.cpp 12 2009-06-22 19:34:25Z paulej $
 *****************************************************************************
 *
 *  Description:
 *      This file will exercise the SHA1 class and perform the three
 *      tests documented in FIPS PUB 180-1.
 *
 *  Portability Issues:
 *      None.
 *
 */

#include "lib/sha1/sha1.h"

using namespace std;

/*
 *  Define patterns for testing
 */
#define TESTA   "abc"
#define TESTB   "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq"

/*
 *  Function prototype
 */
int DisplayMessageDigest(unsigned *message_digest);

/*  
 *  main
 *
 *  Description:
 *      This is the entry point for the program
 *
 *  Parameters:
 *      None.
 *
 *  Returns:
 *      Nothing.
 *
 *  Comments:
 *
 */

/*  
 *  DisplayMessageDigest
 *
 *  Description:
 *      Display Message Digest array
 *
 *  Parameters:
 *      None.
 *
 *  Returns:
 *      Nothing.
 *
 *  Comments:
 *
 */
int DisplayMessageDigest(unsigned *message_digest)
{
    ios::fmtflags   flags;

    //cout << '\t';

    flags = cout.setf(ios::hex|ios::uppercase,ios::basefield);
    cout.setf(ios::uppercase);
	int x=0;
    for(int i = 0; i < 5 ; i++)
    {
        x += message_digest[i];
    }
	return x;
    cout << endl;

    //cout.setf(flags);
}

//using namespace std;

string filenames1 ="";
//prototyping
void menu(Map<string, User*> userInfo, Map<string, Movie*> movieInfo, Map<string, Set<Movie*>* > mapKeywords, Map<string, Movie*> lowercaseMovieTitle);//prototyping
void menu2(Map<string, User*> userInfo, Map<string, Movie*> movieInfo, Map<string, Set<Movie*>* > mapKeywords, Map<string, Movie*> lowercaseMovieTitle, string name);
void menu3(Map<string, User*> userInfo, Map<string, Movie*> movieInfo, Map<string, Set<Movie*>* > mapKeywords, Map<string, Movie*> lowercaseMovieTitle, string keyword, string name);
void menu4(Map<string, User*> userInfo, Map<string, Movie*> movieInfo, Map<string, Set<Movie*>* > mapKeywords, Map<string, Movie*> lowercaseMovieTitle, string name);

void menu(Map<string, User*> userInfo, Map<string, Movie*> movieInfo, Map<string, Set<Movie*>* > mapKeywords, Map<string, Movie*> lowercaseMovieTitle){//the first menu display
	ofstream userFile;
	// userFile.open("data/user.txt", fstream::app);//writing to user.txt
	userFile.open(filenames1, std::ofstream::out | std::ofstream::trunc);//clearing the file
	int input;
	string login, name;
	bool passed = true, passed2 = true;

		cout<<"1. Log in"<<endl;
		cout<<"2. Create a new user"<<endl;
		cout<<"3. Quit"<<endl;

	while (true){//interaction with user
		cin>>input;

		if(input == 1){
			cout<<"Enter your login: "<<endl;
			cin>>login;
	    if(!(userInfo.contains(login))){
        passed = false;
	    }
			if(passed){//If user can log in, we can continue to menu2
				menu2(userInfo, movieInfo, mapKeywords, lowercaseMovieTitle, login);
			}
			else{//otherwise, we prompt them to try a different option
				cout<<"No User Found! Try Again"<<endl;
				cout<<"1. Log in"<<endl;
				cout<<"2. Create a new user"<<endl;
				cout<<"3. Quit"<<endl;
				passed = true;
				cin.clear();
				cin.ignore(10000, '\n');
			}
		}
		else if(input == 2){//this is for creating a new user
			while(passed2){
				cout<<"What ID do you want? "<<endl;
				cin>>login;
		   	if(!(userInfo.contains(login))){//if the userInfo map has the ID, we output User Exist, otherwise, the user can choose a ID and name
		   		passed2 = false;
		   	}
	      if(passed2 == true){
	      	cout<<"User Already Exists! Enter another ID"<<endl;
	      	cin.clear();
	      	cin.ignore(10000, '\n');
	      }
    	}
      	cout<<"User ID is valid. Enter your name"<<endl;
				getline(cin, name);
				getline(cin, name);
      	User* newUser = new User(login, name);//allocating memory for new ID/NAME
      	userInfo.add(login, newUser);
      	menu(userInfo, movieInfo, mapKeywords, lowercaseMovieTitle);
		}
		else if(input == 3){//when the user quits the program, all the information is written back to the file
			userFile.clear();
			for(Map<string, User*>::Iterator userIter = userInfo.begin(); userIter != userInfo.end(); userIter++) {
      	Pair<string, User*> item = *userIter;
      	User *userList = item.second;
      	userFile<<"BEGIN "<<userList->getID()<<endl;
	      userFile<<"NAME: "<<userList->getName()<<endl;
	      if(userList->currentMovie() != NULL){
	     		userFile<<"MOVIE: "<<userList->currentMovie()->getTitle()<<endl;
	     	}
	     	userFile<<"BEGIN QUEUE "<<endl;
	     	while(!(userList->movieQueue()->isEmpty())){
	     		userFile<<userList->movieQueue()->peekFront()->getTitle()<<endl;
	     		userList->movieQueue()->dequeue();
	     	}
	     	userFile<<"END QUEUE "<<endl;
	      userFile<<"END"<<endl;
      }
	    exit(0);
	  }
		else{
			cout<<"Enter a proper choice"<<endl;
      cin.clear();
      cin.ignore( 10000, '\n' );
		}

	}
}

void menu2(Map<string, User*> userInfo, Map<string, Movie*> movieInfo, Map<string, Set<Movie*>* > mapKeywords, Map<string, Movie*> lowercaseMovieTitle, string login){//menu display 2
	string title, keyword;
	int input, input2;
	bool passed = true;
	bool passed2 = true;
	bool passed3 = true;
	if(userInfo.get(login)->currentMovie()){	
		cout<<"The current movie checked out is: "<<userInfo.get(login)->currentMovie()->getTitle()<<endl;
	}
	else{
		cout<<"There are no movie checked out"<<endl;
	}
	cout<<"1. Search for a movie by title"<<endl;
	cout<<"2. Search for a movie by keyword"<<endl;
	cout<<"3. Return the current movie"<<endl;
	cout<<"4. View Queue"<<endl;
	cout<<"5. Logout"<<endl;


	while (true){
		cin>>input;

		if(input == 1){//option 1, searching for movie by title
			cout<<"Enter the title: "<<endl;
			getline(cin, title);
			getline(cin, title);
			locale loc;
	  	string str=title;
	  	string meow;
	  	for (std::string::size_type i=0; i<str.length(); ++i)//this will convert the user input to lowercase
	    meow += tolower(str[i],loc);
			if(!(lowercaseMovieTitle.contains(meow))){//if lowercaseMovieTitle contains the title, we will ouptut
        passed = false;
      }
      //cout<<passed<<endl;
			if(passed){
				string temp = lowercaseMovieTitle.get(meow)->getTitle();//outputting the title and all associated keywords of the movie
				cout<<temp<<endl;
				lowercaseMovieTitle.get(meow)->getAllKeywords().printSet();
				cout<<"1. Add movie to queue"<<endl;
				cout<<"2. Return to menu"<<endl;
				while (true){
					cin>>input2;
					if(input2 == 1){
						cout<<temp<<" is added to the queue!"<<endl;
						userInfo.get(login)->movieQueue()->enqueue(lowercaseMovieTitle.get(meow));
						cout<<"1. Add movie to queue"<<endl;
						cout<<"2. Return to menu"<<endl;
					}
					else if(input2 == 2){
						menu2(userInfo, movieInfo, mapKeywords, lowercaseMovieTitle, login);
					}
					else{
						cout<<"Enter a proper choice"<<endl;//the user choice is not recognized
      			cin.clear();
      			cin.ignore( 10000, '\n' );
					}
				}
			}
			else{//no movie found
				cout<<"No Movie Found!"<<endl;
				if(userInfo.get(login)->currentMovie()){	
					cout<<"The current movie checked out is: "<<userInfo.get(login)->currentMovie()->getTitle()<<endl;
				}
				else{
					cout<<"There are no movie checked out"<<endl;
				}
				cout<<"1. Search for a movie by title"<<endl;
				cout<<"2. Search for a movie by keyword"<<endl;
				cout<<"3. Return the current movie"<<endl;
				cout<<"4. View Queue"<<endl;
				cout<<"5. Logout"<<endl;
				passed = true;
				cin.clear();
			}
		}
		else if(input == 2){//option 2 for searching movie by keyword
			cout<<"Enter a keyword or phrase "<<endl;
			getline(cin, keyword);
			getline(cin, keyword);
			locale loc;
	  	string str2=keyword;
	  	string meow2;
	  	for (std::string::size_type i=0; i<str2.length(); ++i)//convert the keyword input to lowercase
	    meow2 += tolower(str2[i],loc);
	   	if(!(mapKeywords.contains(meow2))){//if mapKeywords contain the keyword, we output the movie and all its information
     		passed2 = false;
      }
 	   	if(!(lowercaseMovieTitle.contains(meow2))){
				passed3 = false;
      }
      if(passed2 == false && passed3 == false){
      	cout<<"No match"<<endl;
			  if(userInfo.get(login)->currentMovie()){	
					cout<<"The current movie checked out is: "<<userInfo.get(login)->currentMovie()->getTitle()<<endl;
				}
				else{
					cout<<"There are no movie checked out"<<endl;
				}
      	cout<<"1. Search for a movie by title"<<endl;
				cout<<"2. Search for a movie by keyword"<<endl;
				cout<<"3. Return the current movie"<<endl;
				cout<<"4. View Queue"<<endl;
				cout<<"5. Logout"<<endl;
      }
			if(passed2){
				cout<<"Number of matches:"<<endl;//show the number of matches with the inputted keyword
				int x = mapKeywords.get(meow2)->size();
				cout<<x<<endl;

		    Set<Movie*> *tempMapKeyWords = mapKeywords.get(meow2);//initializing iterators
				Set<Movie*>::Iterator setIter = tempMapKeyWords->begin();	    

				if(x > 1){
					//mapKeywords.get(meow2)->first();//first displays the first match found, if more than 1 match found, we will go to menu3, otherwise, we stay here
					string temp = (*setIter)->getTitle();
					cout<<temp<<endl;
					(*setIter)->getAllKeywords().printSet();
					menu3(userInfo, movieInfo, mapKeywords, lowercaseMovieTitle, meow2, login);
				}
				else{//staying in menu2 when there is only 1 movie match
					cout<<endl;
					//mapKeywords.get(meow2)->first();
					string temp = (*setIter)->getTitle();
					cout<<temp<<endl;
					(*setIter)->getAllKeywords().printSet();
					cout<<"1. Add movie to queue"<<endl;
					cout<<"2. Return to menu"<<endl;
					while (true){
						cin>>input2;
						if(input2 == 1){
							cout<<temp<<" is added to the queue!"<<endl;
							userInfo.get(login)->movieQueue()->enqueue((*setIter));
							cout<<"1. Add movie to queue"<<endl;
							cout<<"2. Return to menu"<<endl;
						}
						else if(input2 == 2){
							menu2(userInfo, movieInfo, mapKeywords, lowercaseMovieTitle, login);
						}
						else{
							cout<<"Enter a proper choice"<<endl;//the user choice is not recognized
	      			cin.clear();
	      			cin.ignore( 10000, '\n' );
						}
					}
				}
			}
			if(passed3){//reading when the user enters the title as a keyword
				string temp = lowercaseMovieTitle.get(meow2)->getTitle();
				cout<<temp<<endl;
				lowercaseMovieTitle.get(meow2)->getAllKeywords().printSet();
				cout<<"1. Add movie to queue"<<endl;
				cout<<"2. Return to menu"<<endl;
				while (true){
					cin>>input2;
					if(input2 == 1){
						cout<<temp<<" is added to the queue!"<<endl;
						userInfo.get(login)->movieQueue()->enqueue(lowercaseMovieTitle.get(meow2));
						cout<<"1. Add movie to queue"<<endl;
						cout<<"2. Return to menu"<<endl;
					}
					else if(input2 == 2){
						menu2(userInfo, movieInfo, mapKeywords, lowercaseMovieTitle, login);
					}
					else{
						cout<<"Enter a proper choice"<<endl;//the user choice is not recognized
      			cin.clear();
      			cin.ignore( 10000, '\n' );
					}
				}

				//add stuff here
			}
		passed3 = true;
		passed2 = true;			
		}
		else if(input == 3){//option 3 for returning the current checkout movie
			if(userInfo.get(login)->currentMovie()){
				cout<<userInfo.get(login)->currentMovie()->getTitle()<<" has been returned"<<endl;
				userInfo.get(login)->returnMovie();
				cout<<"1. Search for a movie by title"<<endl;
				cout<<"2. Search for a movie by keyword"<<endl;
				cout<<"3. Return the current movie"<<endl;
				cout<<"4. View Queue"<<endl;
				cout<<"5. Logout"<<endl;
			}
			else{
				cout<<"There is no movie to return"<<endl;
				cout<<"1. Search for a movie by title"<<endl;
				cout<<"2. Search for a movie by keyword"<<endl;
				cout<<"3. Return the current movie"<<endl;
				cout<<"4. View Queue"<<endl;
				cout<<"5. Logout"<<endl;
			}
		}
		else if (input == 4){//option 4 for viewing the queue
			try{
				cout<<userInfo.get(login)->movieQueue()->peekFront()->getTitle()<<endl;
			}catch(const EmptyQueueException& le){cout<<"Movie Queue Empty!"<<endl;}
			menu4(userInfo, movieInfo, mapKeywords, lowercaseMovieTitle, login);
		}
		else if(input == 5){//option 5 for logging out
			menu(userInfo, movieInfo, mapKeywords, lowercaseMovieTitle);
		}
		else{
			cout<<"Enter a proper choice"<<endl;//the user choice is not recognized
      cin.clear();
      cin.ignore( 10000, '\n' );
		}

	}


}

void menu3(Map<string, User*> userInfo, Map<string, Movie*> movieInfo, Map<string, Set<Movie*>* > mapKeywords, Map<string, Movie*> lowercaseMovieTitle, string keyword, string login)//menu 3 display
{
	int input;
	int lastCount = 2;
	bool passed = true;
	string temp;
  Set<Movie*> *tempMapKeyWords = mapKeywords.get(keyword);//initializing the iterators
	Set<Movie*>::Iterator setIter = tempMapKeyWords->begin();	  
	while(true){

			if(passed){//if there are next movies to view with the same keywords
				cout<<"1. Next Movie"<<endl;
				cout<<"2. Add movie to queue"<<endl;
				cout<<"3. Return to menu"<<endl;
				cin>>input;
				if(input == 1){
											try{
											setIter++;
											}catch(const NoSuchElementException& le){
		        					passed = false;
		      						}
		     	int	x = mapKeywords.get(keyword)->size();
		     	if(lastCount == x){ //fix this for last item in keywords
		     		passed = false;
		     	}
					//display subsequent movies with keywords
					if(passed){//allow the user to scroll through other movies who have the same keyword until we reach the last movie, in which, there will be no option to look through the next movie
						temp = (*setIter)->getTitle();
						cout<<temp<<endl;
						(*setIter)->getAllKeywords().printSet();
						lastCount++;
					}
				}
				else if(input == 2){
					cout<<"Movie is added to the queue!"<<endl;
					userInfo.get(login)->movieQueue()->enqueue((*setIter));
					//ADD MOVIE TO USER.TXT in QUEUE
				}
				else if(input == 3){//return to the previous menu if user does not wish to see all movies
					menu2(userInfo, movieInfo, mapKeywords, lowercaseMovieTitle, login);
				}
				else{
					cout<<"Enter a proper choice"<<endl;//the user choice is not recognized
		      cin.clear();
		      cin.ignore( 10000, '\n' );
				}
			}
			if(!passed){
				temp = (*setIter)->getTitle();
				cout<<temp<<endl;
				(*setIter)->getAllKeywords().printSet();
				cout<<"1. Add movie to queue"<<endl;
				cout<<"2. Return to menu"<<endl;
				cin>>input;
				if(input == 1){//adding the movie to queue if option 1
					cout<<"Movie is added to the queue!"<<endl;
					userInfo.get(login)->movieQueue()->enqueue((*setIter));					
				}
				else if(input == 2){//return to the menu if option 2
					menu2(userInfo, movieInfo, mapKeywords, lowercaseMovieTitle, login);
				}
				else{
					cin.clear();
					cin.ignore(100000, '\n');
				}
			}
	}
}

void menu4(Map<string, User*> userInfo, Map<string, Movie*> movieInfo, Map<string, Set<Movie*>* > mapKeywords, Map<string, Movie*> lowercaseMovieTitle, string login){ //check for bad input that causes infinite loop
	int input;//the fourth menu for viewing queue
	cout<<"1. Order movie"<<endl;
	cout<<"2. Remove movie from queue"<<endl;
	cout<<"3. Move movie to back of queue"<<endl;
	cout<<"4. Return to user menu"<<endl;

	while(true){
		cin>>input;
		if(input == 1){//option 1, order a movie
			//cout<<userInfo.get(login)->currentMovie()->getTitle()<<endl;
			if(userInfo.get(login)->currentMovie()){
				cout<<"You already have a movie checked out. Please return your current movie before checking out another one"<<endl;
				try{
					cout<<userInfo.get(login)->movieQueue()->peekFront()->getTitle()<<endl;
				}catch(const EmptyQueueException& le){cout<<"Queue is Empty"<<endl;}
			}
			else{
				try{
					userInfo.get(login)->rentMovie(userInfo.get(login)->movieQueue()->peekFront());
					cout<<"You have successfully checkedout "<<userInfo.get(login)->currentMovie()->getTitle()<<endl;
					userInfo.get(login)->movieQueue()->dequeue();
					cout<<userInfo.get(login)->movieQueue()->peekFront()->getTitle()<<endl;
				}catch(const EmptyQueueException& le){
					cout<<"Queue is Empty"<<endl;
				}
			}
			menu4(userInfo, movieInfo, mapKeywords, lowercaseMovieTitle, login);
		}	
		else if(input == 2){//option 2, remove the top movie from queue
			try{
				cout<<userInfo.get(login)->movieQueue()->peekFront()->getTitle()<<" has been removed from your queue!"<<endl;
				userInfo.get(login)->movieQueue()->dequeue();
				cout<<userInfo.get(login)->movieQueue()->peekFront()->getTitle()<<endl;
				menu4(userInfo, movieInfo, mapKeywords, lowercaseMovieTitle, login);
			}catch(const EmptyQueueException& le){cout<<"You have no more movie to remove in queue"<<endl;}
			menu4(userInfo, movieInfo, mapKeywords, lowercaseMovieTitle, login);
		}
		else if(input == 3){//option 3, move the first queue to the back
			try{
				cout<<"Your first movie in queue: "<<userInfo.get(login)->movieQueue()->peekFront()->getTitle()<<" has been moved to the back of the queue"<<endl;
				Movie* temp = userInfo.get(login)->movieQueue()->peekFront();
				userInfo.get(login)->movieQueue()->dequeue();
				userInfo.get(login)->movieQueue()->enqueue(temp);
				cout<<userInfo.get(login)->movieQueue()->peekFront()->getTitle()<<endl;
			}catch(const EmptyQueueException& le){cout<<"You have no movie in queue to move to the back"<<endl;}

			menu4(userInfo, movieInfo, mapKeywords, lowercaseMovieTitle, login);
		}
		else if(input == 4){//option 4, return to the user menu
			menu2(userInfo, movieInfo, mapKeywords, lowercaseMovieTitle, login);
		}
		else{
			cout<<"Enter a proper choice"<<endl;//the user choice is not recognized
      cin.clear();
      cin.ignore( 10000, '\n' );
		}
	}
}

int main(int argc, char *argv[])
{   

	SHA1        sha;
    unsigned    message_digest[5];

    /*
     *  Perform test A
     */
    cout << endl << "Test A: 'abc'" << endl;

    sha.Reset();
    char* test = "abc";
    sha << test;

    if (!sha.Result(message_digest))
    {
        cerr << "ERROR-- could not compute message digest" << endl;
    }
    else
    {
       	int x = DisplayMessageDigest(message_digest);
	cout<<x<<endl;
        cout << "Should match:" << endl;
        cout << '\t' << "A9993E36 4706816A BA3E2571 7850C26C 9CD0D89D" << endl;
    }

    /*
     *  Perform test B
     */
    cout << endl << "Test B: " << TESTB << endl;

    sha.Reset();
    sha << TESTB;

    if (!sha.Result(message_digest))
    {
        cerr << "ERROR-- could not compute message digest" << endl;
    }
    else
    {
     	 int x = DisplayMessageDigest(message_digest);
	cout<<x<<endl;
        cout << "Should match:" << endl;
        cout << '\t' << "84983E44 1C3BD26E BAAE4AA1 F95129E5 E54670F1" << endl;
    }

    /*
     *  Perform test C
     */
    cout << endl << "Test C: One million 'a' characters" << endl;

    sha.Reset();
    for(int i = 1; i <= 1000000; i++) sha.Input('a');

    if (!sha.Result(message_digest))
    {
        cerr << "ERROR-- could not compute message digest" << endl;
    }
    else
    {
        cout<<DisplayMessageDigest(message_digest)<<endl;
        cout << "Should match:" << endl;
        cout << '\t' << "34AA973C D4C4DAA4 F61EEB2B DBAD2731 6534016F" << endl;
    }
	bool passed = true;
	Map<string, Movie*> lowercaseMovieTitle;// Maps and Sets of Users, keywords, Movies
	Map<string, User*> userInfo;
	Map<string, Movie*> movieInfo;
	Map<string, Set<Movie*>* > mapKeywords;	

	int queueSize = 0;


	ifstream file1, file2, file3;//variables for files
	char buffer[100];
	string filenames2, firstWord, secondWord, thirdWord, username, firstName, lastName, user;
	string newMovieTitle, movieTitle, newKeywords, keywords, a, meow3, rentedMovie, queueWord;
	Queue<Movie*> MovieQueue; 
	//string lala = "data/"+argv[1];

	if(argc != 2){
		cout<<"The number of arguements is wrong"<<endl;
		exit(0);
	}

	file1.open(argv[1]);//open the file
	if(!file1.is_open())//check if the file can be opened
	{
  	cout << "The file could not be open. Please enter data/main.txt to properly open the file"<<endl;
  	exit(0);
	}


	else
	{		
		stringstream ss;//abstracting data from the first file, which only has 2 lines
		file1.getline(buffer, 100);
		ss<<buffer;
		ss>>filenames1;
		ss.clear();
		file1.getline(buffer, 100);
		ss<<buffer;
		ss>>filenames2;		

		file2.open(filenames1);
		file3.open(filenames2);
		if(!file2.is_open())//check if the file can be opened
		{
	  	cout << "One of the files could not be opened"<<endl;
	  	exit(0);
		}	
		if(!file3.is_open())//check if the file can be opened
		{
  		cout << "One of the files could not be opened"<<endl;
  		exit(0);
		}
				while(file3.getline(buffer, 100)){//abstracting data from the third file it first file can be opened
					stringstream aa;
					aa<<buffer;
					aa>>firstWord;
					if(firstWord == "BEGIN"){//reading from BEGIN, basically reading the movie title ONLY
						while(aa){
							aa>>a;
							movieTitle = movieTitle + a + " ";
						}
						movieTitle = movieTitle.substr(0,movieTitle.size()-a.size()-2);
						newMovieTitle = movieTitle;
						movieTitle = "";
						Movie* movies = new Movie(newMovieTitle);
						std::locale loc;
				  	string str=newMovieTitle;
				  	string meow;
				  	for (std::string::size_type i=0; i<str.length(); ++i)//converting all keywords to lowercase so it can be useful later
					    meow += tolower(str[i],loc);

						while(file3.getline(buffer, 100)){
							stringstream bb;
							bb<<buffer;
							bb>>secondWord;
							if(secondWord == "KEYWORD:"){//reading from KEYWORD, reading in all the keywords data
								while(bb){
									bb>>a;
									keywords = keywords + a + " ";
								}
								keywords = keywords.substr(0,keywords.size()-a.size()-2);
								newKeywords = keywords;
								std::locale loc;
								string meow2;
						  	string str2=newKeywords;
						  	for (std::string::size_type i=0; i<str2.length(); ++i)
							  meow2 += tolower(str2[i],loc);
								meow3 = meow2;
								keywords = "";
								movies->addKeyword(newKeywords);
								try{
									mapKeywords.get(meow3);
								}catch(const NoSuchElementException& le){
        					passed = false;
								}
								if(!passed){
									Set<Movie*>* temp = new Set<Movie*>;
									temp->add(movies);
									mapKeywords.add(meow3, temp);
								}
								else{
									mapKeywords.get(meow3)->add(movies);
								}
								passed = true;
							}
							else{//we have reached END, so no more data to read for the movie
								movieInfo.add(newMovieTitle, movies);//adding the movie information to movieInfo map when we read in each user fmor user.txt
								lowercaseMovieTitle.add(meow, movies);//adding the lowercase movie information to lowercaseMovieTitle map when we read in each user fmor user.txt
								break;
							}
						bb.clear();//clearing stringstream
						}
					}					
					aa.clear();
				}
				while(file2.getline(buffer, 100)){//abstracting data from the second file if first file can be opened
					stringstream cc;
					cc<<buffer;
					cc>>firstWord;
					string temp = buffer;
					if(firstWord == "BEGIN"){//Read in the BEGIN QUEUE line
						cc>>secondWord;
						if(secondWord != "QUEUE")
							username = secondWord;
						else{
							continue;
						}
					}
					else if (firstWord == "NAME:"){//REad in the NAME line
						user = buffer;
						user = user.substr(6,user.size());
					}
					
					else if(firstWord == "MOVIE:"){//Read in the MOVIE line
						rentedMovie = buffer; 
						rentedMovie = rentedMovie.substr(7,rentedMovie.size());//store checkouted movie to user
					}
					else if(firstWord != "BEGIN" && firstWord != "NAME:" && firstWord != "MOVIE:" && firstWord != "END"){//Read in the list of movies in QUEUE
						queueWord = buffer;
						MovieQueue.enqueue(movieInfo.get(queueWord));
						queueSize++;
					}
					else if(temp == "END QUEUE"){//Read in the END QUEUE line
						continue;
					}
					else{//Read in END, and store all user data
						User* users = new User(username, user);
						Queue<Movie*>* userQueue = users->movieQueue();
						for(int i =0; i<queueSize; i++){
							userQueue->enqueue(MovieQueue.peekFront());
							try{
								MovieQueue.dequeue();
							}catch(const EmptyQueueException& le){}
						}
						try{
							users->rentMovie(movieInfo.get(rentedMovie));
						}catch(NoSuchElementException &le){
							users->rentMovie(NULL);
						}
						userInfo.add(username, users);//adding the user information to userInfo map when we read in each user fmor user.txt
						queueSize =0;
						rentedMovie = "";
						continue;
					}
					cc.clear();
				}
	}
//	if(argv[1] == "data/main.txt"){//enter the interation menu
		menu(userInfo, movieInfo, mapKeywords, lowercaseMovieTitle);
	//}

	file1.close();//closing all files
	file2.close();
	file3.close();	

		for(Map<string, User*>::Iterator mi = userInfo.begin(); mi != userInfo.end(); mi++) {
    delete (*mi).second;
  }

  for(Map<string, Movie*>::Iterator mi = movieInfo.begin(); mi != movieInfo.end(); mi++) {
    delete (*mi).second;
  }

  for(Map<string, Set<Movie*>* >::Iterator mi = mapKeywords.begin(); mi != mapKeywords.end(); mi++) {
    delete (*mi).second;
  }

	return 0;
}