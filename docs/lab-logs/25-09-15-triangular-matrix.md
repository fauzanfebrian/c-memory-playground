## Core Problem

Today's chanllenge is to create a function that generates a triangular matrix of a given size. A triangular matrix is a
square matrix that divides into two parts: the upper triangular part and the lower triangular part. Function to create:

-   Upper Triangular Matrix
-   Lower Triangular Matrix

### Brainstorming

Because the paramaters is contain the size of the matrix `n`, that same rows and columns will be created. The upper
triangular matrix's first row will contain `n` elements, the second row will contain `n-1` elements, and so on until the
last row which will contain 1 element. The lower triangular matrix's first row will contain 1 element, the second row
will contain 2 elements, and so on until the last row which will contain `n` elements.

### Final Code

[c2-triangular-matrix.c](../../src/section-9/c2-triangular-matrix.c)
