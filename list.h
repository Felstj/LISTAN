#ifndef LIST_H
#define LIST_H

class List
{
public:
  List();
private:
  class Node
  {
  public:
      int* next;
      int num;
      int* prev;
    private:
  };
  Node* first; //accessblock i classen
  Node* last; //accessblock i classen
  Node sentf; //sentinell block i lista
  Node sentl; //sentinell block i lista.
};


#endif
