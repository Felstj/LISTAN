#include "Sorted_List.h"
#include <vector>
#include <initializer_list>
#include <iostream>

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
  //first in list
  Node* p1= new Node{}; //allocerar och konstruerar classen Node i heapen
  p1->tal = data; //tilldela int delen i classen, data

  p1 -> prev = first;
  p1->next = first->next;
  first->next->prev=p1;
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


int Sorted_List::get_index(int index)
{

  Node *curr=first;
  int ret;
  if(is_empty())
  {
    return 0;

  }
  else if(index>size())
  {

throw logic_error("index utanför listan");

  }
  else{

for (int i{0}; i<index; ++i)
{
curr=curr->next;
ret=curr->tal;
}
return ret;
}
}


void Sorted_List::remove(int index)
{
Node *curr=first;
Node *precurr=curr; // något som pekar på det curr pekade på förra gången för att hålla ihop listan.
if(is_empty())
{
  index+1; //error egentligen
}
else if(index>size())
{
throw logic_error("index utanför listan");

}
else
{
for(int i{0}; i<index; ++i)
{

  precurr=curr;
  curr=curr->next;
  cout<<curr->tal;
}

curr->next->prev=precurr;
precurr->next=curr->next;
curr->next=nullptr;
curr->prev=nullptr;//länkar ihop listan innan man raderar "curr"
delete curr;

}
}




void Sorted_List::sortny()
{
  Node* curr=first->next;
  Node* looper=nullptr;
  Node* maxptr=nullptr;
  int max{};
  int count{0};
  while(curr->next)
  {
    if (curr->next->next==nullptr)
    {

      maxptr=curr;
      max=curr->tal; //det minsta talet kommer ligga sist i listan annars
      curr=curr->next;
      insert(max);
      maxptr->prev->next=maxptr->next;
      maxptr->next->prev=maxptr->prev;
      maxptr->next=nullptr;
      maxptr->prev=nullptr;
      delete maxptr;


    }
else
{
      looper=curr;

      max = looper->tal;
      maxptr = looper;

        while(looper->next)
          {

            if (max<looper->tal)
            {

              max = looper->tal;
              maxptr = looper;
            }
            looper=looper->next;

          }

      insert(max);
      if (curr==maxptr)
      {
      curr=curr->next;

    }



      maxptr->prev->next=maxptr->next;
      maxptr->next->prev=maxptr->prev;
      maxptr->next=nullptr;
      maxptr->prev=nullptr;
      delete maxptr;
      maxptr=nullptr; //good mannerss

}

    count++;


  }

}

int Sorted_List::size()
{
Node* curr=first;
int ret{0};
if(is_empty())
{
  return 0;
}
else{
while(curr->next!=last)
{
  ++ret;
  curr=curr->next;
}
return ret;
}
}
