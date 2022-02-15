#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> steps;

int main() {
    freopen("input.txt", "r", stdin);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    cout << steps.size() << "\n";
    for (auto i: steps) {
        cout << i.first << " " << i.second << "\n";
    }
}
