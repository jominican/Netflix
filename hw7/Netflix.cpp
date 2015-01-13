#include "Netflix.h"
#include <sstream>
#include <string>
#include <iostream>
#include <exception>
#include <string>

using namespace std;

Netflix::Netflix(int argc, char* argv[])
{

	flag = false;
	bool passed = true;

	int queueSize = 0;
	int queueSize2 = 0;
	double p=0;
	double charges=0;

	ifstream file1, file2, file3;//variables for files
	char buffer[100];
	string filenames2, firstWord, secondWord, thirdWord, username, firstName, lastName, user, password, address, card, price, c;
	string newMovieTitle, movieTitle, newKeywords, keywords, a, meow3, rentedMovie, queueWord;
	string movieWord = "";
	Queue<Movie*> MovieQueue;
	// Queue< Map<Movie*, int> > MovieQueue2;  
	Map<Movie*, int> ratings;
	//string lala = "data/"+argv[1];

	if(argc != 2){
		cout<<"The number of arguements is wrong"<<endl;
		exit(0);
	}

	string lala = "../";
	lala += argv[1];

	file1.open(lala.c_str());//open the file
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

		file2.open(filenames1.c_str());
		file3.open(filenames2.c_str());
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
							else if(secondWord == "ACTOR:"){
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
									mapActors.get(meow3);
									mapKeywords.get(meow3);
								}catch(const NoSuchElementException& le){
        					passed = false;
								}
								if(!passed){
									Set<Movie*>* temp = new Set<Movie*>;
									temp->add(movies);
									mapActors.add(meow3, temp);
									mapKeywords.add(meow3, temp);
								}
								else{
									mapActors.get(meow3)->add(movies);
									mapKeywords.get(meow3)->add(movies);
								}
								passed = true;								
							}
							else if(secondWord == "PRICE:"){
								price = buffer;
								price = price.substr(8, price.size());
								p = atof(price.c_str());
								movies->addPrice(p);
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
						if(secondWord != "QUEUE" && secondWord != "RATINGS")
							username = secondWord;
						else{
							continue;
						}
					}
					else if (firstWord == "NAME:"){//REad in the NAME line
						user = buffer;
						user = user.substr(6,user.size());
					}
					else if(firstWord == "PASSWORD:"){
						password = buffer;
						password = password.substr(10, password.size());
					}
					else if(firstWord == "ADDRESS:"){
						address = buffer;
						address = address.substr(9, address.size());
					}
					else if(firstWord == "CREDITCARD:"){
						card = buffer;
						card = card.substr(12, card.size());
					}

					else if(firstWord == "CHARGES:"){
						c = buffer;
						c = c.substr(9, c.size());
						charges = atof(c.c_str());
					}
					
					else if(firstWord == "MOVIE:"){//Read in the MOVIE line
						rentedMovie = buffer; 
						rentedMovie = rentedMovie.substr(7,rentedMovie.size());//store checkouted movie to user
					}
					else if(firstWord != "BEGIN" && firstWord != "NAME:" && firstWord != "MOVIE:" && firstWord != "END" && firstWord != "1" && firstWord != "2" && firstWord != "3" && firstWord != "4" && firstWord != "5"){//Read in the list of movies in QUEUE
						queueWord = buffer;
						MovieQueue.enqueue(movieInfo.get(queueWord));
						queueSize++;
					}
					else if(firstWord != "BEGIN" && firstWord != "NAME:" && firstWord != "MOVIE:" && firstWord != "END" && (firstWord == "1" || firstWord == "2" || firstWord == "3" || firstWord == "4" || firstWord == "5")){
						movieWord = buffer;
						movieWord = movieWord.substr(2,temp.size());
						int value = atoi(firstWord.c_str());
						ratings.add(movieInfo.get(movieWord), value);
						queueSize2++;
					}
					else if(temp == "END RATINGS"){
						continue;
					}
					else if(temp == "END QUEUE"){//Read in the END QUEUE line
						continue;
					}
					else if(temp == "END"){//Read in END, and store all user data
						passwordInfo.add(username, password);
						User* users = new User(username, user, address, card);
						users->addCharges(charges);
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
						Map<Movie*, int> * temp = users->getRatings();
						Map<Movie*, int>::Iterator itA = ratings.begin();
						for(itA = ratings.begin(); itA != ratings.end(); ++itA) {
    					temp->add(((*itA).first), ((*itA).second));
  					}
						for(int i=0; i<queueSize2; i++){
							ratings.remove();
						}
						//cout<<username<<" "<<users->getRatings()<<endl;
						userInfo.add(username, users);//adding the user information to userInfo map when we read in each user fmor user.txt
						// users->movieQueue()->printStack();
						//users->getRatings()->printMap();
						queueSize =0;
						queueSize2=0;
						rentedMovie = "";
						movieWord = "";
						password = "";
						continue;
					}
					cc.clear();
				}
	}

	//movieInfo.printMap();
	file1.close();//closing all files
	file2.close();
	file3.close();	
	size = 0;
}

