#pragma once

#include <cstddef>
#include <stdexcept>
#include <utility>
#include <vector>

template <typename T>
struct DNode {
    T value;
    DNode* prev;
    DNode* next;

    explicit DNode(const T& v, DNode* p = nullptr, DNode* n = nullptr)
        : value(v), prev(p), next(n) {}
};

template <typename T>
class DLinkedList {
public:
    DLinkedList();
    ~DLinkedList();
    DLinkedList(const DLinkedList& other);
    DLinkedList& operator=(const DLinkedList& other);

    void push_front(const T& value);
    void push_back(const T& value);
    bool pop_front();
    bool pop_back();

    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
    std::size_t size() const noexcept;
    bool empty() const noexcept;
    bool contains(const T& value) const;
    std::vector<T> to_vector() const;
    void clear();

private:
    // Link a new node between two existing adjacent nodes.
    void insert_between(const T& value, DNode<T>* before, DNode<T>* after);
    // Unlink and delete a real (non-sentinel) node.
    void remove_node(DNode<T>* node);

    DNode<T>* header_;
    DNode<T>* trailer_;
    std::size_t size_;
};

template <typename T>
DLinkedList<T>::DLinkedList() : size_(0) {
    header_ = new DNode<T>(T(), nullptr, nullptr);
    trailer_ = new DNode<T>(T(), nullptr, nullptr);
    header_->next = trailer_;
    trailer_->prev = header_;
}

// Destructor: free all data nodes, then the two sentinels.
template <typename T>
DLinkedList<T>::~DLinkedList() {
    clear();
    delete header_;
    delete trailer_;
}

// Copy constructor: build fresh sentinels, then append each value in order.
template <typename T>
DLinkedList<T>::DLinkedList(const DLinkedList& other) : size_(0) {
    header_ = new DNode<T>(T(), nullptr, nullptr);
    trailer_ = new DNode<T>(T(), nullptr, nullptr);
    header_->next = trailer_;
    trailer_->prev = header_;
    for (DNode<T>* cur = other.header_->next; cur != other.trailer_; cur = cur->next) {
        push_back(cur->value);
    }
}

// Copy assignment via copy-and-swap.
template <typename T>
DLinkedList<T>& DLinkedList<T>::operator=(const DLinkedList& other) {
    if (this != &other) {
        DLinkedList<T> temp(other);
        std::swap(header_, temp.header_);
        std::swap(trailer_, temp.trailer_);
        std::swap(size_, temp.size_);
    }
    return *this;
}

template <typename T>
void DLinkedList<T>::insert_between(const T& value, DNode<T>* before, DNode<T>* after) {
    DNode<T>* node = new DNode<T>(value, before, after);
    before->next = node;
    after->prev = node;
    ++size_;
}

template <typename T>
void DLinkedList<T>::remove_node(DNode<T>* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
    --size_;
}

template <typename T>
void DLinkedList<T>::push_front(const T& value) {
    insert_between(value, header_, header_->next);
}

template <typename T>
void DLinkedList<T>::push_back(const T& value) {
    insert_between(value, trailer_->prev, trailer_);
}

template <typename T>
bool DLinkedList<T>::pop_front() {
    if (empty()) {
        return false;
    }
    remove_node(header_->next);
    return true;
}

template <typename T>
bool DLinkedList<T>::pop_back() {
    if (empty()) {
        return false;
    }
    remove_node(trailer_->prev);
    return true;
}

template <typename T>
T& DLinkedList<T>::front() {
    if (empty()) {
        throw std::out_of_range("DLinkedList is empty");
    }
    return header_->next->value;
}

template <typename T>
const T& DLinkedList<T>::front() const {
    if (empty()) {
        throw std::out_of_range("DLinkedList is empty");
    }
    return header_->next->value;
}

template <typename T>
T& DLinkedList<T>::back() {
    if (empty()) {
        throw std::out_of_range("DLinkedList is empty");
    }
    return trailer_->prev->value;
}

template <typename T>
const T& DLinkedList<T>::back() const {
    if (empty()) {
        throw std::out_of_range("DLinkedList is empty");
    }
    return trailer_->prev->value;
}

template <typename T>
std::size_t DLinkedList<T>::size() const noexcept {
    return size_;
}

template <typename T>
bool DLinkedList<T>::empty() const noexcept {
    return size_ == 0;
}

template <typename T>
bool DLinkedList<T>::contains(const T& value) const {
    for (DNode<T>* cur = header_->next; cur != trailer_; cur = cur->next) {
        if (cur->value == value) {
            return true;
        }
    }
    return false;
}

template <typename T>
std::vector<T> DLinkedList<T>::to_vector() const {
    std::vector<T> values;
    values.reserve(size_);
    for (DNode<T>* cur = header_->next; cur != trailer_; cur = cur->next) {
        values.push_back(cur->value);
    }
    return values;
}

template <typename T>
void DLinkedList<T>::clear() {
    while (pop_front()) {
    }
}
