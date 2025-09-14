## Core Problem

Vlad gave a challenge to swap the rows and columns of a 2D matrix. there are 2 functions to implement:

-   swap 2 rows
-   swap 2 columns

### Brainstorming

I Just thinking for the 2 rows is the pointer manipulation, and for the 2 columns is the value swapping.

-   The 2 rows, i can change or swap the pointers that point to each row.
-   The 2 columns, i have to swap the values between the 2 columns.

### Implementation

For the swap rows, at first, i think i will implement the `temp` method, but i think that's too easy, and then i
challenge myself to use the `XOR` method, but i can't do it regularly just like swap the ordinary integer because it's a
pointer, then i asked to ChatGPT how do i swap a pointer, then he give me this code:

```c
*a = (int *)((uintptr_t)(*a) ^ (uintptr_t)(*b));
*b = (int *)((uintptr_t)(*a) ^ (uintptr_t)(*b));
*a = (int *)((uintptr_t)(*a) ^ (uintptr_t)(*b));
```

It turns out i should cast the pointer to `uintptr_t` first, then do the `XOR` operation, and then cast it back to the
original pointer type, this is because the pointer is not an number, so we need to cast it to number type first.

And for the swap columns, it's just a simple value swapping.

### Final Code

[c1-swap-matrix.c](../../src/section-9/c1-swap-matrix.c)
