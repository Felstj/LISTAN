#include "Sorted_List.h"
#include <vector>
#include <initializer_list>
#include <iostream>
#include <sstream>

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

bool Sorted_List::is_empty() const
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

Sorted_List& Sorted_List::operator =(Sorted_List const& rhs)
{

  Node* curr=rhs.first;

  if(is_empty()==false)
{
for (int i{0}; i<size(); ++i)
  {
    remove(i);
  }
}

for (int i{0};i<rhs.size();i++)
{
  curr=curr->next;
   insert(curr->tal);

}
  curr=nullptr;
  return *this;

  }

Sorted_List::Sorted_List(Sorted_List const& L):Sorted_List{}
{
  *this=L;
}

void Sorted_List::insert(int  data)
{
  Node* curr=first;
  Node* p1=new Node;
  p1->tal=data;

while (curr->next->next)
  {
    curr=curr->next;
    if (p1->tal<=curr->tal)
      {
      p1->next=curr;
      p1->prev=curr->prev;
      curr->prev->next=p1;
      curr->prev=p1;
      return;
    }

  }
    p1->next=last;
    p1->prev=curr;
    curr->next=p1;
    last->prev=p1;

    return;
}




Sorted_List::Node::~Node()
{
  if(next)
  {
    delete next;
  }

}


int Sorted_List::get_index(int index)const
{

  Node *curr=first;
  int ret;
if(index>size() || index==0)
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
 if(index>size() || index==0)
{
throw logic_error("index utanför listan");

}
else
{
for(int i{0}; i<index; ++i)
{

  precurr=curr;
  curr=curr->next;

}

curr->next->prev=precurr;
precurr->next=curr->next;
curr->next=nullptr;
curr->prev=nullptr;//länkar ihop listan innan man raderar "curr"
delete curr;

}
}




void Sorted_List::sort()
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

int Sorted_List::size() const
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

 stringstream Sorted_List::print(Sorted_List const& L)const
{
  stringstream ss;
  for (int i{0}; i<L.size();i++)
  {
    ss<<L.get_index(i);
  }
  return ss;
  }

  void Sorted_List::printny(Sorted_List const& L)const
 {

    for (int i{1}; i<L.size()+1;i++)
    {
      cout<<L.get_index(i);
    }
   }

// Node* Sorted_List::get_indexptr(int index)
// {
//   Node* indexptr=first;
//
//   for (int i{0}; i<index; ++i)
//     {
//       indexptr=indexptr->next;
//     }
//   return indexptr;
//   }
