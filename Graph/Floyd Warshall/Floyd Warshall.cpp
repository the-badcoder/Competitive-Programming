#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main()
{
    int V, E, u, v, w, graph[200][200], parent[200][200];

    scanf("%d %d", &V, &E);

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            graph[i][j] = INF;
            graph[i][i] = 0;
            parent[i][j] = i;
        }
    }

    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w; // directed graph
    }

    for (int k = 0; k < V; k++)  // common error: remember that loop order is k->i->j
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                /*
                if( graph[i][k] + graph[k][j] < graph[i][j] ){
                    graph[i][j] = graph[i][k] + graph[k][j]; // For Parent.
                    parent[i][j] = parent[k][j];
                }
                */
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("APSP(%d, %d) = %d\n", i, j, graph[i][j]);
        }
    }

    return 0;
}

void printPath( int i, int j )
{
    if( i != j ) printPath( i, parent[i][j] );
    printf(" %d", j );
}
