#include <stdio.h>
#include <vector>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    
    long long min, max;
    scanf("%lld %lld", &min, &max);
    
    vector<bool> squareFree(max-min+1, false);

    long long count = max - min + 1;
    long long n, i = 2;

    while (i * i <= max) {
        n = min / (i * i);
        if (min % (i * i)) n++;

        while (n * i * i <= max) {
            // true = already checked
            if (!squareFree[n * i * i - min]) {
                squareFree[n * i * i - min] = true;
                count--;
            }
            n++;
        }
        i++;
    }
    
    printf("%lld", count);
    return 0;
}
