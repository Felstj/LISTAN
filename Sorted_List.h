#ifndef SORTED_LIST_H
#define SORTED_LIST_H
#include <vector>
#include <initializer_list>

class Sorted_List{
public:

  Sorted_List();
 Sorted_List(std::initializer_list<int> medlemmar);
 void insert(int data);
 int get_index(int index);
 void remove(int index);
 void sortny();
 int size();
  bool is_empty();
  ~Sorted_List();

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
