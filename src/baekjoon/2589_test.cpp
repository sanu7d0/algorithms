#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
using std::vector, std::max, std::pair, std::queue;
constexpr int MAXN = 50, INF = 5'000;

typedef pair<int, int> p_ii;
int R, C, map[MAXN + 2][MAXN + 2];
vector<p_ii> candidate;

void readData(void) {
    scanf("%d %d", &R, &C);

    char str[MAXN + 1];
    for (int r = 1; r <= R; r++) {
        scanf("%s", str);
        for (int c = 1; c <= C; c++) {
            if (str[c - 1] == 'L')
                map[r][c] = INF;
        }
    }
}

void makeCandidate(void) {
    static int dxy[5][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (map[r][c] == 0)
                continue;
            for (int k = 0, cnt = 0; k <= 4; k++) {
                if (map[r + dxy[k][0]][c + dxy[k][1]] == 0)
                    cnt++;
                else
                    cnt = 0;
                if (cnt > 1) {
                    candidate.emplace_back(r, c);
                    break;
                }
            }
        }
    }

    // for (const p_ii& c : candidate) {
    //   printf("%d %d\n", c.first, c.second);
    // }
}

void print_map(void) {
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            printf("%5d ", map[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}

int getMaxDistance(const p_ii &pos) {
    static int id = INF;
    id--;
    queue<p_ii> que;
    que.push(pos);
    map[pos.first][pos.second] = id;
    int depth = 0;
    while (!que.empty()) {
        int len = que.size();
        depth++;
        for (int l = 0; l < len; l++) {
            auto [r, c] = que.front();
            que.pop();
            if (map[r - 1][c] > id) {
                que.emplace(r - 1, c);
                map[r - 1][c] = id;
            }
            if (map[r + 1][c] > id) {
                que.emplace(r + 1, c);
                map[r + 1][c] = id;
            }
            if (map[r][c - 1] > id) {
                que.emplace(r, c - 1);
                map[r][c - 1] = id;
            }
            if (map[r][c + 1] > id) {
                que.emplace(r, c + 1);
                map[r][c + 1] = id;
            }
        }
        // print_map();
        // printf("d %d\n", depth);
    }
    return depth - 1;
}

int main(void) {
    readData();
    makeCandidate();

    int ans = 0;
    for (const p_ii &can : candidate) {
        ans = max(ans, getMaxDistance(can));
    }
    printf("%d\n", ans);

    return 0;
}
