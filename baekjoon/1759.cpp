#include <algorithm>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int L, C;
vector<char> v;
vector<string> ans;

int count_vowel(const string& s)
{
    int count = 0;
    for (char c : s)
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            count++;
    return count;
}

void traverse(string s, int idx)
{
    s += v[idx];
    if (s.length() == L) {
        int vowels = count_vowel(s);
        if (vowels >= 1 && (L - vowels) >= 2) {
            // hit
            ans.push_back(s);
        }
        return;
    }
    if (idx == C - 1)
        return;

    for (int i = 1; i < C - idx; ++i) {
        traverse(s, idx + i);
    }
}

int main()
{
    fastio;

    cin >> L >> C;
    v = vector<char>(C);

    for (int i = 0; i < C; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    for (int i = 0; i <= C - L; ++i)
        traverse("", i);

    for (auto s : ans)
        cout << s << "\n";
}
