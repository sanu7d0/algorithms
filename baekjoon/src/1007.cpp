#include <stdio.h>
#include <vector>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    
    int T, n;
    pair<int, int> *dots;

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        dots = new pair<int, int>[n]();
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", dots[i].first, dots[i].second);
        }
        
        // Not solved
        

        printf("%d\n", 0);
        delete[] dots;
    }
}
