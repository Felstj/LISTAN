#ifndef SORTED_LIST_H
#define SORTED_LIST_H
#include <vector>
#include <initializer_list>

class Sorted_List{
public:


//friend std::ostream& operator <<(std::ostream& os, Sorted_List const& L);

  Sorted_List();
 Sorted_List(std::initializer_list<int> medlemmar);
 Sorted_List(Sorted_List const& L);

//Node* get_indexptr(int index);
 void insert(int data);
 int get_index(int index);
 void remove(int index);
 Sorted_List get_list();
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
  void sort();
  Stepping begin();
  Stepping end();


};
//std::ostream& operator <<(std::ostream& os, Sorted_List const& L);

Class stepping{
  public:
  private:
  Node* current;
  };
#endif
