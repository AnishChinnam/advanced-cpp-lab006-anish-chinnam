#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "singly_linked_list.h"
#include "doubly_linked_list.h"

#include <stdexcept>
#include <string>
#include <vector>

TEST_CASE("Singly linked list starts empty and supports front insertion") {
    SLinkedList<int> list;
    REQUIRE(list.empty());
    REQUIRE(list.size() == 0u);

    list.push_front(10);
    list.push_front(20);
    list.push_back(30);

    REQUIRE(list.size() == 3u);
    REQUIRE(list.front() == 20);
    REQUIRE(list.contains(10));
    REQUIRE(list.contains(30));

    auto values = list.to_vector();
    REQUIRE(values.size() == 3u);
    REQUIRE(values[0] == 20);
    REQUIRE(values[1] == 10);
    REQUIRE(values[2] == 30);
}

TEST_CASE("Singly linked list pop operations remove correctly") {
    SLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    REQUIRE(list.pop_front());
    REQUIRE(list.front() == 2);
    REQUIRE(list.pop_back());

    auto values = list.to_vector();
    REQUIRE(values.size() == 1u);
    REQUIRE(values[0] == 2);
    REQUIRE(list.size() == 1u);
}

TEST_CASE("Singly linked list throws on front when empty") {
    SLinkedList<std::string> list;
    REQUIRE_THROWS_AS(list.front(), std::out_of_range);
}

TEST_CASE("Singly linked list copy constructor and assignment work") {
    SLinkedList<int> original;
    original.push_back(5);
    original.push_back(8);
    original.push_back(9);

    SLinkedList<int> copy(original);
    REQUIRE(copy.size() == original.size());
    REQUIRE(copy.to_vector() == original.to_vector());

    SLinkedList<int> assigned;
    assigned = original;
    REQUIRE(assigned.to_vector() == original.to_vector());
}

TEST_CASE("Doubly linked list starts empty and supports front/back operations") {
    DLinkedList<int> list;
    REQUIRE(list.empty());
    REQUIRE(list.size() == 0u);

    list.push_front(5);
    list.push_back(10);
    list.push_front(2);

    REQUIRE(list.size() == 3u);
    REQUIRE(list.front() == 2);
    REQUIRE(list.back() == 10);
    REQUIRE(list.contains(5));
    REQUIRE(list.contains(10));

    auto values = list.to_vector();
    REQUIRE(values.size() == 3u);
    REQUIRE(values[0] == 2);
    REQUIRE(values[1] == 5);
    REQUIRE(values[2] == 10);
}

TEST_CASE("Doubly linked list maintains prev/next pointers with sentinel nodes") {
    DLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    REQUIRE(list.front() == 1);
    REQUIRE(list.back() == 3);
    REQUIRE(list.pop_front());
    REQUIRE(list.front() == 2);
    REQUIRE(list.pop_back());
    REQUIRE(list.back() == 2);
    REQUIRE(list.size() == 1u);
}

TEST_CASE("Doubly linked list throws on empty access") {
    DLinkedList<std::string> list;
    REQUIRE_THROWS_AS(list.front(), std::out_of_range);
    REQUIRE_THROWS_AS(list.back(), std::out_of_range);
}

TEST_CASE("Doubly linked list copy constructor and assignment work") {
    DLinkedList<int> original;
    original.push_back(4);
    original.push_back(6);
    original.push_back(9);

    DLinkedList<int> copy(original);
    REQUIRE(copy.to_vector() == original.to_vector());

    DLinkedList<int> assigned;
    assigned = original;
    REQUIRE(assigned.to_vector() == original.to_vector());
}
