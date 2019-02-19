#ifndef SORTED_LIST_H
#define SORTED_LIST_H
#include <vector>
#include <initializer_list>

class Sorted_List{
public:
  Sorted_List();
  std::vector<int> Lista{};
  Sorted_List(std::initializer_list<int> medlemmar);
  //konstruktor som kan ta varierande många integers
  bool is_empty();
  //~Sorted_List();
private:
  class Node //noder till listan
  {
  public:
    int* next;
    int tal;
    int* prev;
  private:
  };
  Node* first; //accessblock i classen
  Node* last; //accessblock i classen
  Node sentf; //sentinell i listan
  Node sentl; //sentinell i listan
};


#endif
