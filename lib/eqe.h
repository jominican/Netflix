#ifndef EQE
#define EQE
#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

class EmptyQueueException : public std::exception{
  public:
    EmptyQueueException(const string m= "Empty Queue!"):msg(m){}
    ~EmptyQueueException() throw(){}
    const char* what() const throw()
    {
      //msg.c_str("No Such Element Exist!");
      return msg.c_str();
    }

  private:
    string msg;
};
#endif