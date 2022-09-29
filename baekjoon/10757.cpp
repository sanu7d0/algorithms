#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string a, b;
    cin >> a >> b;

    // zero padding
    a = string(max((int)b.length() - (int)a.length(), 0), '0') + a;
    b = string(max((int)a.length() - (int)b.length(), 0), '0') + b;
    // reverse
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    vector<char> ans(1, 0); // 0~9 -> char
    int n, m;
    for (int i = 0; i < a.length(); i++)
    {
        n = a.at(i) - 48;
        m = b.at(i) - 48;
        
        ans.push_back((ans[i] + n + m) / 10);
        ans[i] = (ans[i] + n + m) % 10;
    }

    if (ans[a.length()] != 0){
        cout << to_string(ans[a.length()]);
    }
    for (int i = a.length()-1; i >= 0; i--)
    {
        cout << to_string(ans[i]);
    }
}
