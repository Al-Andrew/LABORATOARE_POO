#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <algorithm>
#include "Sort.hpp"
#include "SortFixed.hpp"

#include "TestingHelpers.hpp"


TEST_CASE( "INTS", "[sort]"){
    SECTION("ALREADY SORTED"){
        int a[10] = {1,2,3,4,5,6,7,8,9,10};
        SortFixed<int>::QuickSort(a, 10);
        CHECK( il<int>({1,2,3,4,5,6,7,8,9,10}) ==  a );
    }
    SECTION("INVERTED"){
        int a[10] = {10,9,8,7,6,5,4,3,2,1};
        SortFixed<int>::QuickSort(a, 10);
        CHECK( il<int>({1,2,3,4,5,6,7,8,9,10}) ==  a );
    }
    SECTION("SHUFFLED"){
        int a[10] = {1,2,3,4,5,6,7,8,9,10};

        std::random_device rd;
        std::mt19937 g(rd());

        std::shuffle(std::begin(a), std::end(a), g);

        SortFixed<int>::QuickSort(a, 10);
        CHECK( il<int>({1,2,3,4,5,6,7,8,9,10}) ==  a );
    }
}

TEST_CASE( "FLOATS", "[sort]"){
    SECTION("ALREADY SORTED"){
        float a[10] = {0.5f,1.f,1.5f,2.f,2.5f,3.f,3.5f,4.f,4.5f,5.f};
        SortFixed<float>::QuickSort(a, 10);
        CHECK( il<float>({0.5f,1.f,1.5f,2.f,2.5f,3.f,3.5f,4.f,4.5f,5.f}) ==  a );
    }
    SECTION("INVERTED"){
        float a[10] = {5.f,4.5f,4.f,3.5f,3.f,2.5f,2.f,1.5f,1.f,0.5f};
        SortFixed<float>::QuickSort(a, 10);
        CHECK( il<float>({0.5f,1.f,1.5f,2.f,2.5f,3.f,3.5f,4.f,4.5f,5.f}) ==  a );
    }
    SECTION("SHUFFLED"){
        float a[10] = {0.5f,1.f,1.5f,2.f,2.5f,3.f,3.5f,4.f,4.5f,5.f};

        std::random_device rd;
        std::mt19937 g(rd());

        std::shuffle(std::begin(a), std::end(a), g);

        SortFixed<float>::QuickSort(a, 10);
        CHECK( il<float>({0.5f,1.f,1.5f,2.f,2.5f,3.f,3.5f,4.f,4.5f,5.f}) ==  a );
    }
}