// Netflix::Netflix()//(QWidget *parent) : QMainWindow(parent)
// {

// }


Netflix::~Netflix()
{
}


bool Netflix::loginIn(string login, string password)
{
	string encrypted;
	char key = 'x';
	bool passed = true;

	for(int i=0; i<password.size(); ++i){
		encrypted += password[i]^(int(key)+i)%20;
	}

		if(userInfo.contains(login)){//if the userinfo map has the ID, return pass will be true
			this->setName(login);
			this->setID(userInfo.get(login)->getName());
			if(passwordInfo.get(login) != encrypted)
				passed = false;
		}
		else{
  		passed = false;
  	}

  return passed;

}


void Netflix::quit()
{
	ofstream userFile;
	userFile.open(filenames1.c_str(), std::ofstream::out | std::ofstream::trunc);//clearing the file
	userFile.clear();
	for(Map<string, User*>::Iterator userIter = userInfo.begin(); userIter != userInfo.end(); userIter++) {
  	Pair<string, User*> item = *userIter;
  	User *userList = item.second;
  	userFile<<"BEGIN "<<userList->getID()<<endl;
    userFile<<"NAME: "<<userList->getName()<<endl;
    userFile<<"PASSWORD: "<<passwordInfo.get(userList->getID())<<endl;
    userFile<<"ADDRESS: "<<userList->getAddress()<<endl;
    userFile<<"CREDITCARD: "<<userList->getCard()<<endl;
    userFile<<"CHARGES: "<<userList->getCharges()<<endl;

    if(userList->currentMovie() != NULL){
   		userFile<<"MOVIE: "<<userList->currentMovie()->getTitle()<<endl;
   	}
   	userFile<<"BEGIN QUEUE "<<endl;
   	while(!(userList->movieQueue()->isEmpty())){
   		userFile<<userList->movieQueue()->peekFront()->getTitle()<<endl;
   		userList->movieQueue()->dequeue();
   	}
   	userFile<<"END QUEUE "<<endl;
    userFile<<"BEGIN RATINGS"<<endl;
		Map<Movie*, int>::Iterator itA;
		//cout<<userList->getRatings()<<endl;
		for(itA = userList->getRatings()->begin(); itA != userList->getRatings()->end(); itA++) {
			string x = ((*itA).first)->getTitle();
			userFile<<((*itA).second)<<" "<<x<<endl;
		}    
    userFile<<"END RATINGS"<<endl;
    userFile<<"END"<<endl;
  }
}

bool Netflix::confirm(string login, string name, string password, string address, string card)
{
	bool passed = true;
	char key = 'x';
	if(userInfo.contains(login)){//if the userInfo map has the ID, we output User Exist, otherwise, the user can choose a ID and name
  }
  else{
  	User* newUser = new User(login, name, address, card);//allocating memory for new ID/NAME
  	userInfo.add(login, newUser);
  	string encrypted; 
		for(int i=0; i<password.size(); ++i){
			encrypted += password[i]^(int(key)+i)%20;
		}
	 	passwordInfo.add(login, encrypted);
    passed = false;
  }
  return passed;
}

void Netflix::setName(string n)
{
	name = n;
	getName = n;
}

void Netflix::setID(string n)
{
	getID = n;
}


