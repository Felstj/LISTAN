#ifndef SORTED_LIST_H
#define SORTED_LIST_H
#include <vector>
#include <initializer_list>
#include <sstream>

class Sorted_List{
public:


//friend std::ostream& operator <<(std::ostream& os, Sorted_List const& L);
//&& - döende objekt skapas och destrueras innanför måsvingarna
  Sorted_List();
 Sorted_List(std::initializer_list<int> medlemmar);
 Sorted_List(Sorted_List const& rhs);
 Sorted_List& operator =(Sorted_List const& rhs);
 //Sorted_List
//Node* get_indexptr(int index);
 void insert(int data);
 int get_index(int index)const;
 void remove(int index);
 int size() const;
  bool is_empty() const;
std::stringstream  print(Sorted_List const& L)const;
void printny(Sorted_List const& L)const;
  ~Sorted_List();

private:

  class Node //noder till listan
  {
  public:

  //  Node();
    ~Node();
    Node* next;
    int tal;
    Node* prev;
  private:
  };

  Node* first; //accessblock i classen
  Node* last; //accessblock i classen
  void sort();

};




#endif
