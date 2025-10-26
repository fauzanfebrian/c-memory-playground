# Memory Padding

I want to document today's course insight about memory usage optimization, specifically about memory padding in a `struct`.

## Ignorance

I'm a high-level language coder, and I've always been ignorant about memory management. I didn't know a thing about it. Because, honestly, who cares?

Actually, there are a lot of coders who *do* care about that. Not me at first, but today’s course really changed how I see memory management. I learned about memory padding, a really clever mechanism.

The computer can only read a certain number of bytes at once, so the smart person who designed this introduced memory padding. It allows data to be fetched from memory in aligned bundles. For example:

```c
typedef struct point {
    char x;
    double y;
    int z;
} Point;
```

`char` takes 1 byte, `double` takes 8 bytes, and `int` takes 4 bytes. So, in total, this `Point` should have 13 bytes, right? Nope, You’re wrong.

This struct actually takes **24 bytes** because of memory padding. Let’s say we’re on a 64-bit computer, that means the CPU can only fetch 8 bytes at a time. Look at this visualization of how memory is accessed:

```c
char   ✅ ❌ ❌ ❌ ❌ ❌ ❌ ❌
double ✅ ✅ ✅ ✅ ✅ ✅ ✅ ✅
int    ✅ ✅ ✅ ✅ ❌ ❌ ❌ ❌
```

The `✅` symbols represent data the computer reads, while the `❌` symbols represent padding.
Because of this padding, the computer can load the `double` value all at once.
Without padding, the double would be fetched in chunks, which could make the program unstable or even crash.

## Improvisation

While memory padding is useful, the trade-off is expensive, 11 bytes are wasted just for padding.
So Vlad taught us how to optimize it by simply reordering the struct fields:

```c
typedef struct point {
    char x;
    int z;
    double y;
} Point;
```

Now, the `int` comes before the `double`, changing how padding works:

```c
char   ✅ ❌ ❌ ❌
int    ✅ ✅ ✅ ✅
double ✅ ✅ ✅ ✅ ✅ ✅ ✅ ✅
```

Look at that, only **3 bytes** are wasted now. This matters a lot, especially when writing programs for low-end devices.
