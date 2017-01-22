#include <bits/stdc++.h>

using namespace std;

/* This Programm Is For Basic DFS \
   And It Will Find \
   Connect Components Of An Undirected Graph.
   Practice Problem: UVA 459 --> Graph Connectivity.
*/

#define DFS_BLACK 1
#define DFS_WHITE 0

typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector < ii > vii;

const int INF = INT_MAX;
const int res = 1e5 + 5;

bool color[res];
vi graph[res];

void reset();
void dfs( int u );

int CC;

int main()
{
    int nodes, edges, u, v;

    while( scanf("%d %d", &nodes, &edges) == 2 )
    {
        reset();              /// Reset Everythings.

        for( int i = 0; i < edges; i++ )
        {
            scanf("%d %d", &u, &v);

            graph[u].push_back( v );
            graph[v].push_back( u );     /// For Undirected Graph.
        }

        for( int i = 0; i < nodes; i++ )
        {
            if( color[i] == DFS_WHITE )
            {
                CC++;             /// Count Connected Components And Call DFS.
                dfs( i );
            }
        }

        printf("%d Connected Components In This Graph.\n", CC );
    }
    return 0;
}

void dfs( int u )
{
    color[u] = DFS_BLACK;

    for( int i = 0; i < graph[u].size(); i++ )
    {
        int v = graph[u][i];

        if( color[v] == DFS_WHITE )
        {
            dfs( v );
        }
    }
}

void reset()
{
    CC = 0;
    for( int i = 0; i < res; i++ )
    {
        graph[i].clear();
        color[i] = DFS_WHITE;
    }
}

/* TEST INPUT: \

   9 7
   0 1
   1 2
   1 3
   2 3
   3 4
   7 6
   6 8

   OUTPUT: 3 Connected Components In This Graph.
*/
