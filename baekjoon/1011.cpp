#include <stdio.h>
#include <cmath>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    
    int T, x, y, move;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &x, &y);

        // (1), (1-2-1), (1-2-3-2-1), ... = n^2
        int distance = y - x;
        int n = 0;
        do {
            if (pow(n, 2) <= distance && distance < pow(n+1, 2))
            {
                move = 2*n- 1;
                int remain = distance - pow(n,2);
                if (0 < remain && remain <= n)
                    move += 1;
                else if (n < remain)
                    move += 2;
                printf("%d\n", move);
                break;
            }
            n++;
        } while (true);
    }
}
