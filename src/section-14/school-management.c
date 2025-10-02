#include <stdio.h>
#include <stdlib.h>

typedef struct student {
    char name[64];
    int ID;
} Student;

typedef struct courseGrade {
    int grade;
    Student* student;
} CourseGrade;

typedef struct course {
    char name[16];
    float avgGrade;
    CourseGrade* grades;
    int minimumGrade;
    int totalStudents;
    int ID;
} Course;

typedef struct school {
    char name[32];
    Course** courses;
    int totalCourses;
    int ID;
} School;

Student* createStudents(int* totalStudents) {
    Student* students;

    printf("______\n");
    printf("How many students to regist? ");
    scanf("%d", totalStudents);

    if (*totalStudents < 1) {
        return NULL;
    }

    students = calloc(*totalStudents, sizeof(Student));
    if (students == NULL) {
        return NULL;
    }

    printf("So for registration of %d students you have to enter their name.\n", *totalStudents);

    for (size_t i = 0; i < *totalStudents; i++) {
        students[i].ID = i + 1;

        printf("Enter name for student #%d: ", students[i].ID);
        scanf("%s", &students[i].name);
    }

    return students;
}

Student* findStudentById(Student* students, int totalStudents, int studentId) {
    for (size_t i = 0; i < totalStudents; i++) {
        if (students[i].ID == studentId) {
            return &students[i];
        }
    }
    return NULL;
}

int checkStudentInTheCourse(Course* course, int studentId) {
    if ((*course).totalStudents < 1) {
        return 0;
    }

    for (size_t i = 0; i < (*course).totalStudents; i++) {
        if ((*(*course).grades[i].student).ID == studentId) {
            return 1;
        }
    }

    return 0;
}

int checkStudentInTheSchool(School* school, int studentId) {
    if (school->totalCourses < 1) {
        return 0;
    }

    for (size_t i = 0; i < school->totalCourses; i++) {
        if (checkStudentInTheCourse(school->courses[i], studentId)) {
            return 1;
        }
    }

    return 0;
}

void printAllCourseForAStudent(Course* courses, int totalCourses, int studentId) {
    printf("Courses: ");
    for (size_t i = 0; i < totalCourses; i++) {
        if (checkStudentInTheCourse(&courses[i], studentId) == 0) {
            continue;
        }

        printf("Course #%d. %s, Avg. %.2f, Total Students: %d\n", courses[i].ID, courses[i].name, courses[i].avgGrade, courses[i].totalStudents);
    }
}

Course* createCourses(int* totalCourses, Student* students, int totalStudents) {
    Course* courses;

    printf("______\n");
    printf("How many courses to regist? ");
    scanf("%d", totalCourses);

    if (*totalCourses < 1) {
        return NULL;
    }

    courses = calloc(*totalCourses, sizeof(Course));
    if (courses == NULL) {
        return NULL;
    }

    printf("So for registration of %d courses you have to enter their name, select student ids (from 1 - %d) and his grade.\n", *totalCourses, totalStudents);

    for (size_t i = 0; i < *totalCourses; i++) {
        courses[i].ID = i + 1;
        courses[i].avgGrade = 0;
        courses[i].totalStudents = 0;

        printf("\nEnter name for course #%d: ", courses[i].ID);
        scanf("%s", &courses[i].name);

        printf("\nEnter minimum grade for course #%d: ", courses[i].ID);
        scanf("%d", &courses[i].minimumGrade);

        courses[i].grades = calloc(totalStudents, sizeof(CourseGrade));
        if (courses[i].grades == NULL) {
            for (size_t j = 0; j < i; j++) {
                free(courses[j].grades);
            }
            free(courses);
            return NULL;
        }

        while (courses[i].totalStudents < totalStudents) {
            int studentId;
            printf("Enter student's ID #1 - #%d (enter 0 to exit): ", totalStudents);
            scanf("%d", &studentId);

            if (studentId < 1) {
                break;
            }

            if (checkStudentInTheCourse(&courses[i], studentId)) {
                printf("Student already in the course.\n");
                continue;
            }

            CourseGrade* grade = &courses[i].grades[courses[i].totalStudents];

            (*grade).student = findStudentById(students, totalStudents, studentId);
            if ((*grade).student == NULL) {
                printf("Student is not available\n");
                continue;
            }

            printf("Enter student's grade: ");
            scanf("%d", &(*grade).grade);

            courses[i].avgGrade = (courses[i].avgGrade * (float)courses[i].totalStudents + (float)(*grade).grade) / (float)(courses[i].totalStudents + 1);
            courses[i].totalStudents += 1;
        }

        if (totalStudents > courses[i].totalStudents && courses[i].totalStudents > 0) {
            CourseGrade* grades = realloc(courses[i].grades, courses[i].totalStudents * sizeof(CourseGrade));
            if (grades == NULL) {
                for (size_t j = 0; j < i + 1; j++) {
                    free(courses[j].grades);
                }
                free(courses);
                return NULL;
            }
            courses[i].grades = grades;
        }
    }

    return courses;
}

