#include <algorithm>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

struct Robot {
    int x;
    int y;
    int dir;
    int id;
};

vector<vector<int>> v;
vector<Robot> r;
int A, B;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int get_dir(char c) {
    switch (c) {
    case 'N':
        return 0;
    case 'E':
        return 1;
    case 'S':
        return 2;
    case 'W':
        return 3;
    default:
        return -1;
    }
}

int find_robot(int x, int y) {
    for (int i = 0; i < r.size(); ++i) {
        Robot robot = r[i];
        if (robot.x == x && robot.y == y)
            return robot.id;
    }
    return -1;
}

int run_command(char cmd, Robot &robot) {
    switch (cmd) {
    case 'L':
        robot.dir = (robot.dir - 1 + 4) % 4;
        return 0;
    case 'R':
        robot.dir = (robot.dir + 1 + 4) % 4;
        return 0;
    case 'F':
        v[robot.y][robot.x] = 0;
        int t_x = robot.x + dx[robot.dir];
        int t_y = robot.y + dy[robot.dir];

        // wall crash
        if (t_x <= 0 || t_x > A || t_y <= 0 || t_y > B) {
            cout << "Robot " << robot.id << " crashes into the wall\n";
            return 1;
        }
        // robot crash
        else if (v[t_y][t_x] == 1) {
            cout << "Robot " << robot.id << " crashes into robot "
                 << find_robot(t_x, t_y) << "\n";
            return 1;
        }

        v[t_y][t_x] = 1;
        robot.x = t_x;
        robot.y = t_y;
        return 0;
    }
    return -1;
}

int main() {
    fastio;

    int N, M;

    cin >> A >> B >> N >> M;
    // 0 -> empty, 1 -> robot
    v = vector<vector<int>>(B + 1, vector<int>(A + 1, 0));

    for (int i = 0; i < N; ++i) {
        int x, y;
        char dir;
        cin >> x >> y >> dir;

        v[y][x] = 1;
        r.push_back({x, y, get_dir(dir), i + 1});
    }

    bool no_problem = true;
    for (int i = 0; i < M && no_problem; ++i) {
        int robot, iteration;
        char cmd;
        cin >> robot >> cmd >> iteration;

        for (int j = 0; j < iteration; ++j) {
            if (run_command(cmd, r[robot - 1]) != 0) {
                no_problem = false;
                break;
            }
        }
    }
    if (no_problem)
        cout << "OK\n";
}
