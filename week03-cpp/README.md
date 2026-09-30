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