Course* findCourseById(Course* courses, int totalCourses, int courseId) {
    for (size_t i = 0; i < totalCourses; i++) {
        if (courses[i].ID == courseId) {
            return &courses[i];
        }
    }
    return NULL;
}

int checkCourseInSchools(School* schools, int totalSchools, int idCourse) {
    for (size_t i = 0; i < totalSchools; i++) {
        if ((**(*schools).courses).ID == idCourse) {
            return 1;
        }
    }
    return 0;
}

void printStudentsWhoFailedCourse(Course* course) {
    if (course->totalStudents < 1) {
        return;
    }

    printf("Student who failed course #%d %s\n", course->ID, course->name);
    for (size_t i = 0; i < course->totalStudents; i++) {
        if (course->minimumGrade > course->grades[i].grade) {
            printf("%d.\t#%d %s\n", i + 1, course->grades[i].student->ID, course->grades[i].student->name);
        }
    }
}

void printStudentsWhoPassedCourse(Course* course) {
    if (course->totalStudents < 1) {
        return;
    }

    printf("Student who passed course #%d %s\n", course->ID, course->name);
    for (size_t i = 0; i < course->totalStudents; i++) {
        if (course->minimumGrade <= course->grades[i].grade) {
            printf("%d.\t#%d %s\n", i + 1, course->grades[i].student->ID, course->grades[i].student->name);
        }
    }
}

School* createSchools(int* totalSchools, Course* courses, int totalCourses) {
    School* schools;

    printf("______\n");
    printf("How many schools to regist? ");
    scanf("%d", totalSchools);

    if (*totalSchools < 1) {
        return NULL;
    }

    schools = calloc(*totalSchools, sizeof(School));
    if (schools == NULL) {
        return NULL;
    }

    printf("So for registration of %d schools you have to enter their name, select course ids (from 1 - %d).\n", *totalSchools, totalCourses);

    for (size_t i = 0; i < *totalSchools; i++) {
        schools[i].ID = i + 1;

        printf("\nEnter name for school #%d: ", schools[i].ID);
        scanf("%s", &schools[i].name);

        schools[i].courses = calloc(totalCourses, sizeof(Course*));
        if (schools[i].courses == NULL) {
            for (size_t j = 0; j < i; j++) {
                free(schools[j].courses);
            }
            free(schools);
            return NULL;
        }

        while (schools[i].totalCourses < totalCourses) {
            int courseId;
            printf("Enter course's ID #1 - #%d (enter 0 to exit): ", totalCourses);
            scanf("%d", &courseId);

            if (courseId < 1) {
                break;
            }

            if (checkCourseInSchools(schools, i, courseId)) {
                printf("Course already in the course.\n");
                continue;
            }

            schools[i].courses[schools[i].totalCourses] = findCourseById(courses, totalCourses, courseId);
            schools[i].totalCourses += 1;
        }

        if (totalCourses > schools[i].totalCourses && schools[i].totalCourses > 0) {
            Course** courses = realloc(schools[i].courses, schools[i].totalCourses * sizeof(Course*));
            if (courses == NULL) {
                for (size_t j = 0; j < i + 1; j++) {
                    free(schools[j].courses);
                }
                free(schools);
                return NULL;
            }
            schools[i].courses = courses;
        }
    }

    return schools;
}

void printStudent(Student* student) {
    printf("___\n");
    printf("Detail student #%d:\n", student->ID);
    printf("Name: %s\n", student->name);
}

void printCourse(Course* course) {
    printf("___\n");
    printf("Detail course #%d:\n", course->ID);
    printf("Name: %s\n", course->name);
    printf("Average: %d\n", course->avgGrade);
    printf("Total Students: %d\n", course->totalStudents);
    for (size_t i = 0; i < course->totalStudents; i++) {
        printStudent(course->grades[i].student);
        printf("Grade: %d\n", course->grades[i].grade);
    }
}

