## Core Problem

The challenge is to allocate a 2D array in a function, then pass it by reference to the parameter of the calling
function.

### Brainstorming

Create a function that allocate a 2D array dynamically, then should receive three params:

1. A pointer to a pointer to a pointer (to hold the address of the 2D array)
2. A pointer that hold number of rows
3. A pointer that hold number of columns

### Issues I Faced

When dealing with a pointer to a pointer to a pointer, I faced some issues with dereferencing and allocating memory
correctly, when i tried to assign a columns of memory allocated to the pointer, i mistakenly dereferenced it, like this:

```c
*array2D[i]  =calloc(*columns, sizeof(int));
```

This dereferencing is incorrect and caused a seg fault because this implementation is the same as`*(ref[i])`. The
correct dereferencing is `(*ref)[i]`: dereference first, then access the index.

### Final Code

[c3-2d-matrix-allocation-referrence.](../../src/section-9/c3-2d-matrix-allocation-referrence.)
