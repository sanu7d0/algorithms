#include <iostream>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T, k, n;
    cin >> T;
    while (T--) {
        cin >> k >> n;
        int *men = new int[n+1];
        for (int i = 0; i <= n; i++)
        {
            men[i] = i;
        }

        // from floor 1 to k
        for (int i = 1; i <= k; i++)
        {
            for (int j = 0; j < n; j++)
            {
                men[j+1] = men[j] + men[j+1];
            }
        }
        

        cout << men[n] << "\n";
        delete[] men;
    }
}
