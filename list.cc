#include "catch.hpp"
#include "list.h"

List::List()
:first{}, last{}, sentf{}, sentl{}
{
  first = &sentf; //first obectet i classen pekar nu på den första sentinellen
  last = &sentl;  //last obectet i classen pekar nu på den sista sentinellen
  sentf.prev = nullptr;
  sentl.next = nullptr;
  sentf.next = sentl.prev;
  sentl.prev = sentf.next;
  // int var;
  // int* ptri;
  // var = 42;
  // ptri = &var;
}
