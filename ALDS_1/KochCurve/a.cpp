#include<stdio.h>
#include<iostream>
using namespace std;

typedef struct Point {
    double x = 0;
    double y = 0;
} Point;

void koch(int d, Point p1, Point p2){
    if(0 == d) return;
    Point s, t, u;

    s.x = (2 * p1.x + p2.x) / 3.0;
    s.y = (2 * p1.y + p2.y) / 3.0;

    t.x = (p1.x + 2 * p2.x) / 3.0;
    t.y = (p1.y + 2 * p2.y) / 3.0;

    double sin60 = 0.86602540378; // approximate value of sin(60 degrees)
    double cos60 = 0.5; // approximate value of cos(60 degrees)
    u.x = (t.x - s.x) * cos60 - (t.y - s.y) * sin60 + s.x;
    u.y = (t.x - s.x) * sin60 + (t.y - s.y) * cos60 + s.y;

    koch(d-1, p1, s);
    printf("%.8f %.8f\n", s.x, s.y);

    koch(d-1, s, u);
    printf("%.8f %.8f\n", u.x, u.y);

    koch(d-1, u, t);
    printf("%.8f %.8f\n", t.x, t.y);

    koch(d-1, t, p2);
}


int main() {
    int n;
    scanf("%d", &n);

    Point a, b;
    a.x = 0.0;
    a.y = 0.0;

    b.x = 100.0;
    b.y = 0.0;

    printf("%.8f %.8f\n", a.x, a.y);
    koch(n, a, b);
    printf("%.8f %.8f\n", b.x, b.y);

    return 0;
}