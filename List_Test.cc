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
}
