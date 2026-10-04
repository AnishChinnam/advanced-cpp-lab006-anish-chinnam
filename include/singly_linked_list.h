#pragma once

#include <cstddef>
#include <stdexcept>
#include <utility>
#include <vector>

template <typename T>
struct SNode {
    T value;
    SNode* next;

    explicit SNode(const T& v, SNode* n = nullptr) : value(v), next(n) {}
};

template <typename T>
class SLinkedList {
public:
    SLinkedList();
    ~SLinkedList();
    SLinkedList(const SLinkedList& other);
    SLinkedList& operator=(const SLinkedList& other);

    void push_front(const T& value);
    void push_back(const T& value);
    bool pop_front();
    bool pop_back();

    T& front();
    const T& front() const;
    std::size_t size() const noexcept;
    bool empty() const noexcept;
    bool contains(const T& value) const;
    std::vector<T> to_vector() const;
    void clear();

private:
    SNode<T>* head_;
    std::size_t size_;
};

template <typename T>
SLinkedList<T>::SLinkedList() : head_(nullptr), size_(0) {}

template <typename T>
SLinkedList<T>::~SLinkedList() {
//TODO: Implement the destructor for the SLinkedList class
}

template <typename T>
SLinkedList<T>::SLinkedList(const SLinkedList& other) : head_(nullptr), size_(0) {
//TODO: Implement the copy constructor for the SLinkedList class
}

template <typename T>
SLinkedList<T>& SLinkedList<T>::operator=(const SLinkedList& other) {
//TODO: Implement the assignment operator for the SLinkedList class

}

template <typename T>
void SLinkedList<T>::push_front(const T& value) {
// TODO: Implement the push_front function for the SLinkedList class
}

template <typename T>
void SLinkedList<T>::push_back(const T& value) {
// TODO: Implement the push_back function for the SLinkedList class

}

template <typename T>
bool SLinkedList<T>::pop_front() {
// TODO: Implement the pop_front function for the SLinkedList class
}

template <typename T>
bool SLinkedList<T>::pop_back() {
// TODO: Implement the pop_back function for the SLinkedList class

}

template <typename T>
T& SLinkedList<T>::front() {
// TODO: Implement the front function for the SLinkedList class
    
}

template <typename T>
const T& SLinkedList<T>::front() const {
    if (empty()) {
        throw std::out_of_range("SLinkedList is empty");
    }
    return head_->value;
}

template <typename T>
std::size_t SLinkedList<T>::size() const noexcept {
// TODO: Implement the size function for the SLinkedList class
    
}

template <typename T>
bool SLinkedList<T>::empty() const noexcept {
// TODO: Implement the empty function for the SLinkedList class
    
}

template <typename T>
bool SLinkedList<T>::contains(const T& value) const {
// TODO: Implement the contains function for the SLinkedList class
    
}

template <typename T>
std::vector<T> SLinkedList<T>::to_vector() const {
    std::vector<T> values;
    values.reserve(size_);
    for (SNode<T>* current = head_; current != nullptr; current = current->next) {
        values.push_back(current->value);
    }
    return values;
}

template <typename T>
void SLinkedList<T>::clear() {
//TODO: Implement the clear function for the SLinkedList class
}
