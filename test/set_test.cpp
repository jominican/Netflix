#include <iostream>
#include <string>
#include "../lib/Map.h"
#include <vector>
#include "../lib/MergeSort.h"
#include "gtest/gtest.h"

using namespace std;

#include "../lib/Set.h"
//#include "../lib/SetImpl.h"
//TYPED_TEST_CASE_P(Set);

class SetTest: public ::testing::Test
{
protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  SetTest()
  {
    // You can do set-up work for each test here.
  }

  virtual ~SetTest()
  {
    // You can do clean-up work that doesn't throw exceptions here.   
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  virtual void SetUp()
  {
    // Code here will be called immediately after the constructor (right
    // before each test).
  }

  virtual void TearDown()
  {
    // Code here will be called immediately after each test (right
    // before the destructor).
  }

  // Objects declared here can be used by all tests in the test case.
};

//Different testing. Union between a normal set and another normal set
TEST (SetTest, Union1) {
  Set<int> setA, setB, setC;
  setA.add(1);
  setA.add(2);  
  setA.add(3);
  setA.add(4);
  setA.add(5);

  setB.add(3);  
  setB.add(4);
  setB.add(5);
  setB.add(6);
  setB.add(7);
  setB.add(8);

  bool actual[5];
  actual[0] = false;
  actual[1] = true;
  actual[2] = true;
  actual[3] = true;
  actual[4] = true;
  actual[5] = true;
  actual[6] = true;
  actual[7] = true;
  actual[8] = true;
  actual[9] = false;


  setC = setA.setUnion(setB);
  for(int i = 0; i < 10; i++) {
    //try{
      EXPECT_EQ(setC.contains(i), actual[i]);
    //}catch(const NoSuchElementException& le){

    //}
  }
}
//union between an empty set and a normal set
TEST (SetTest, Union2) {
  Set<int> setA, setB, setC;

  setB.add(0);  
  setB.add(1);
  setB.add(2);
  setB.add(3);
  setB.add(4);

  bool actual[5];
  actual[0] = true;
  actual[1] = true;
  actual[2] = true;
  actual[3] = true;
  actual[4] = true;

  setC = setA.setUnion(setB);
  for(int i = 0; i < 5; i++) {
    //try{
      EXPECT_EQ(setC.contains(i), actual[i]);
    //}catch(const NoSuchElementException& le){

    //}
  }
}
//union between 2 identical sets (ons is sorted, the other is not)
TEST (SetTest, Union3) {
  Set<int> setA, setB, setC;
  setA.add(5);
  setA.add(4);  
  setA.add(3);
  setA.add(2);
  setA.add(1);

  setB.add(1);  
  setB.add(2);
  setB.add(3);
  setB.add(4);
  setB.add(5);

  bool actual[7];
  actual[0] = false;
  actual[1] = true;
  actual[2] = true;
  actual[3] = true;
  actual[4] = true;
  actual[5] = true;
  actual[6] = false;


  setC = setA.setUnion(setB);
  for(int i = 0; i < 7; i++) {
    //try{
      EXPECT_EQ(setC.contains(i), actual[i]);
    //}catch(const NoSuchElementException& le){

    //}
  }
}
//normal intersection where some numbers intersect
TEST (SetTest, Intersection1) {
  Set<int> setA, setB, setC;
  setA.add(1);
  setA.add(2);  
  setA.add(3);
  setA.add(4);
  setA.add(5);
  setA.add(0);

  setB.add(3);  
  setB.add(4);
  setB.add(5);
  setB.add(6);
  setB.add(7);

  bool actual[10];
  actual[0] = false;
  actual[1] = false;
  actual[2] = false;
  actual[3] = true;
  actual[4] = true;
  actual[5] = true;
  actual[6] = false;
  actual[7] = false;

  setC = setA.setIntersection(setB);
  for(int i = 0; i < 8; i++) {
    //try{
      EXPECT_EQ(setC.contains(i), actual[i]);
    //}catch(const NoSuchElementException& le){

    //}
  }
}
//intersection between 2 sets with no intersection
TEST (SetTest, Intersection2) {
  Set<int> setA, setB, setC;
  setA.add(0);
  setA.add(9);  
  setA.add(8);
  setA.add(1);
  setA.add(2);

  setB.add(3);  
  setB.add(4);
  setB.add(5);
  setB.add(6);
  setB.add(7);

  bool actual[10];
  actual[0] = false;
  actual[1] = false;
  actual[2] = false;
  actual[3] = false;
  actual[4] = false;
  actual[5] = false;
  actual[6] = false;
  actual[7] = false;
  actual[8] = false;
  actual[9] = false;

  setC = setA.setIntersection(setB);
  for(int i = 0; i < 10; i++) {
    //try{
      EXPECT_EQ(setC.contains(i), actual[i]);
    //}catch(const NoSuchElementException& le){

    //}
  }
}
//intersection between a sorted and reverse sorterd set
TEST (SetTest, Intersection3) {
  Set<int> setA, setB, setC;
  setA.add(1);
  setA.add(3);  
  setA.add(5);
  setA.add(7);
  setA.add(9);

  setB.add(6);  
  setB.add(5);
  setB.add(4);
  setB.add(3);
  setB.add(2);
  setB.add(1);
  setB.add(0);

  bool actual[10];
  actual[0] = false;
  actual[1] = true;
  actual[2] = false;
  actual[3] = true;
  actual[4] = false;
  actual[5] = true;
  actual[6] = false;
  actual[7] = false;
  actual[8] = false;
  actual[9] = false;

  setC = setA.setIntersection(setB);
  for(int i = 0; i < 10; i++) {
    //try{
     EXPECT_EQ(setC.contains(i), actual[i]);
    //}catch(const NoSuchElementException& le){

    //}
  }
}