// other's approach: topological sort

#include <stdio.h>
#include <vector>
using namespace std;

const int INF = 1000000;

int bellman_ford(vector<vector<pair<int,int>>> edge,int start)
{
	vector<int> distance(edge.size(),INF);
	distance[start] = 0;

    int shortest = INF;
	for (int n = 0; n < edge.size() - 1; n++)
	{
		for (int i = 0; i < edge.size(); i++)
		{
			for (int j = 0; j < edge[i].size(); j++)
			{
				int v = edge[i][j].first;
				int cost = edge[i][j].second;

				if (distance[i] != INF && distance[v] > distance[i] + cost)
				{
					distance[v] = distance[i] + cost;
                    shortest = min(shortest, distance[v]);
				}
			}
		}
	}

    return shortest;
}

int main() {
    freopen("input.txt", "r", stdin);
    
    int T, n, k, w;

    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &n, &k);
        vector<vector<pair<int, int>>> edge(n+1);
        
        int *cost = new int[n+1]();
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &cost[i+1]);
            // store as negative
            cost[i+1] *= -1;
        }

        int from, to;
        for (int i = 0; i < k; i++)
        {
            scanf("%d %d", &from, &to);
            // link reversely
            edge[to].push_back(make_pair(from, cost[from]));
        }

        scanf("%d", &w);
        if (edge[w].size() == 0)
        {
            printf("%d\n", -cost[w]);
        } else
        {
            printf("%d\n", -bellman_ford(edge, w) - cost[w]);
        }

        delete[] cost;
    }
}
