#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<vector<bool>> stars;

void checkStar(int n, int r, int c)
{
    if (n == 1)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i == 1 && j == 1) continue;
                stars[r+i][c+j] = true;
            }
        }
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 1 && j == 1) continue;
            checkStar(n-1, r + pow(3, n-1)*i, c + pow(3,n-1)*j);
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, k;
    cin >> N;
    k = log10(N) / log10(3); // log3(N) = log10(N) / log10(3)
    for (int i = 0; i < N; i++)
    {
        stars.push_back(vector<bool>(N, false));
    }

    checkStar(k, 0, 0);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << (stars[i][j] ? "*" : " ");
        }
        cout << "\n";
    }    
}
