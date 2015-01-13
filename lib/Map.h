#ifndef MAP
#define MAP
#include <iostream>
#include "nsee.h"




template <class keyType, class valueType>
struct MapItem
{
  keyType key;
  valueType value;
  MapItem<keyType, valueType> *prev, *next;
};

template <class FirstType, class SecondType> 
struct Pair {
   FirstType first;
   SecondType second;

   Pair(FirstType first, SecondType second)
      { this->first = first; this->second = second; }
   // we're very nice and give you this piece of difficult code for free :-P
};


template <class keyType, class valueType>
class Map
{
  public:
    Map ();  // constructor for a new empty map

    Map (const Map<keyType, valueType> & other);

    ~Map (); // destructor

    int size () const; // returns the number of key-value pairs

    void add (keyType key1, valueType value1); 
      /* Adds a new association between the given key and the given value.
         If the key already has an association, it should do nothing.
      */

    void remove (keyType key1);
     /* Removes the association for the given key.
        If the key has no association, it should do nothing. */
    void remove();

    valueType & get (const keyType & key1);
     /* Returns the value associated with the given key.
        If the key existed in the map, success should be set to true.
        If the key has no association, it should set success to false. */

    void merge (const Map<keyType, valueType> & other);
     /* Adds all the key-value associations of other to the current map.
        If both maps (this and other) contain an association for the same
        key, then the one of this is used. */

  
    void printMap ();

    void printMapSet();

    Map<keyType, valueType> & operator = (const Map<keyType, valueType>& otherMap);

    bool contains(keyType key) const;

    public:
     class Iterator {
         /* add any constructors that you feel will be helpful,
            and choose whether to make them public or private. */

         public:

            Iterator();
           Pair<keyType, valueType> operator* () const;
              // return the current (key, value) pair the iterator is at

           Map<keyType,valueType>::Iterator operator++ ();
              // advances the iterator (pre-increment)

           Map<keyType,valueType>::Iterator operator++ (int dummy);//dummy function for post increment

           Map<keyType,valueType>::Iterator operator= (const Map<keyType,valueType>::Iterator & other);
              // assigns the other iterator to this iterator and returns this

           bool operator== (const Map<keyType,valueType>::Iterator & other) const;
              // returns whether this iterator is equal to the other iterator

           bool operator!= (const Map<keyType,valueType>::Iterator & other) const;
              // returns whether this iterator is not equal to the other iterator

            friend class Map;
          private:
           /* Optionally, if you think that it makes your code easier to write,
              you may also overload other operators: */
            Iterator(const Map<keyType,valueType> *w, MapItem<keyType, valueType> *l);
            MapItem<keyType, valueType>* curr;
            const Map<keyType,valueType> *WhoIBelongTo;
     };

     Map<keyType,valueType>::Iterator begin () const;
       // returns an iterator initialized to the first element

     Map<keyType,valueType>::Iterator end () const;
       /* returns an iterator initialized past the last element,
          to designate that the end of the map has been reached. */

  private:
     /* The head and tail of the linked list you're using to store
        all the associations. */

     MapItem <keyType, valueType> *head, *tail;
     int listSize;
     MapItem <keyType, valueType> *tracker;



     /* If you like, you can add further data fields and private
        helper methods. */
};
#include "MapImpl.h"
#endif
