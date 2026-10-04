# Lab 6 — Linked Lists in C++

## Course: CS 20 — Advanced Programming with C++

This lab introduces the fundamental linked-list data structures used in data structures courses.

## Learning goals

Students should be able to:

- implement a generic singly linked list;
- implement a generic doubly linked list;
- manage dynamic memory correctly;
- reason about pointer manipulation;
- understand sentinel nodes and boundary conditions;
- develop and run unit tests for list behavior.

## Required structures

### 1. Generic singly linked list

Implement:

- `SNode<T>`
- `SLinkedList<T>`
- insertion at front and back
- removal from front and back
- `front()`, `size()`, `empty()`, traversal, search
- constructor and destructor
- correct dynamic memory management

### 2. Generic doubly linked list

Implement:

- `DNode<T>`
- `DLinkedList<T>`
- header and trailer sentinel nodes
- insertion at front and back
- removal from front and back
- `front()`, `back()`, `size()`, `empty()`, traversal, search
- correct `prev`/`next` pointer management
- constructor and destructor

## Required behavior

The final code should support:

- inserting values at the front and back;
- removing the first and last node safely;
- retrieving the first and last value;
- searching for a value;
- reporting size and emptiness;
- constructing and copying lists correctly;
- avoiding memory leaks.

## Build and test

```bash
make test
```

## Suggested challenge

Do not rely on `std::list` or other standard library containers for this assignment. The goal is to understand pointer-based list structure and memory ownership.

## Deliverables

Students should submit:

1. a working header implementation for the singly linked list;
2. a working implementation for the doubly linked list;
3. passing tests for all required list behaviors;
4. a brief explanation of pointer management and sentinel-node design.
