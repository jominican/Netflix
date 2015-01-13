#ifndef MOVIE
#define MOVIE
#include <iostream>
#include "lib/Set.h"
#include "lib/Map.h"

class Movie {
  public: 
    Movie (string title);       // constructor for a movie with the given title

    Movie (const Movie & other);  // copy constructor

    ~Movie ();                  // destructor

    string getTitle () const;   // returns the title of the movie

    double getPrice() const;

    void addKeyword (string keyword); 
      /* Adds the (free-form) keyword to this movie.
         If the exact same keyword (up to capitalization) was already
         associated with the movie, then the keyword is not added again. */

    void addPrice (double p); 

    Set<string> getAllKeywords () const;
      /* Returns a set of all keywords associated with the movie. */

  private:
    Set<string> movies;
    string theTitle;
    double price;
    // you get to decide what goes here
};
//#include "Movie.cpp"
#endif