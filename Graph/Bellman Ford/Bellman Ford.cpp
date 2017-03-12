#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;

int main()
{
    int V, E, s, a, b, w;
    vector<vii> graph;

    scanf("%d %d %d", &V, &E, &s );
    graph.assign(V, vii()); // assign blank vectors of pair<int, int>s to AdjList

    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &a, &b, &w );
        graph[a].push_back( ii(b, w) );
    }

    vi dist(V, INF);
    dist[s] = 0;
    bool hasNegativeCycle = false;

    for (int i = 0; i < V - 1; i++)   // relax all E edges V-1 times, overall O(VE)
    {
        for (int u = 0; u < V; u++)                         // these two loops = O(E)
        {
            for (int j = 0; j < (int)graph[u].size(); j++)
            {
                ii v = graph[u][j];        // we can record SP spanning here if needed
                dist[v.first] = min(dist[v.first], dist[u] + v.second);         // relax
            }
        }
    }

    for (int u = 0; u < V; u++)                           // one more pass to check
    {
        for (int j = 0; j < (int)graph[u].size(); j++)
        {
            ii v = graph[u][j];
            if (dist[v.first] > dist[u] + v.second)                 // should be false
                hasNegativeCycle = true;     // but if true, then negative cycle exists!
        }
    }
    printf("Negative Cycle Exist? %s\n", hasNegativeCycle ? "Yes" : "No");

    if (!hasNegativeCycle)
    {
        for (int i = 0; i < V; i++)
        {
            printf("SSSP(%d, %d) = %d\n", s, i, dist[i]);
        }
    }

    return 0;
}

