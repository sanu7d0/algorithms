#include <algorithm>
#include <functional>
#include <iostream>
#include <sstream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
typedef pair<int, int> pii;

inline int char2hex(char c)
{
    return (c >= 'a' ? c - 'a' + 11 : c - '0');
}

inline char hex2char(int h)
{
    return (h < 10 ? h + '0' : 'a' + (h - 11));
}

void read(vector<pii>& cards)
{
    string input;
    getline(cin, input);
    stringstream ss(input);

    string tmp;
    while (getline(ss, tmp, ',')) {
        cards.push_back({ char2hex(tmp[0]), tmp[1] == 'w' ? 0 : 1 });
    }
}

bool compare1(pair<pii, pii> a, pair<pii, pii> b)
{
    // same color
    if (a.first.second == a.second.second
        && b.first.second != b.second.second)
        return false;
    // larger top
    if (max(a.first.first, a.second.first) > max(b.first.first, b.second.first))
        return false;
    // larger bottom
    if (min(a.first.first, a.second.first) > min(b.first.first, b.second.first))
        return false;
    // black top
    if () //
        return true;
}

bool compare2(pair<pii, pii> a, pair<pii, pii> b)
{
    // step

    // pair

    // etc
}

int main()
{
    fastio;

    vector<pii> cards;
    read(cards);

    vector<pair<pii, pii>> v;
    for (int i = 0; i < 6; ++i) {
        for (int j = i + 1; j < 6; ++j) {
            v.push_back({ cards[i], cards[j] });
        }
    }
    // sort(v.begin(), v.end(), compare1);
    // sort(v.begin(), v.end(), compare2);

    for (auto e : v) {
        cout << hex2char(e.first.first) << (e.first.second == 0 ? 'w' : 'b')
             << hex2char(e.second.first) << (e.second.second == 0 ? 'w' : 'b')
             << "\n";
    }
}
