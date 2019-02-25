#include "catch.hpp"
#include "Sorted_List.h"

//Länkad lista
using namespace std;

TEST_CASE("empty list")
{
  Sorted_List S{};
  CHECK(S.is_empty());
}

TEST_CASE("Filled list")
{
      Sorted_List L{43,3,3,3,3,3};
      CHECK_FALSE(L.is_empty());
      CHECK(L.get_index(1)==3);
      CHECK(L.get_index(2)==3);
      CHECK(L.get_index(3)==3);
      CHECK(L.get_index(4)==3);
      CHECK(L.get_index(5)==3);
      CHECK(L.get_index(6)==43);
}

TEST_CASE("Check index")
{
Sorted_List L{5,3,7};
CHECK(L.get_index(1)==7);
CHECK(L.get_index(2)==3);
CHECK(L.get_index(3)==5);

}
