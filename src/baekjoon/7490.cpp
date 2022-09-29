#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N;
vector<char> ops;

void traverse(int n, int sum, int save, int save_sign)
{
    if (n == N + 1) {
        if (save != 0)
            sum += save_sign * save;

        if (sum == 0) {
            cout << 1;
            for (int i = 2; i <= N; ++i)
                cout << ops[i] << i;
            cout << "\n";
        }
        return;
    }

    // space
    ops[n] = ' ';
    traverse(n + 1, sum, 10 * save + n, save_sign);
    // plus
    ops[n] = '+';
    traverse(n + 1, sum + save_sign * save, n, 1);
    // minus
    ops[n] = '-';
    traverse(n + 1, sum + save_sign * save, n, -1);
}

int main()
{
    fastio;

    int T;
    cin >> T;

    ops = vector<char>(10);

    while (T--) {
        cin >> N;

        traverse(2, 0, 1, 1);
        cout << "\n";
    }
}
