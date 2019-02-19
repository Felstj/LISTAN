#include "catch.hpp"
#include "Sorted_List.h"

//Länkad lista
using namespace std;

TEST_CASE("empty list")
{
  Sorted_List S{};
  CHECK(S.is_empty());
}

TEST_CASE("filled list")
{
  Sorted_List S{7};
  CHECK_FALSE(S.is_empty());
  SECTION("Fler parametrar")
  Sorted_List S{1,2,3,4};
  CHECK_FALSE(S.is_empty());
}
