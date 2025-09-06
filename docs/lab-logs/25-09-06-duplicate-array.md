### Core Problem

Vlad gave a challenge to duplicate an array, and pass the duplicated array to a function's parameter. This should be a
generic function that works with any type of array.

### Brainstorming

1. **Parameters**:

    - A pointer to the original array.
    - The actual size of the array.
    - A pointer that point to the memory that hold the duplicated array.

2. Use the `realloc` logic to allocate memory for the duplicated array, avoid using `memcpy` for better understanding.

### Implementation

```c
void duplicateArray(void *arr, size_t size, void **arrLoc) {
    // allocate new memory
    unsigned char *newBlock = malloc(size);
    if (newBlock == NULL) {
        return;
    }

    for (size_t i = 0; i < size; i++) {
        newBlock[i] = ((unsigned char *)arr)[i];
    }

    *arrLoc = (void *)newBlock;
}
```

Just copy byte by byte, and assign the new memory block to the pointer that passed by reference.

### File

[c6-duplicate-array-function.c](../../src/section-8/c6-duplicate-array-function.c)