QString Netflix::Name()
{
	return QString::fromStdString(getName);
}

QString Netflix::ID()
{
	return QString::fromStdString(getID);
}

QString Netflix::getCurrentMovieLabel()
{
	string error = "You have no movie checked out";
	if(userInfo.get(name)->currentMovie()){
			current = userInfo.get(name)->currentMovie()->getTitle();
			currentMovie = userInfo.get(name)->currentMovie();

		return QString::fromStdString(userInfo.get(name)->currentMovie()->getTitle());
	}
	else{
		return QString::fromStdString(error);
	}
}

QString Netflix::getCurrentQueueLabel()
{
	string error = "You have no movie in queue";
	try{
		return QString::fromStdString(userInfo.get(name)->movieQueue()->peekFront()->getTitle());
	}catch(const EmptyQueueException& le){return QString::fromStdString(error);}
}

QString Netflix::getCurrentPriceLabel()
{
	string error = "No Price";
	if(userInfo.get(name)->currentMovie()){
			current = userInfo.get(name)->currentMovie()->getPrice();
			currentMovie = userInfo.get(name)->currentMovie();

		return QString::number(userInfo.get(name)->currentMovie()->getPrice());
	}
	else{
		return QString::fromStdString(error);
	}
}

bool Netflix::returnMovie()
{
	if(userInfo.get(name)->currentMovie()){
		double cost = userInfo.get(name)->currentMovie()->getPrice();
		userInfo.get(name)->returnMovie();
		userInfo.get(name)->addCharges(cost);
		return true;
	}
	return false;

}

int Netflix::rentMovie()
{
	if(userInfo.get(name)->currentMovie()){
		return 3;	
	}
	else{
		try{
			userInfo.get(name)->rentMovie(userInfo.get(name)->movieQueue()->peekFront());
			userInfo.get(name)->movieQueue()->dequeue();
			return 1;
		}catch(const EmptyQueueException& le){
			return 2;
		}
	}
}

bool Netflix::deleteFromQueue()
{
	try{
		userInfo.get(name)->movieQueue()->dequeue();
		return true;
	}catch(const EmptyQueueException& le){return false;}
}

bool Netflix::moveToBack()
{
	try{
		Movie* temp = userInfo.get(name)->movieQueue()->peekFront();
		userInfo.get(name)->movieQueue()->dequeue();
		userInfo.get(name)->movieQueue()->enqueue(temp);
		return true;
	}catch(const EmptyQueueException& le){return false;}
}

bool Netflix::searchByTitle(string title)
{

	trie* t = new trie();
	string z = "";
	bool passed = true;
	bool passed2 = true;
	locale loc;
	string str=title;
	string meow;
	for (std::string::size_type i=0; i<str.length(); ++i)//this will convert the user input to lowercase
  meow += tolower(str[i],loc);
	//movieTitle = meow;

	Map<string, Movie*>:: Iterator itB;
	for(itB = lowercaseMovieTitle.begin(); itB != lowercaseMovieTitle.end(); itB++){
		string y = ((*itB).first);
		t->insert(z);
	}

	if(!(t->search(meow))){
		passed2 = false;
	}


	Map<string, Movie*>:: Iterator itA;
			for(itA = lowercaseMovieTitle.begin(); itA != lowercaseMovieTitle.end(); itA++) {
				string x = ((*itA).first);
				size_t found = x.find(meow);
				if(title == ""){
					passed = false;
				}
				else if(found == std::string::npos){
					passed = false;
				}
				else{
					movieTitle = x;
					passed = true;
					break;
				}
			}

		return passed;




	// if(lowercaseMovieTitle.contains(meow)){//if lowercaseMovieTitle contains the title, we will ouptut
	// 	return true;
 //  }
 //  return false;
 
}

