
// Check if four points make a rectangle on a cartesian coordinate plane
// Use the distance formula between two points on a plane.
// dist = sqrt((x2-x1)^2 + (y2 - y1)^2)

#include <vector>
#include <iostream>

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

int main() {
    Point a = {4, 1};
    Point b = {3, -1};
    Point c = {-3, 2};
    Point d = {-2, 4};

    if (isRectangleAll(a, b, c, d)) {
        std::cout << "The points form a valid rectangle." << std::endl;
    } else {
        std::cout << "The points do not form a rectangle." << std::endl;
    }

    return 0;
}



