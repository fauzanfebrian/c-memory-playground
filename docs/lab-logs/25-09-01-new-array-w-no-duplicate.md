### Core Problem

For today's problem, the challenge is to create a function that takes a sorted array as input and returns a new
heap-allocated array with all consecutive duplicate elements removed.

---

### My Approach: The One-Pass Dynamic Method

My initial strategy was to solve this in a single pass to be efficient with iterations. The logic is as follows:

1.  Iterate through the original array just once.
2.  Maintain a new, dynamically-sized array.
3.  If the current element from the original array is different from the last element added to our new array, it's
    unique and should be added.
4.  To accommodate the new element, resize the dynamic array using `realloc`. To minimize the number of `realloc` calls,
    I'll use a doubling strategy for the capacity.
5.  After the loop finishes, trim any excess capacity from the dynamic array with a final `realloc` call to make it fit
    the exact size.

---

### Implementation (My Approach)

```c
#include <stdlib.h>

// The one-pass approach using dynamic reallocation.
int *createNoDuplexArray(int *ogArr, size_t ogSize, int *arrSize) {
    if (ogSize == 0) {
        return NULL;
    }

    int *noDuplexArr = NULL;

    int dynamicSize = 0;
    *arrSize = 0;

    for (size_t i = 0; i < ogSize; i++) {
        if (*arrSize > 0 && ogArr[i] == noDuplexArr[*arrSize - 1]) {
            continue;
        }

        *arrSize += 1;
        if (*arrSize > dynamicSize) {
            dynamicSize = dynamicSize > 0 ? dynamicSize * 2 : 4;
            noDuplexArr = realloc(noDuplexArr, dynamicSize * sizeof(int));
        }

        noDuplexArr[*arrSize - 1] = ogArr[i];
    }

    if (dynamicSize > *arrSize) {
        noDuplexArr = realloc(noDuplexArr, *arrSize * sizeof(int));
    }

    return noDuplexArr;
}
```

---

### Limitations of My Approach

While this one-pass method seems efficient on the surface, it has significant hidden costs and technical drawbacks:

1.  **High Performance Overhead**: `realloc` is **not a cheap operation**. In the worst-case scenario, it cannot simply
    extend the existing memory block. Instead, it must:

    -   Allocate a completely new, larger block of memory.
    -   **Copy every single element** from the old block to the new one.
    -   Free the old block. This copy process can make the function unexpectedly slow, especially for large arrays.

2.  **Memory Fragmentation**: Frequent calls to `realloc` can leave small, unused gaps in the system's memory. Over
    time, this makes it harder for the memory manager to find large, contiguous blocks, potentially slowing down the
    entire application.

3.  **Wasteful Memory Management**: The code makes multiple system calls for memory. It temporarily **over-allocates**
    memory (up to almost double what's needed) and then requires an **extra `realloc` call** at the end just to trim the
    waste.

---

### A Superior Approach: The Two-Pass Method (Vlad's Code)

A counter-intuitive but far superior method involves iterating through the array twice. It works like this:

1.  **First Pass**: Iterate through the array _only to count_ the exact number of unique consecutive elements. This
    gives us the final, precise size needed for the new array.
2.  **Allocation**: Make a **single `malloc` call** to allocate the exact amount of memory required.
3.  **Second Pass**: Iterate through the array again to _populate_ the new, perfectly-sized array.

This approach separates the problem of "how big should the array be?" from "what should be in the array?".

### Superiority Analysis: My Approach vs. The Two-Pass Method

Here is a direct comparison explaining why the two-pass method is superior.

| Aspect                | My One-Pass `realloc` Method                                 | Vlad's Two-Pass `malloc` Method                                   | **Verdict**              |
| :-------------------- | :----------------------------------------------------------- | :---------------------------------------------------------------- | :----------------------- |
| **Memory Allocation** | Many `realloc` calls. Wasteful and causes fragmentation.     | **One single, precise `malloc` call.**                            | **Two-Pass is Superior** |
| **Performance**       | Unpredictable. Can be very slow due to hidden memory copies. | Consistently fast. Operations are lightweight (integer compares). | **Two-Pass is Superior** |
| **Readability**       | Logic is mixed. Sizing and populating happen together.       | Clean separation of concerns: Count -\> Allocate -\> Fill.        | **Two-Pass is Superior** |

**Analogy:** My approach is like packing for a trip by starting with a small bag. When it's full, you buy a bigger bag
and repack everything. You repeat this until you're done. It's inefficient. Vlad's approach is like laying all your
items on the floor first, determining you need exactly one large suitcase, and then packing everything just once. It is
far more efficient and planned.

### Conclusion

In conclusion, while the one-pass approach avoids a second iteration, the cost of that "convenience" is a significant,
unpredictable performance penalty and inefficient memory management. The two-pass method, despite iterating twice, is
faster in practice, more memory-efficient, and represents a much cleaner and more robust engineering solution.
