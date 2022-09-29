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
        if (cards[i] != p[i])
            return false;
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

    cout << "aaa\n";

    cin >> N;
    p = vector<int>(N);
    s = vector<int>(N);
    cards = vector<int>(N);

    for (int i = 0; i < N; ++i)
        cin >> p[i];
    for (int i = 0; i < N; ++i)
        cin >> s[i];
    for (int i = 0; i < N; ++i)
        cards[i] = i;

    int shuffleCount = 0;
    while (true)
    {
        auto tempCards = vector<int>(cards);
        for (int i = 0; i < N; ++i)
        {
            cards[s[i]] = tempCards[i];
        }

        if (checkCards())
            break;

        if (checkShuffleLoop())
        {
            shuffleCount = -1;
            break;
        }

        shuffleCount++;
    }

    cout << shuffleCount << endl;
}
