typedef struct point {
    char x;
    double y;
    char z;
} Point;

typedef struct point2 {
    char x;
    char z;
    double y;
} Point2;

typedef struct point3 {
    char x;
    char z;
    int w;
    double y;
} Point3;

int main() {
    Point point = {
        .x = 'H',
        .y = 10.02,
        .z = 'J',
    };

    Point2 point2 = {
        .x = 'H',
        .y = 10.02,
        .z = 'J',
    };

    Point3 point3 = {
        .x = 'H',
        .y = 10.02,
        .z = 'J',
        .w = 10,
    };

    return 0;
}