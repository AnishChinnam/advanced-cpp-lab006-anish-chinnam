#include "singly_linked_list.h"
#include "doubly_linked_list.h"

#include <iostream>
#include <string>
#include <vector>

template <typename T>
void print(const std::string& label, const std::vector<T>& values) {
    std::cout << label << ": [";
    for (std::size_t i = 0; i < values.size(); ++i) {
        std::cout << (i ? ", " : "") << values[i];
    }
    std::cout << "]\n";
}

int main() {
    SLinkedList<int> s;
    s.push_back(1);
    s.push_back(2);
    s.push_front(0);
    print("Singly linked list", s.to_vector());
    s.pop_back();
    print("After pop_back", s.to_vector());

    DLinkedList<std::string> d;
    d.push_back("b");
    d.push_front("a");
    d.push_back("c");
    print("Doubly linked list", d.to_vector());
    std::cout << "front=" << d.front() << " back=" << d.back()
              << " size=" << d.size() << "\n";
    return 0;
}
