#include "Sorted_List.h"
#include <vector>
#include <initializer_list>

using namespace std;
Sorted_List::Sorted_List()
:first{}, last{}
{
  first = new Node;
  last = new Node;
  first->next=last;
  last->prev=first;
  first->prev = nullptr;
  last->next = nullptr;

}

Sorted_List::~Sorted_List()
{
  if(first->next)
  {
delete first;
  }
}

bool Sorted_List::is_empty()
{
  if (first->next == last && last->prev==first)
  {
    return true;
  }
  else
  {
    return false;
  }
}

 Sorted_List::Sorted_List(initializer_list<int> medlemmar)
 :first{},last{}
{
  first = new Node;
  last = new Node;
  last->prev=first;
  first->next=last;
  first->prev = nullptr;
  last->next = nullptr;


    for (int i: medlemmar)
  {
    insert(i);
  }
}

void Sorted_List::insert(int  data)
{

  Node* p1= new Node{}; //allocerar och konstruerar classen Node i heapen
  p1->tal = data; //tilldela int delen i classen, data

  p1 -> prev = last->prev;
  p1 -> next = first->next;

  last->prev = p1;
  first->next=p1;
}

Sorted_List::Node::Node()
:next{nullptr},tal{0},prev{nullptr}
{}

Sorted_List::Node::~Node()
{
  if(next)
{
  delete next;
}

}
