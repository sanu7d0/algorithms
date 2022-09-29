#include <iostream>
#include <math.h>
#include <string>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
    fastio;

    int N;
    cin >> N;

    int num[11] {};
    for (int i = 0; i < N; ++i) {
        // num > 9876543210
        if (num[10] > 0)
            break;

        num[0] += 1;
        for (int j = 0; j < 10; ++j) {
            if (num[j] == 0)
                break;

            if (num[j] == 10) {
                // 0 9 8 7 -> 0 10 9 8 -> 3 2 1 0
                for (int k = j + 1; k >= 0; --k) {
                    num[k] = k;
                }
            }

            if (num[j + 1] != 0 && num[j] >= num[j + 1]) {
                num[j + 1] += 1;
                num[j] = (j == 0 ? 0 : num[j - 1] + 1);
            }
        }
    }

    if (num[10] == 0) {
        string answer;
        for (int i = 9; i >= 0; --i)
            answer += (char)num[i] + '0';

        cout << stoll(answer);
    } else {
        cout << "-1";
    }
    cout << "\n";
}
