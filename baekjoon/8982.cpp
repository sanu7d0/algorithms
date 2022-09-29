#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
typedef vector<Section>::iterator MapIter;

struct Section
{
    int x1, x2, y;
    bool isHole = false;

    int size(int yBound)
    {
        return (yBound - y) * (x2 - x1);
    }
};

vector<Section> map;

void checkHole(int x1, int x2, int y)
{
    for (Section s : map)
    {
        if (s.x1 == x1 && s.x2 == x2 && s.y == y)
        {
            s.isHole = true;
            break;
        }
    }
}

MapIter *findMaxHeightHole(MapIter left, MapIter right)
{
    int maxHeight = 0;
    MapIter *res = NULL;
    for (MapIter iter = left; iter != right; ++iter)
    {
        if (iter->isHole && iter->y > maxHeight)
        {
            maxHeight = iter->y;
            res = &iter;
        }
    }
    return res;
}

int dp(MapIter left, MapIter right)
{
    if (left == map.end())
        return 0;

    if (left == right)
        return left->x;

    // max height hole in x bound
    MapIter *hole = findMaxHeightHole(left, right);
    if (hole == NULL)
    {
        //
    }

    return dp(map.begin(), hole) + dp(hole, map.end());
}

int main()
{
    fastio;

    int N, K;

    cin >> N;
    {
        int x1, x2, y;
        cin >> x1 >> y; // (0,0)
        for (int i = 0; i < N / 2 - 1; ++i)
        {
            cin >> x1 >> y;
            cin >> x2 >> y;
            map.push_back({x1, x2, y});
        }
        cin >> x2 >> y; // (w, 0)
    }

    cin >> K;
    {
        int x1, x2, y;
        for (int i = 0; i < K; ++i)
        {
            cin >> x1 >> y >> x2 >> y;
            checkHole(x1, x2, y);
        }
    }

    cout << dp(0, 40000, 0) << endl;
}