int Netflix::searchByKeyword(string title)
{
	int passed = 0;

	locale loc;
	string str2=title;
	string meow2;
	for (std::string::size_type i=0; i<str2.length(); ++i)//convert the keyword input to lowercase
  meow2 += tolower(str2[i],loc);
	keyword = meow2;

	Map<string, Set<Movie*>* >:: Iterator itB;
			for(itB = mapKeywords.begin(); itB != mapKeywords.end(); itB++) {
				string x = ((*itB).first);
				size_t found = x.find(meow2);
				if(title == ""){
					passed = 3;
				}
				else if(found == std::string::npos){
					passed = 3;
				}
				else{
					passed = 1;
					keyword = x;
					break;
				}
			}

	if(passed != 1){
		Map<string, Movie*>:: Iterator itA;
			for(itA = lowercaseMovieTitle.begin(); itA != lowercaseMovieTitle.end(); itA++) {
				string x = ((*itA).first);
				//keyword = x;
				size_t found = x.find(meow2);
				if(title == ""){
					passed = 4;
				}
				else if(found == std::string::npos){
					passed = 4;
				}
				else{
					passed = 2;
					break;
				}
			}
	}

	return passed;


	// if(mapKeywords.contains(meow2)){//if mapKeywords contain the keyword, we output the movie and all its information
	// 	passed = 1;
 //  }
 //  else{
 //  	passed = 3;
 //  }

 //  if(passed != 1){
	//   if(lowercaseMovieTitle.contains(meow2)){
	// 		passed = 2;
	//   }
	//   else{
	//    passed = 4;
	//   }
	// }
	// return passed;

}

int Netflix::searchByActor(string title)
{
	int passed = 0;

	locale loc;
	string str2=title;
	string meow2;
	for (std::string::size_type i=0; i<str2.length(); ++i)//convert the keyword input to lowercase
  meow2 += tolower(str2[i],loc);
	keyword = meow2;
	if(mapActors.contains(meow2)){//if mapKeywords contain the keyword, we output the movie and all its information
		passed = 1;
  }
  else{
  	passed = 3;
  }

  if(passed != 1){
	  if(lowercaseMovieTitle.contains(meow2)){
			passed = 2;
	  }
	  else{
	   passed = 4;
	  }
	}
	return passed;

}

bool Netflix::needsRating()
{
	bool passed = true;
		Map<Movie*, int>::Iterator itA;
		for(itA = userInfo.get(name)->getRatings()->begin(); itA != userInfo.get(name)->getRatings()->end(); itA++) {
			string x = ((*itA).first)->getTitle();
			if(x == current){
				passed = false;
			}
		}
		return passed;
}

bool Netflix::changingPassword(string changed)
{
	bool passed = true;
	if(changed != ""){
		passwordInfo.remove(name);
		string encrypted = "";
		char key = 'x';
		for(int i=0; i<changed.size(); ++i){
			encrypted += changed[i]^(int(key)+i)%20;
		}
		passwordInfo.add(name, encrypted);
	}
	else{
		passed = false;
	}
	return passed;
}

void Netflix::one()
{
	if(flag){
		userInfo.get(name)->getRatings()->remove(currentMovie2);
		userInfo.get(name)->getRatings()->add(currentMovie2, 1);
	}
	else{
		userInfo.get(name)->getRatings()->remove(currentMovie);
		userInfo.get(name)->getRatings()->add(currentMovie, 1);
	}
	flag = false;
}

void Netflix::two()
{
	if(flag){
		userInfo.get(name)->getRatings()->remove(currentMovie2);
		userInfo.get(name)->getRatings()->add(currentMovie2, 2);
	}
	userInfo.get(name)->getRatings()->remove(currentMovie);
	userInfo.get(name)->getRatings()->add(currentMovie, 2);	
	flag = false;
}
void Netflix::three()
{
	if(flag){
		userInfo.get(name)->getRatings()->remove(currentMovie2);
		userInfo.get(name)->getRatings()->add(currentMovie2, 3);
	}
	userInfo.get(name)->getRatings()->remove(currentMovie);
	userInfo.get(name)->getRatings()->add(currentMovie, 3);
	flag = false;
}
void Netflix::four()
{
	if(flag){
		userInfo.get(name)->getRatings()->remove(currentMovie2);
		userInfo.get(name)->getRatings()->add(currentMovie2, 4);
	}
	userInfo.get(name)->getRatings()->remove(currentMovie);
	userInfo.get(name)->getRatings()->add(currentMovie, 4);
	flag = false;
}
void Netflix::five()
{
	if(flag){
		userInfo.get(name)->getRatings()->remove(currentMovie2);
		userInfo.get(name)->getRatings()->add(currentMovie2, 5);
	}
	userInfo.get(name)->getRatings()->remove(currentMovie);
	userInfo.get(name)->getRatings()->add(currentMovie, 5);
	flag = false;
}

