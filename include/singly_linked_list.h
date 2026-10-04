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

// Destructor: release every node the list owns.
template <typename T>
SLinkedList<T>::~SLinkedList() {
    clear();
}

// Copy constructor: deep copy, preserving order. A tail pointer keeps it O(n).
template <typename T>
SLinkedList<T>::SLinkedList(const SLinkedList& other) : head_(nullptr), size_(0) {
    SNode<T>* tail = nullptr;
    for (SNode<T>* cur = other.head_; cur != nullptr; cur = cur->next) {
        SNode<T>* node = new SNode<T>(cur->value);
        if (tail == nullptr) {
            head_ = node;
        } else {
            tail->next = node;
        }
        tail = node;
        ++size_;
    }
}

// Copy assignment: copy-and-swap gives self-assignment safety and the strong
// exception guarantee.
template <typename T>
SLinkedList<T>& SLinkedList<T>::operator=(const SLinkedList& other) {
    if (this != &other) {
        SLinkedList<T> temp(other);
        std::swap(head_, temp.head_);
        std::swap(size_, temp.size_);
    }
    return *this;
}

template <typename T>
void SLinkedList<T>::push_front(const T& value) {
    head_ = new SNode<T>(value, head_);
    ++size_;
}

template <typename T>
void SLinkedList<T>::push_back(const T& value) {
    SNode<T>* node = new SNode<T>(value);
    if (head_ == nullptr) {
        head_ = node;
    } else {
        SNode<T>* cur = head_;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = node;
    }
    ++size_;
}

template <typename T>
bool SLinkedList<T>::pop_front() {
    if (head_ == nullptr) {
        return false;
    }
    SNode<T>* old = head_;
    head_ = head_->next;
    delete old;
    --size_;
    return true;
}

template <typename T>
bool SLinkedList<T>::pop_back() {
    if (head_ == nullptr) {
        return false;
    }
    if (head_->next == nullptr) {
        delete head_;
        head_ = nullptr;
        --size_;
        return true;
    }
    SNode<T>* cur = head_;
    while (cur->next->next != nullptr) {
        cur = cur->next;
    }
    delete cur->next;
    cur->next = nullptr;
    --size_;
    return true;
}

template <typename T>
T& SLinkedList<T>::front() {
    if (empty()) {
        throw std::out_of_range("SLinkedList is empty");
    }
    return head_->value;
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
    return size_;
}

template <typename T>
bool SLinkedList<T>::empty() const noexcept {
    return size_ == 0;
}

template <typename T>
bool SLinkedList<T>::contains(const T& value) const {
    for (SNode<T>* cur = head_; cur != nullptr; cur = cur->next) {
        if (cur->value == value) {
            return true;
        }
    }
    return false;
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
    while (pop_front()) {
    }
}
