#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
typedef pair<int, int> pii;

struct Point {
    int r, c;

    Point operator+(Point &p) { return Point{r + p.r, c + p.c}; }
};

Point dirs[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main() {
    fastio;

    int N, K;
    cin >> N >> K;

    // 0 - empty, 1 - snake, 2 - apple
    vector<vector<int>> map = vector<vector<int>>(N, vector<int>(N, 0));
    map[0][0] = 1;
    for (int i = 0; i < K; ++i) {
        int r, c;
        cin >> r >> c;
        map[r - 1][c - 1] = 2;
    }

    int L;
    deque<pii> turn;
    cin >> L;
    for (int i = 0; i < L; ++i) {
        int x;
        char c;
        cin >> x >> c;
        turn.push_back({x, c == 'D' ? 1 : -1});
    }

    deque<Point> snake;
    snake.push_back({0, 0});
    int d = 0; // dir[0]

    int t = 0;
    while (true) {
        t += 1;

        Point next = snake.front() + dirs[d];
        Point tail = snake.back();

        // wall
        if (next.r < 0 || next.r >= N || next.c < 0 || next.c >= N)
            break;

        int obj = map[next.r][next.c];
        // apple
        if (obj == 2) {
            snake.push_front(next);
            map[next.r][next.c] = 1;
            map[tail.r][tail.c] = 1;
        }
        // snake
        else if (obj == 1) {
            break;
        } else {
            snake.push_front(next);
            map[next.r][next.c] = 1;
            snake.pop_back();
            map[tail.r][tail.c] = 0;
        }

        // turn
        if (t == turn.front().first) {
            d = (d + turn.front().second + 4) % 4;
            turn.pop_front();
        }
    }

    cout << t;
}
