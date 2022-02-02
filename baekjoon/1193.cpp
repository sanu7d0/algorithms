#include <iostream>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long X;
    cin >> X;
    
    int i = 1;
    while (i*(i+1)/2 < X)
    {
        i++;
    }

    int over = X - (i-1)*i/2;
    if (i%2) {
        cout << i-over+1 << "/" << over << "\n";
    }
    else {
        cout << over << "/" << i-over+1 << "\n";
    }
}
