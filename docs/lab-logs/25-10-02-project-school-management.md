# School Management System — Requirements & Guidelines (Refined, English)

> **Purpose:** Build a lightweight, struct-based school management system with a focus on **data modeling**, **core
> operations**, and **dynamic memory discipline**. This document restates the original brief in a clearer, punchier
> format, without examples or code.

---

## 1) Project Scope

-   Three core entities: **Student**, **Course**, and **School**.
-   All core data must be managed **dynamically** (allocated on the heap).
-   The main program creates a **School**, populates it with **Courses** and **Students**, then prints a concise
    summary.

---

## 2) Data Model (High-Level)

### Student

-   Minimum attributes: **Name** and **ID** (integer, unique per student).
-   Stored dynamically.

### Course

-   Minimum attributes: **Course Name**, **Average Grade**, and a **dynamic array** of enrolled **Students**.
-   The average grade may be maintained as a cached value or computed on demand, but it must remain accurate.

### School

-   Minimum attributes: **School Name** and a **dynamic array** of **Courses** it offers.

> **Note:** You may extend the design as needed, as long as you implement all required operations below and uphold
> proper dynamic memory management.

---

## 3) Required Operations (Functions)

Implement the following operations with clear contracts and validated inputs. Do not include examples in the
deliverable; just the working implementation in your codebase.

1. **Create a Student** Create a new Student record and initialize its attributes.

2. **Create a Course** Create a new Course, determine the number of Students, and populate the roster.

3. **Create a School** Create a new School, determine the number of Courses, and populate their details.

4. **Print Student Details** Print a concise summary for a single Student.

5. **Print Course Details** Print a Course summary and all enrolled Students.

6. **Print School Details** Print a School summary, all Courses, and the Students in each Course.

7. **Check if Student Is in a Course** Search for a Student by ID within a Course.

8. **Check if Student Is in the School** Search for a Student by ID across all Courses in the School.

9. **Print All Courses for a Student** Print all Courses in which a given Student (by ID) is enrolled.

10. **Print Students Who Failed a Course** For a given Course and passing grade, print Students below the threshold.

11. **Print Students Who Passed a Course** For a given Course and passing grade, print Students meeting or exceeding the
    threshold.

12. **Print Courses with Passed Average Grade** For a School and passing grade, print Courses whose average grade meets
    or exceeds the threshold.

13. **Print Courses with Failed Average Grade** For a School and passing grade, print Courses whose average grade is
    below the threshold.

14. **Print the Average Grade Across All Courses** Compute and print the aggregate average across all Courses in the
    School.

15. **Print the Course with the Highest Average Grade** Identify and print the Course with the highest average grade.

---

## 4) Rules & Constraints

-   **Dynamic memory:** allocate, reallocate, and free correctly. No leaks.
-   **Data consistency:** whenever Students are added/removed from a Course, the **Average Grade** must remain accurate.
-   **Input validation:** IDs and passing grades must be sensible; handle empty or invalid input gracefully.
-   **Execution order:** create School → create Courses → enroll Students → run print/search/statistics operations.
-   **Output:** print functions must be concise, consistent, and easy to read.

---

## 5) Implementation Quality (What Good Looks Like)

-   **Clear structure:** functions follow single responsibility; names are precise; no overlapping concerns.
-   **Memory safety:** all allocations are freed; no double-free; no use-after-free.
-   **Data accountability:** any data change updates dependent values (e.g., average grade) accurately.
-   **Readability:** tidy output, informative error messages, comments kept minimal and useful.

---

## 6) Minimum Testing

-   One School with at least two Courses and at least two Students per Course.
-   Verify membership checks at both Course and School levels.
-   Verify pass/fail filtering per Course and School-wide average behavior.
-   Edge cases: Course with zero Students, School with zero Courses, missing IDs, extreme passing grades.

---

## 7) Memory Management Checklist

-   [ ] All strings/arrays are dynamically allocated and freed correctly.
-   [ ] No use-after-free or dangling pointers.
-   [ ] No double-free.
-   [ ] No memory leaks detected by tooling (e.g., Valgrind).

---

## 8) Deliverables

-   Source code implementing all required operations.
-   Brief run instructions and project structure.
-   Optional: sample outputs from print functions for visual verification.

---

## 9) Recap

Create a School → add Courses → enroll Students → run the specified print, check, and statistics operations. Keep data
consistent and memory clean. The objective is to practice **structs**, **pointers**, and **dynamic allocation** with
discipline.

---

### Attribution

Original requirements by **Vlad Budnitski**. This document clarifies and tightens the instructions without adding
implementation examples.

---

### My Key Takeaways

#### Char Allocation in C Structs — Clear Guidelines

-   If the **maximum length is known** and small: use a **fixed-size `char name[N]`** inside the struct.
-   If the length is **unknown or variable**: use a **`char *name`** and **allocate on the heap**
    (`malloc`/`calloc`/`realloc`), then `free` later.
-   Do **not** keep string storage on the **stack** if the struct must outlive the current function.
