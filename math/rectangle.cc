
// check if four points make a rectangle on a cartesian coordinate plane

#include <vector>
using namespace std;

struct Point {
    int x;
    int y;
};

double square(double x) {
    return x * x;
}

// https://www.youtube.com/watch?v=FXTt0jM_AzM
bool isRectangle(Point a, Point b, Point c, Point d) {
    double diagonal1_squared = square(a.x - c.x) + square(a.y - c.y);
    double diagonal2_squared = square(b.x - d.x) + square(b.y - d.y);
    return diagonal1_squared == diagonal2_squared;
}

bool isRectangleAll(Point a, Point b, Point c, Point d) {
    return isRectangle(a, b, c, d) ||
             isRectangle(a, c, b, d) ||
             isRectangle(a, d, b, c);
}



