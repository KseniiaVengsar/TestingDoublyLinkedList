#include <iostream>
#include "TestingDoublyLinkedList.cpp"
#include "Catch2/catch_test_macros.hpp"
#include "Catch2/catch_session.hpp"

TEST_CASE("Empty function on an empty list should return true", "[L1]") {
    List myList;
    REQUIRE(myList.Empty() == true);
    
}


TEST_CASE("Size function should return the correct number of elements", "[L2]") {
    List myList;
    REQUIRE(myList.Size() == 0);

    myList.PushFront(1);
    myList.PushFront(2);
    myList.PushFront(3);

    REQUIRE(myList.Size() == 3);
}

TEST_CASE("Clear function should remove all elements", "[L3]") {
    List myList;
    myList.PushFront(1);
    myList.PushFront(2);
    myList.PushFront(3);

    myList.Clear();

    REQUIRE(myList.Size() == 0);
    REQUIRE(myList.Empty() == true);
}
int main() {
    return Catch::Session().run();
}