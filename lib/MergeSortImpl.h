#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <vector>
#ifndef MERGESORTIMPL
#define MERGESORTIMPL

using namespace std;

template <class T>
static vector<T> MergeSort<T>::sort (vector<T> c) {

  //sort code here
  sorting(c,0,c.size()-1);
  return c;
}

template <class T>
static void MergeSort<T>::sorting(vector<T> &c, int first, int last){
		if(first < last){ //base case
			int m = (first + last )/2; //divide the array by 2 T(n) = THETA(1)+
			sorting(c,first,m); //recurse			
			sorting(c,m+1,last); //recurse		
			Merge(c, first, last, m); //combine	THETA(n)
		}
	}

template <class T>//code for merging smaller pieces fo the vector
	static void MergeSort<T>::Merge( vector<T> &c, int first, int last, int m){
		int i = first;
		int j=m+1; 
		int k=0;
		vector<T> temp((last-first+1), 0);
		while( i <= m || j <= last){											
			if(((c[i] <= c[j]) || (j > last)) && (i<=m)){  
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
}

#endif