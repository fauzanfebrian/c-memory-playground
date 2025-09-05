### Core Problem

The problem/challenge from Vlad is to rebuild new realloc function from scratch, and i would do that in my way, so then
i could deeply understand about this Dynamic Memory Allocation (DMA).

### Idea

My first thought from this problem is to using memcpy, but i dont know how that really works, then i should deep dive
into it first.

#### Pseudo Code from ChatGPT

```c
void *memcpy(void *dest, const void *src, size_t n) {
    // unsigned char used cause C standard guarantee that byte has no sign-extension
    // and also that an object representation from any data types.
    unsigned char *d = dest;
    const unsigned char *s = src;

    for (size_t i = 0; i < n; i++) {
        d[i] = s[i];   // copy byte by byte
    }

    return dest;
}
```

From this pseudocode, i've an idea to build my own memcpy too, so there are no external/built-in function that i used.
And here's my own realloc implementation:

```c
void *myRealloc(void *srcBlock, size_t oldMemSize, size_t newMemSize) {
    // allocate new memory
    unsigned char *newBlock = malloc(newMemSize);
    if (newBlock == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < oldMemSize && i < newMemSize; i++) {
        newBlock[i] = ((unsigned char *)srcBlock)[i];
    }

    free(srcBlock);

    return (void *)newBlock;
}
```

This code can be accessed at [c3-realloc.c](../../src/section-7/c3-realloc.c).