void printSchool(School* school) {
    printf("___\n");
    printf("Detail school #%d:\n", school->ID);
    printf("Name: %s\n", school->name);
    printf("Total Courses: %d\n", school->totalCourses);
    for (size_t i = 0; i < school->totalCourses; i++) {
        printCourse(school->courses[i]);
    }
}

// ==================== ADD-ON: helpers & scenario (append at the very end of the file) ====================

static void freeAll(Student* students, Course* courses, int totalCourses, School* schools, int totalSchools) {
    if (schools) {
        for (size_t i = 0; i < (size_t)totalSchools; i++) {
            free(schools[i].courses);  // array of pointers to Course
        }
        free(schools);
    }

    if (courses) {
        for (size_t i = 0; i < (size_t)totalCourses; i++) {
            free(courses[i].grades);  // array of CourseGrade
        }
        free(courses);
    }

    free(students);
}

static int promptInt(const char* label, int min, int max) {
    int v;
    while (1) {
        printf("%s", label);
        if (scanf("%d", &v) != 1) {
            // flush invalid input
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {
            }
            printf("Invalid input. Try again.\n");
            continue;
        }
        if ((min != 0 || max != 0) && (v < min || v > max)) {
            printf("Value must be between %d and %d.\n", min, max);
            continue;
        }
        return v;
    }
}

static void runUseCases(Student* students, int totalStudents, Course* courses, int totalCourses, School* schools, int totalSchools) {
    printf("\n====== USE CASE DEMO ======\n");

    // 1) Show details of one school: all courses and students
    if (totalSchools > 0) {
        int schoolId = promptInt("Select a School ID to display (1..N): ", 1, totalSchools);
        School* s = NULL;
        for (size_t i = 0; i < (size_t)totalSchools; i++) {
            if (schools[i].ID == schoolId) {
                s = &schools[i];
                break;
            }
        }
        if (s) {
            printSchool(s);
        } else {
            printf("School #%d not found. Skipping.\n", schoolId);
        }
    }

    // 2) For a given student, list every course they joined
    if (totalStudents > 0 && totalCourses > 0) {
        int sid = promptInt("\nEnter a Student ID to list their courses: ", 1, totalStudents);
        Student* st = findStudentById(students, totalStudents, sid);
        if (st) {
            printStudent(st);
            printAllCourseForAStudent(courses, totalCourses, sid);
        } else {
            printf("Student #%d not found.\n", sid);
        }
    }

    // 3) For a given course, print passed and failed students
    if (totalCourses > 0) {
        int cid = promptInt("\nEnter a Course ID to list passed & failed students: ", 1, totalCourses);
        Course* c = findCourseById(courses, totalCourses, cid);
        if (c) {
            printStudentsWhoPassedCourse(c);
            printStudentsWhoFailedCourse(c);
        } else {
            printf("Course #%d not found.\n", cid);
        }
    }

    // 4) Check if a student is enrolled in any course across any school
    if (totalStudents > 0 && totalSchools > 0) {
        int sid2 = promptInt("\nEnter a Student ID to check enrollment across schools: ", 1, totalStudents);
        int found = 0;
        for (size_t i = 0; i < (size_t)totalSchools && !found; i++) {
            if (checkStudentInTheSchool(&schools[i], sid2)) found = 1;
        }
        printf("Student #%d is %s enrolled in at least one course in any school.\n",
               sid2, found ? "" : "NOT");
    }

    printf("====== END DEMO ======\n");
}

int main() {
    Student* students;
    Course* courses;
    School* schools;

    int totalStudents, totalCourses, totalSchools;

    students = createStudents(&totalStudents);
    if (students == NULL) {
        return 1;
    }

    courses = createCourses(&totalCourses, students, totalStudents);
    if (courses == NULL) {
        free(students);
        return 1;
    }

    schools = createSchools(&totalSchools, courses, totalCourses);
    if (schools == NULL) {
        for (size_t i = 0; i < (size_t)totalCourses; i++) {
            free(courses[i].grades);
        }
        free(courses);
        free(students);
        return 1;
    }

    // Run scenario without modifying your existing functions
    runUseCases(students, totalStudents, courses, totalCourses, schools, totalSchools);

    // Proper cleanup
    freeAll(students, courses, totalCourses, schools, totalSchools);

    return 0;
}
