#ifndef linkedList_H
#define LinkedList_H

#include <iostream>
#include <assert.h>
/* define linkedList node */
template <typename T>
struct node
{
  T data;
  node *next;
};

/* define linkedList class */
template <typename T>
class LinkedList
{
public:
  LinkedList() : head_(nullptr), len_(0){};
  void push_back(T newData);
  node<T> *get(int idx);
  void insert(T newData, int idx);
  ~LinkedList();

private:
  node<T> *head_;
  int len_;
};

/* class implementation */
template <typename T>
void LinkedList<T>::push_back(T newData)
{

  node<T> *temp = (node<T> *)new node<T>();
  temp->data = newData;
  temp->next = nullptr;
  if (head_ == nullptr)
  {
    head_ = temp;
  }
  else
  {
    node<T> *temp1 = head_;
    while (temp1->next != nullptr)
      temp1 = temp1->next;
    temp1->next = temp;
  }
  len_++;
}

template <typename T>
node<T> *LinkedList<T>::get(int idx)
{
  assert(idx < len_ && "given index bigger than length of list!");
  node<T>* temp = head_;
  for(int i=1; i<=idx; i++)
    temp = temp->next;
  return temp;
}

template <typename T>
void LinkedList<T>::insert(T newData, int idx)
{
  assert(idx < len_ && "given index bigger than length of list!");
  node<T> *newNode = new node<T>();
  newNode->data = newData;

  if (head_ == nullptr && idx == 0)
    head_ = newNode;
  else
  {
    node<T> *tempParent, *tempChild;
    tempParent = head_;
    for (int i = 1; i < idx; i++)
    {
      // if we want to insert node at idx = 5, we get parent of node 5 which is 4
      tempParent = tempParent->next;
    }
    tempChild = tempParent->next;
    tempParent->next = newNode;
    newNode->next = tempChild;
  }
  len_++;
}
template <typename T>
LinkedList<T>::~LinkedList()
{
  /** delete all allocated nodes **/
  if (head_ != nullptr)
  {
    node<T> *temp = head_;
    node<T> *next;
    while (temp != nullptr)
    {
      next = temp->next;
      delete temp;
      temp = next;
    }
  }
}
#endif