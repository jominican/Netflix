#ifndef NSEE
#define NSEE
#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

class NoSuchElementException : public exception{
  public:
    NoSuchElementException(const string m= "No Such Element Exist!"):msg(m){}
    ~NoSuchElementException() throw(){}
    const char* what() const throw()
    {
      //msg.c_str("No Such Element Exist!");
      return msg.c_str();
    }

  private:
    string msg;
};
#endif
