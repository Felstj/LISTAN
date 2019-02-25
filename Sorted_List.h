#ifndef SORTED_LIST_H
#define SORTED_LIST_H
#include <vector>
#include <initializer_list>

class Sorted_List{
public:

  Sorted_List();
 Sorted_List(std::initializer_list<int> medlemmar);
 void insert(int data);
  bool is_empty();
  ~Sorted_List();
  void sort();
  int get(int index);

private:
  class Node //noder till listan
  {
  public:
    Node();
    ~Node();
    Node* next;
    int tal;
    Node* prev;
  private:
  };
  Node* first; //accessblock i classen
  Node* last; //accessblock i classen

};


#endif
