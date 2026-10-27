# Week 3: Stack from scratch (C++)

An array-backed Stack built without std::stack, using raw pointers and
manual memory management (new[] /delete[]).
## Design
- 'data': pointer to a heap-allocated int array
- 'capacity': current size of that array
- 'count': how many elements are actually stored (top is at count -)
- 'grow()': doubles capacity and doubles elements over when the array is full
## Complexity
| Op | Time |
| --- | --- |
| push | amortized 0(1) |
| pop / peek /isEmpty | 0(1) |
## Run
g++ stack.cpp -o stack && ./stack
Prints "Stacks test passed" if every test succeeds.

# What broke

- pop() on an empty stack originally read data[-1] silently instead of failing, returning garbage (0) with no warning. Fixed by throwing std::out_of_range when the stack is empty.
- push() past capacity originally wrote past the end of the allocated array (a buffer overflow) instead of growing it. Fized by adding grow(), which doubles capacity, copies existing elements, and frees the old array. 

## Queue (circular buffer)

A FIFO queue of `int` built on a dynamic array. `head` marks the front, and indices wrap around with `%`, so `dequeue` is O(1) with no shifting.

| Operation | Time | Notes |
|---|---|---|
| `enqueue(v)` | O(1) amortized | Doubles capacity when full |
| `dequeue()` | O(1) | Throws `std::underflow_error` if empty |
| `front()` | O(1) | Throws `std::underflow_error` if empty |
| `empty()`, `size()`, `clear()` | O(1) | |

**Files:** `queue.hpp` (the class), `test_queue.cpp` (assert-based tests).

**Build and run:**

```
g++ -std=c++17 -Wall -Wextra -g -fsanitize=address,undefined test_queue.cpp -o test_queue && ./test_queue
```

Expected output: `All queue tests passed`

**What the tests cover:** FIFO ordering, growth past the initial capacity, index wraparound (100 enqueue/dequeue cycles), `clear()`, and the empty-queue exception.

## Singly Linked List

Nodes allocated with `new`, each pointing to the next. The destructor frees every node.

| Operation | Time |
|---|---|
| `push_front(v)` | O(1) |
| `push_back(v)` | O(n) |
| `pop_front()` | O(1) |
| `contains(v)`, `at(i)`, `remove(v)` | O(n) |

**Build and run:**

```
g++ -std=c++17 -Wall -Wextra -g -fsanitize=address,undefined test_linked_list.cpp -o test_linked_list && ./test_linked_list
```
