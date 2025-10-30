## Core Problem

The challenge is to make a sort function but dynamically using function pointer

### Brainstorming

1. Create 2 function comparison function, ascending and descending.
2. Create sort function that accept 3 params, arr pointer, length of arr, the pointer to comparison function
3. Use simple sorting algorithm, the buble short

### Issues I Faced

I still faced confusion about the function pointer written, it's so unclear i think

```c
int (*diff)(int, int)
```

See that, too complicated i think, but i believe i will get through it.

### Final Code

[c1-sort-function-pointer.c](../../src/section-18/c1-sort-function-pointer.c)
