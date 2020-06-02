#include <iostream>
#include <assert.h>

#include "linkedlist.hpp"

int main()
{
  // test out implementation
  LinkedList<int> test;
  test.push_back(15);
  test.push_back(20);
  // list now --> 15 - 20
  test.insert(25, 1);
  // list now --> 15 - 25 - 20
  test.push_back(30);
  test.push_back(40);
  // list now --> 15 - 25 - 20 - 30 - 40

  test.insert(1, 0);
  // list now --> 1 - 15 - 25 - 20 - 30 - 40
  assert(test.get(0)->data == 15);
  assert(test.get(1)->data == 1);
  assert(test.get(2)->data == 25);
  assert(test.get(3)->data == 20);
  assert(test.get(4)->data == 30);
  assert(test.get(5)->data == 40);
  std::cout<<"test passed!\n";
  
  return 0;
}