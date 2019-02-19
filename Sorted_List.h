#ifndef SORTED_LIST_H
#define SORTED_LIST_H

class Sorted_List{
public:
  Sorted_List();
  Sorted_List(int test);
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
