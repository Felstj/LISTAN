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

TEST_CASE("sorted list?")
{
Sorted_List L{4,3,7};
L.sortny();
CHECK(L.get_index(1)==3);
CHECK(L.get_index(2)==4);
CHECK(L.get_index(3)==7);
}

TEST_CASE("remove")
{
Sorted_List L{1};
L.remove(1);
CHECK(L.is_empty());
}

TEST_CASE("removemore")
{
Sorted_List L{1,5,7,4};
L.sortny();
CHECK(L.get_index(1)==1);
CHECK(L.get_index(2)==4);
CHECK(L.get_index(3)==5);
CHECK(L.get_index(4)==7);

L.remove(2);

CHECK(L.get_index(2)==5);
CHECK(L.get_index(3)==7);

}


TEST_CASE("size")
{
Sorted_List L{};
CHECK(L.size()==0);

SECTION("sizefilled")
{
Sorted_List J{1,5,8,2};
CHECK(J.size()==4);
}

SECTION("checkerror")
{
Sorted_List I{1,3,4};
CHECK_THROWS(I.get_index(5));
CHECK_THROWS(I.remove(7));

}
}
