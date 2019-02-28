#include "catch.hpp"
#include "Sorted_List.h"
#include <iostream>
#include <sstream>

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
CHECK(L.get_index(1)==3);
CHECK(L.get_index(2)==5);
CHECK(L.get_index(3)==7);

}

TEST_CASE("sorted list?")
{
Sorted_List L{4,3,7};

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

TEST_CASE("TILLDELNING")
{
Sorted_List L{3,2,6};
Sorted_List LC{};
LC=L;
CHECK(LC.get_index(1)==2);
CHECK(LC.get_index(2)==3);


SECTION("KOPIERING")
{
  Sorted_List P{2,7,3};
  Sorted_List PC{P};
  CHECK(PC.get_index(2)==3);
  CHECK(PC.get_index(3)==7);
  PC.insert(10);
  CHECK(PC.get_index(4)==10);
}

}


TEST_CASE("utskrift")
{
Sorted_List L{1,5,7,10};
  cout<<" "<<'\n';
  L.printny(L);

}
#if 0
#endif
