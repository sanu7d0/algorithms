#include <algorithm>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N;
vector<int> p;
vector<int> s;
vector<int> cards;

bool checkCards()
{
    for (int i = 0; i < N; ++i)
    {
        if (p[cards[i]] != i % 3)
            return false;
    }
    return true;
}

bool checkShuffleLoop()
{
    for (int i = 0; i < N; ++i)
        if (cards[i] != i)
            return false;
    return true;
}

int main()
{
    fastio;

    cin >> N;
    p = vector<int>(N);
    s = vector<int>(N);
    cards = vector<int>(N);

    int idxCount[3] = {};
    int x;
    for (int i = 0; i < N; ++i)
        cin >> p[i];
    for (int i = 0; i < N; ++i)
        cin >> s[i];
    for (int i = 0; i < N; ++i)
        cards[i] = i;

    int shuffleCount = 0;
    while (true)
    {
        if (checkCards())
            break;

        auto tempCards = vector<int>(cards);
        for (int i = 0; i < N; ++i)
            cards[s[i]] = tempCards[i];
        shuffleCount++;

        if (checkShuffleLoop())
        {
            shuffleCount = -1;
            break;
        }
    }

    cout << shuffleCount << endl;
}
