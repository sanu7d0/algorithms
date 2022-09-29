#include <iostream>
#include <string>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

struct Point {
    int x, y;

    bool operator==(const Point &p) { return x == p.x && y == p.y; }
};

struct Box {
    int x1, y1, x2, y2;
    Point points[4]; // top left, top right, bottom left, bottom right

    Box(int _x1, int _y1, int _x2, int _y2) {
        x1 = _x1;
        y1 = _y1;
        x2 = _x2;
        y2 = _y2;
        points[0] = {x1, y2};
        points[1] = {x2, y2};
        points[2] = {x1, y1};
        points[3] = {x2, y1};
    }
};

bool check_null(Box b1, Box b2) {
    return b1.y1 > b2.y2 || b2.y1 > b1.y2 || b1.x1 > b2.x2 || b2.x1 > b1.x2;
}

bool check_line(Box b1, Box b2) {
    return b1.x1 == b2.x2 || b2.x1 == b1.x2 || b1.y1 == b2.y2 || b2.y1 == b1.y2;
}

bool check_point(Box b1, Box b2) {
    return b1.points[2] == b2.points[1] || b2.points[2] == b1.points[1] ||
           b1.points[3] == b2.points[0] || b2.points[3] == b1.points[0];
}

int main() {
    fastio;

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Box b1 = Box(x1, y1, x2, y2);
    cin >> x1 >> y1 >> x2 >> y2;
    Box b2 = Box(x1, y1, x2, y2);

    string res = "FACE";
    if (check_null(b1, b2))
        res = "NULL";
    else if (check_point(b1, b2))
        res = "POINT";
    else if (check_line(b1, b2))
        res = "LINE";

    cout << res;
}
