#include "Sorted_List.h"
#include <vector>
#include <initializer_list>

using namespace std;
Sorted_List::Sorted_List()
:first{}, last{}, sentf{}, sentl{}
{
  first = &sentf; //first obectet i classen pekar nu på den första sentinellen
  last = &sentl;  //last obectet i classen pekar nu på den sista sentinellen
  sentf.prev = nullptr;
  sentl.next = nullptr;
  sentf.next = &sentl.tal;
  sentl.prev = &sentf.tal;
}

bool Sorted_List::is_empty()
{
  if (sentf.next == &sentl.tal )
  {
    return true;
  }
  else
  {
    return false;
  }
}

 Sorted_List::Sorted_List(initializer_list<int> medlemmar)
 :first{},last{},sentf{},sentl{}, Lista{medlemmar}
{
  first = &sentf;
  last = &sentl;
  sentf.prev = nullptr;
  sentl.next = nullptr;
  //får för mig att detta är det ända denna konstuktorn skall göra
  //resten skall lösas på andra ställen.
  sort(Lista.begin(),Lista.end());
    int tmp;
    for (size_t i{0};i<Lista.size();++i)
    {

      tmp=Lista.at(i);
      insert(tmp);
    }
    //shitty comment;

}
void Sorted_List::insert(int  data)
{


  Node* p1= new Node; //allocerar och konstruerar classen Node i heapen
  p1->tal = data; //tilldela int delen i classen, var

  p1 -> next = &sentl.tal;
  p1 -> prev = sentl.prev;

  sentl.prev = &p1->tal;

  if(p1->*next==&sentl.tal)
  {
  sentf.next = &p1->tal;
  }

  delete p1;
}
