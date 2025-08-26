### Core Problem

The challenge today is to write function to create dynamic array, the size is dynamic from user input, every time user
input a value, the array should resize or to be adjusted accordingly, until the input -1 is received, then it should
return an array and pass it's size.

### Brainstorming

1. Looping and listening every user input.
2. Create a function to handle dynamic array creation and resizing.
3. Avoid memory overhead by using a strategy to minimize reallocations.
4. Implement a way to return both the array and its size.

### Implementation

```c
void handleDynamicArray(int **arr, size_t *dynamicSize, size_t currentSize, int newValue) {
    if (currentSize > *dynamicSize) {
        if (*dynamicSize == 0) {
            *dynamicSize = 4;
        } else {
            *dynamicSize = (size_t)(*dynamicSize * SIZE_MULTIPLIER);
        }

        int *newArr = realloc(*arr, *dynamicSize * sizeof(int));
        if (!newArr) {
            printf("Error allocating memory\n");
            exit(1);
        }
        *arr = newArr;
    }

    (*arr)[currentSize - 1] = newValue;
}
```

This handler function take 4 parameters:

1. `int **arr`: A pointer to the dynamic array.
2. `size_t *dynamicSize`: The actual dynamic array, this to prevent memory overhead, the strategy of the reallocation.
3. `size_t currentSize`: The current number of elements in the array or we can say the actual size of the user input
   array.
4. `int newValue`: The new value to be added to the array.

At code above, we handle the dynamic array resizing and memory allocation. After the memory handling then we add the new
value to the array.

#### Limitation

In this implementation we have a few limitation like the `dynamicSize` that unused, this such a waste of memory. Then we
need to free them using this reallocation code:

```c
void handleFreeMultiplier(int **arr, size_t actualSize) {
    if (actualSize == 0) {
        *arr = NULL;
    }

    int *newTemp = realloc(*arr, actualSize * sizeof(int));
    if (newTemp) {
        *arr = newTemp;
    }
}
```

### File

This code can be accessed and modified at `src/section-7/c4-dynamic-array.c`
