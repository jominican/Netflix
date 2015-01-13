#include <iostream>
#include <vector>
#include "gtest/gtest.h"
//#include "../lib/MergeSort.h"


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

TEST (MergeSortTest, BasicCase) {
  string fruit[5];
  // int fruit[5];

  fruit[0] = "actual";
  fruit[1] = "banana";
  fruit[2] = "canteloupe";
  fruit[3] = "durian";
  fruit[4] = "eggplant";

  // fruit[0] = 0;
  // fruit[1] = 1;
  // fruit[2] = 2;
  // fruit[3] = 3;
  // fruit[4] = 4;

  std::vector<string> v;
  // std::vector<int> v;
  v.push_back(fruit[4]);
  v.push_back(fruit[3]);
  v.push_back(fruit[1]);
  v.push_back(fruit[2]);
  v.push_back(fruit[0]);
  std::vector<string> v_sorted = MergeSort::sort(v);
  // std::vector<int> v_sorted = MergeSort::sort(v);

  for( int i = 0; i < 5; i++) {
    EXPECT_EQ(v_sorted.at(i), fruit[i]);
  }
}

TEST (MergeSortTest, SortedCase){
  vector<int> v;
  v.push_back(1);
  v.push_back(3);
  v.push_back(5);
  v.push_back(7);
  v.push_back(9);
  int actual[5];
  actual[0] = 1;
  actual[1] = 3;
  actual[2] = 5;
  actual[3] = 7;
  actual[4] = 9;
  vector<int> v_sorted = MergeSort::sort(v);
  for(unsigned int i = 0; i < v.size(); i++) {
    EXPECT_EQ(v_sorted.at(i), actual[i]);
  }
}

TEST (MergeSortTest, EmptyCase){
  vector<double> v;
  vector<double> v_sorted = MergeSort::sort(v);
  for(unsigned int i = 0; i < v.size(); i++) {
    EXPECT_EQ(v_sorted.at(i), NULL);
  }
}

TEST (MergeSortTest, ReverseCase){
  vector<double> v;
  v.push_back(8.1);
  v.push_back(6.1);
  v.push_back(4.1);
  v.push_back(2.1);
  v.push_back(0.1);

  double actual[5];
  actual[0] = 0.1;
  actual[1] = 2.1;
  actual[2] = 4.1;
  actual[3] = 6.1;
  actual[4] = 8.1;

  vector<double> v_sorted = MergeSort::sort(v);
  for(unsigned int i = 0; i < v.size(); i++) {
    EXPECT_EQ(v_sorted.at(i), actual[i]);
  }
}

TEST (MergeSortTest, DuplicateCase){
  vector<int> v;
  v.push_back(3);
  v.push_back(2);
  v.push_back(8);
  v.push_back(8);
  v.push_back(5);
  v.push_back(5);
  v.push_back(10);
  v.push_back(14);

  int actual[8];
  actual[0] = 2;
  actual[1] = 3;
  actual[2] = 5;
  actual[3] = 5;
  actual[4] = 8;
  actual[5] = 8;
  actual[6] = 10;
  actual[7] = 14;


  vector<int> v_sorted = MergeSort::sort(v);
  for(unsigned int i = 0; i < v.size(); i++) {
    EXPECT_EQ(v_sorted.at(i), actual[i]);
  }
}