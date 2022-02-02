#include <iostream>
#include <cmath>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b, v;
    cin >> a >> b >> v;

    cout << (int)ceil((double)(v-a)/(a-b)+1) << "\n";
}
