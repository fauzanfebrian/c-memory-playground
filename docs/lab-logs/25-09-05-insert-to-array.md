### Main Problem

Vlad gave a challenge to insert a generic value into a generic array at certain index. That generic is the real deal.

### Brainstorming

1. The function should accept generic array, its total byte size, the current latest index, the index to insert at, and
   the value to insert.
2. From the total byte size and the latest index i can calculate the size of each element.
3. I should growing the array by one element to make space for the new element.
4. Return the new array.

### Implementation

```c
void *insertValueToArray(void *arr, size_t elementCount, size_t elementSize, size_t insertIndex, void *insertValue) {
    size_t newMemSize = elementCount + elementSize;

    // allocate new memory
    unsigned char *newArr = malloc(newMemSize);
    if (newArr == NULL) {
        return NULL;
    }

    int arrIndex = 0;

    for (size_t i = 0; i < newMemSize; i++) {
        if (i / elementSize == insertIndex) {
            newArr[i] = ((unsigned char *)insertValue)[i % elementSize];
            continue;
        }

        newArr[i] = ((unsigned char *)arr)[arrIndex];
        arrIndex++;
    }

    // make this outside of this function, cause i dunno where the array came from.
    //  it may came from Stack memory, which is this function can do nothing about it.
    // free(arr);

    return (void *)newArr;
}
```

I realized the logic is kinda similar into the `realloc` function that i wrote before (a challenge from Vlad too). But
there is tweak for inserting new value.

```c
if (i / elementSize == insertIndex) {
   newArr[i] = ((unsigned char *)insertValue)[i % elementSize];
   continue;
}
```

This part is the key logic of inserting new value, check the index of loop, if the result of division is equal to the
`insertIndex` then insert the new value, and continue to the next loop.

### File

[c4-insert-to-array-function.c](../../src/section-8/c4-insert-to-array-function.c)
