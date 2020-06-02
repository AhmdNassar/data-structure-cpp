#ifndef linkedList_H
#define LinkedList_H

#include <iostream>

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
}

template <typename T>
LinkedList<T>::~LinkedList()
{
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