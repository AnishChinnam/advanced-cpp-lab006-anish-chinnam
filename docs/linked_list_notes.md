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

## Implementation notes: pointer management and sentinel design

### Singly linked list

- The list owns every node it allocates with `new`. Each removal (`pop_front`, `pop_back`) unlinks a node first, then `delete`s it, then decrements `size_`, so the list is never left pointing at freed memory.
- `pop_back` must walk to the second-to-last node because a singly linked node has no `prev` pointer. That makes it O(n). The one-node case is handled separately so `head_` gets reset to `nullptr`.
- `clear()` calls `pop_front()` until the list is empty, and the destructor calls `clear()`, so every node is freed exactly once.
- The copy constructor makes a deep copy: it allocates a new node for each value and keeps a local tail pointer so the copy runs in O(n) and preserves order. Copying only the `head_` pointer would make two lists share and double-free the same nodes.
- Assignment uses copy-and-swap. A temporary copy is built first; if that throws, the target list is untouched. The temporary's destructor then frees the old nodes.

### Doubly linked list with sentinels

- `header_` and `trailer_` are dummy nodes that never hold real data. An empty list is `header_ <-> trailer_`.
- Because every real node always has a non-null `prev` and `next`, insertion and removal reduce to two helpers with no special cases:
  - `insert_between(value, before, after)` sets the new node's `prev`/`next`, then updates `before->next` and `after->prev`.
  - `remove_node(node)` links `node->prev` and `node->next` to each other, then deletes `node`.
- `push_front` inserts between `header_` and `header_->next`; `push_back` inserts between `trailer_->prev` and `trailer_`. Both pops are O(1).
- Traversal starts at `header_->next` and stops at `trailer_`, so sentinels are never treated as data.
- The destructor clears the data nodes and then deletes both sentinels. The copy constructor creates its own sentinels before appending copies of the other list's values.
- `front()` and `back()` throw `std::out_of_range` on an empty list instead of returning a sentinel's placeholder value.

### Verification

`make test` passes all 8 test cases (42 assertions), and running the test binary under `valgrind --leak-check=full` reports no leaks.
