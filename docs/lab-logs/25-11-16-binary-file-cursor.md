# Binary File Cursor

Today's key take aways are about `Binary Files`, what i really got from today's material is about Binary Files Cursor manipulation, for example, if we want to edit a value of a binary file at certain location, or simply just reading from it, we need to understand how cursor manipuilated, using the `fseek` function. Usage example:

```c
fseek(fp, (choice - 1) * sizeof(Point), SEEK_SET);
```

Look at the `SEEK_SET`, there are 3 SEEK_* we can use:

1. SEEK_SET: seek/move cursor from start of the file.
2. SEEK_CUR: seek/move cursor from the current position, used when we simply want to backward one step or just continue one step.
3. SEEK_END: seek/move cursor from the end of the file.

## Notes

After we manipulate the file using `fread` or `fwrite` we should note that the cursor has already moved. For example, we move the cursor to the location 5 at the file, then we read the value from location 8, now the cursor is already at location 9, if we want to manipulate the value at location 5-8 we should move the cursor backward using the `fseek` again.

## Examples

See the full code [here](../../src/section-20/c3-multiply-by-3.c)