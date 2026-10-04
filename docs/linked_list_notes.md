# Linked List Lab Notes

This lab focuses on understanding how linked-list structures behave in C++.

## Singly linked list goals

Students should be able to:

- add nodes to the front and back;
- remove from the front and back;
- maintain a correct size counter;
- traverse the list safely;
- search for an element.

## Doubly linked list goals

Students should be able to:

- use sentinel header and trailer nodes;
- maintain correct previous and next links;
- add and remove from both ends;
- avoid breaking the list while deleting nodes.

## Important design points

- The singly linked list stores only a head pointer and a size counter.
- The doubly linked list uses a header and trailer sentinel to simplify edge-case logic.
- Both implementations must avoid memory leaks and must keep the list consistent after every update.
