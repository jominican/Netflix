#ifndef MERGESORT
#define MERGESORT
#include <iostream>
#include <vector>

using namespace std;

class MergeSort {
  public:
    template <typename T>
    static std::vector<T> sort (std::vector<T> c) {
      // for (int i=0; i<c.size(); i++){
      //   cout<<c[i]<<endl;
      // }
      //sort code here
      sorting(c,0,c.size()-1);
      return c;
    }

    template <typename T>
    static void sorting(std::vector<T> &c, int first, int last){

      if(first < last){ //base case
        int m = (first + last )/2; //divide the array by 2 T(n) = THETA(1)+
        sorting(c,first,m); //recurse     
        sorting(c,m+1,last); //recurse    
        Merge(c, first, last, m); //combine THETA(n)
      }
    }
    
    template <typename T>//code for merging smaller pieces fo the vector
    static void Merge( std::vector<T> &c, int first, int last, int m){
      //cout<<c[0]<<endl;
      int i = first;
      int j=m+1; 
      int k=0;
 
      std::vector<T> temp((last-first+1));

      while( i <= m || j <= last){  
        if(((j > last) || (c[i] <= c[j])) && (i<=m)){  
          temp[k] = c[i];
          i++;
          k++;
        }
        else{
          temp[k] = c[j];
          j++;
          k++;
        }                                         
      }
      for(k=0; k<(last-first+1); k++){
        c[k+first] = temp[k];
      }

    }
};

#endif
