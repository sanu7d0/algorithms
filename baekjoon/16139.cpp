#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

string S;

int main()
{
    fastio;

    int q;
    cin >> S >> q;

    vector<int> table[26];
    for (int i = 0; i < S.length(); ++i)
        table[S[i] - 'a'].push_back(i);

    while (q--) {
        char a;
        int l, r;
        cin >> a >> l >> r;

        vector<int>& a_table = table[a - 'a'];
        int occurence = std::upper_bound(a_table.begin(), a_table.end(), r)
            - std::lower_bound(a_table.begin(), a_table.end(), l);
        cout << occurence << "\n";
    }
}
