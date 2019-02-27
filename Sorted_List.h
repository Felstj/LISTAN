#ifndef SORTED_LIST_H
#define SORTED_LIST_H
#include <vector>
#include <initializer_list>

class Sorted_List{
public:

  Sorted_List();
 Sorted_List(std::initializer_list<int> medlemmar);
 void insert(int data);
<<<<<<< HEAD
=======
 int get_index(int index);
 void sort();
 void remove(int index);
 void sortny();
 //Node* indexptr();
  //konstruktor som kan ta varierande många integers
>>>>>>> c5d08d6f43557e5c3657113d82cc11f1f2dc5419
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
