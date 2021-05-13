#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "Sort.hpp"
#include "SortFixed.hpp"

#include "TestingHelpers.hpp"


TEST_CASE( "INTS", "[sort]"){
    SECTION("ALREADY SORTED"){
        int a[11] = {1,2,3,4,5,6,7,8,9,10};
        SortFixed<int>::QuickSort(a, 10);
        CHECK( il<int>({1,2,3,4,5,6,7,8,9,10}) ==  a );
    }
    SECTION("INVERTED"){
        int a[11] = {10,9,8,7,6,5,4,3,2,1};
        SortFixed<int>::QuickSort(a, 10);
        CHECK( il<int>({1,2,3,4,5,6,7,8,9,10}) ==  a );
    }
}
