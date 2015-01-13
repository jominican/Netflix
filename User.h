#ifndef USER
#define USER
#include <iostream>
#include "lib/Map.h"
#include "lib/Set.h"
#include "Movie.h"
#include "lib/Queue.h"

class User {
  public:
    User (string ID, string name, string a, string c);  
    /* constructor that generates a user with the given name and ID.
       While multiple users may have the same name, the ID should be unique
       (e.g., an e-mail address), so that users can log in with it. */

    User (const User & other); // copy constructor

    ~User ();            // destructor

    string getID () const;    // returns the ID associated with this user

    string getName () const;  // returns the name associated with this user

    string getAddress() const;

    string getCard() const;

    double getCharges() const;

    void addCharges(double n);

    Queue<Movie*> * movieQueue (); 
      /* returns a pointer to the user's movie queue.
         This is the easiest way to ensure that you can modify the queue.
         (If you return by reference, that's also possible, but you'd need
         to be very careful not to invoke any deep copy constructors or
         assignments. A pointer is thus safer.) */
    Map<Movie*, int> * getRatings (); 

    void addRating(Map<Movie*, int>* rate);

    void rentMovie (Movie *m);
      /* sets the user's currently rented movie to m.
         If the user already has a movie checked out, then it does nothing.
         (So no overwriting the current movie.) */

    void returnMovie ();
      /* returns the movie that the user currently has checked out.
         Does nothing if the user doesn't currently have a movie. */

    Movie* currentMovie ();
      /* returns the user's current checked out movie.
         Returns NULL if the user has no movie checked out. */

  private:
    string username, idname, address, card;
    Queue<Movie*>* theQueue;
    Map<Movie*, int>* ratings;
    Movie* current; 
    double charges;
    //Map<string, string> info;
    // you get to decide what goes here.
};
//#include "User.cpp"
#endif