QString Netflix::getCurrentMovieTitleLabel()
{
	return QString::fromStdString(lowercaseMovieTitle.get(movieTitle)->getTitle());
}

QString Netflix::getCurrentMovieTitleLabel3()
{
	flag = true;
	this->mapIterator();
	int i = ((*mapIter).second);
	std::string s;
	std::stringstream out;
	out << i;
	s = out.str();
	string x = s + " " + ((*mapIter).first)->getTitle();
	return QString::fromStdString(x);
}

QString Netflix::getCurrentMovieTitleLabel2()
{
	this->setIterator();
	return QString::fromStdString((*setIter)->getTitle());
}

void Netflix::addToMyQueue()
{
	userInfo.get(name)->movieQueue()->enqueue(lowercaseMovieTitle.get(movieTitle));
}

void Netflix::addToMyQueue2()
{
	userInfo.get(name)->movieQueue()->enqueue((*setIter));
}

void Netflix::mapIterator()
{
	temp = userInfo.get(name)->getRatings();//initializing iterators
	mapIter = temp->begin();
	//size = (*setIter)->getAllKeywords().size();
	movieTitle1 = ((*mapIter).first)->getTitle();
	currentMovie2 = ((*mapIter).first);
}


void Netflix::setIterator()
{
	tempMapKeyWords = mapKeywords.get(keyword);//initializing iterators
	setIter = tempMapKeyWords->begin();
	size = (*setIter)->getAllKeywords().size();
	movieTitle = (*setIter)->getTitle();
}

QString Netflix::next()
{
		++setIter;
		if(setIter != tempMapKeyWords->end()){
			size = (*setIter)->getAllKeywords().size();
			movieTitle = (*setIter)->getTitle();
			return QString::fromStdString((*setIter)->getTitle());
		}
		else{
			this->setIterator();
			size = (*setIter)->getAllKeywords().size();
			movieTitle = (*setIter)->getTitle();
			return QString::fromStdString((*setIter)->getTitle());
		}
}

QString Netflix::next2()
{
	flag = true;
		++mapIter;
		if(mapIter != temp->end()){
			//size = (*setIter)->getAllKeywords().size();
			movieTitle1 = ((*mapIter).first)->getTitle();
			int i = ((*mapIter).second);
			std::string s;
			std::stringstream out;
			out << i;
			s = out.str();
			string x = s + " " + ((*mapIter).first)->getTitle();
			currentMovie2 = ((*mapIter).first);
			return QString::fromStdString(x);
		}
		else{
			this->mapIterator();
			//size = (*setIter)->getAllKeywords().size();
			movieTitle1 = ((*mapIter).first)->getTitle();
			int i = ((*mapIter).second);
			std::string s;
			std::stringstream out;
			out << i;
			s = out.str();
			string x = s + " " + ((*mapIter).first)->getTitle();
			currentMovie2 = ((*mapIter).first);
			return QString::fromStdString(x);
		}
}

int Netflix::setNumKeywords()
{
	return size;
}

int Netflix::numKeywords()
{
	//try{
		return lowercaseMovieTitle.get(movieTitle)->getAllKeywords().size();
	//}catch(const NoSuchElementException& le){}
}


Set<string> Netflix::getAllKeywords()
{
	//try{
		return lowercaseMovieTitle.get(movieTitle)->getAllKeywords();
	//}catch(const NoSuchElementException& le){}
}

Set<string> Netflix::getAllKeywords1()
{
	this->setIterator();
	//try{
		return movieInfo.get(movieTitle)->getAllKeywords();
	//}catch(const NoSuchElementException& le){}
}

Set<string> Netflix::getAllKeywords2()
{
	//try{
		return movieInfo.get(movieTitle)->getAllKeywords();
	//}catch(const NoSuchElementException& le){}
}