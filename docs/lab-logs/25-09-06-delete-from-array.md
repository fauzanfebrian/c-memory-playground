### Core Problem

Today's challenge is the opposite of yesterday's challenge, which is to delete an element from a generic array at a
certain index.

### Implementation

I just do a reverse logic from the insert function, so there are no real catch today, just copy and paste and little bit
of tweak.

```c
void *deleteFromArray(void *arr, size_t elementCount, size_t elementSize, size_t removeIndex) {
    // allocate new memory
    unsigned char *newArr = malloc(elementCount - elementSize);
    if (newArr == NULL) {
        return NULL;
    }

    int arrIndex = 0;

    for (size_t i = 0; i < elementCount; i++) {
        if (i / elementSize == removeIndex) {
            continue;
        }

        newArr[arrIndex] = ((unsigned char *)arr)[i];
        arrIndex++;
    }

    return (void *)newArr;
}
```

### Reflection

This is a pretty straightforward challenge, just do the reverse logic from the insert function. I think this is a good
exercise to understand how to manipulate memory in C, especially with generic types.

### File

[c5-remove-from-array-function.c](../../src/section-8/c5-remove-from-array-function.c)
