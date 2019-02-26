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


int Sorted_List::get_index(int index)
{
  Node *curr=first;
  int ret;
  if(is_empty())
  {
    return 0;

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
else
{
for(int i{0}; i<index; ++i)
{
  precurr=curr;
  curr=curr->next;
}

curr->next->prev=precurr;
precurr->next=curr->next; //länkar ihop listan innan man raderar "curr"
delete curr;

}



}

void Sorted_List::sort()
{
    Node* curr=first;
    Node* starter;
    int max{0};

    while(curr->next)
    {
      curr =curr->next; //kanske längst ner?
      max = curr->tal;
      starter = first->next; //för inre loop

        while(starter->next)
        {
          //hitta den nod som har störst tal
          if (max<starter->tal)
          {
            max = starter->tal;

          }
          starter = starter->next;
        }
        //sätt in talet i rätt ordning
        insert(max);
        // flytta om alla pekare
         //listan blir nu hel men man tappar en nod ur den länkade listan.
        curr->prev=curr->next;
        curr->next=curr->prev;
        //ta bort den nod som curr pekar på.
        delete curr;
}
}
