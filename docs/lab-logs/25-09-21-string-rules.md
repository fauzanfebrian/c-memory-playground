## String Rules in C

Understanding how strings work in C requires distinguishing between **character arrays**, **pointers to arrays**, and
**string literals** that live in read-only memory.

### Key Concepts

1. **Character Array** Declaring `char charsArray[] = {'H','E','L','L','O'};` creates an array without a null terminator
   `\0`. Using `%s` with `printf` on this array may result in undefined behavior. Arrays can decay into pointers, e.g.,
   `tempPtr = charsArray;`. Any modification through `tempPtr` also changes the array contents.

2. **Array-Initialized String** Declaring `char str[] = "Hello";` creates a mutable character array in stack memory that
   includes the null terminator. Individual characters (e.g., `str[0] = 'G';`) can be modified safely.

3. **Pointer to String Literal** Declaring `char *str2 = "Hello";` makes the pointer reference a string literal in
   read-only memory. Attempting to modify `str2[1]` results in a segmentation fault. However, reassigning
   `str2 = "Good-Bye";` is valid, because the pointer is redirected to another literal.

### Example Code

[string-rules.c](../../src/section-10/string-rules.c)
