#include <iostream>
#include <queue>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

struct T {
    int num;

    bool operator()(T& a, T& b) const
    {
        if (abs(a.num) == abs(b.num))
            return a.num > b.num;
        else
            return abs(a.num) > abs(b.num);
    }
};

int main()
{
    fastio;

    int N;
    priority_queue<T, vector<T>, T> pq;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;

        if (x == 0) {
            if (pq.empty()) {
                cout << "0\n";
            } else {
                cout << pq.top().num << "\n";
                pq.pop();
            }
        } else {
            pq.push({ x });
        }
    }
}
