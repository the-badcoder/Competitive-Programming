#include <bits/stdc++.h>

using namespace std;

#define White 0
#define Black 1
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector < ii > vii;

const int INF = INT_MAX;
const int res = 1e5 + 5;

bool color[res], bipartite[res];
vi graph[res];

void bfs( int s );
void reset();

int main()
{
    int nodes, edges, u, v;

    while( scanf("%d", &nodes ) && nodes != 0 )
    {
        scanf("%d", &edges );

        reset();              /// Reset Everythings.
        for( int i = 0; i < edges; i++ )
        {
            scanf("%d %d", &u, &v);

            graph[u].push_back( v );
            graph[v].push_back( u );     /// For Undirected Graph.
        }

        bfs( 0 ); /// Call BFS.
    }
    return 0;
}

void bfs( int s )
{
    queue <int> q;
    q.push( s );

    color[s] = Black;
    bipartite[s] = 0;

    bool isbipartite = true;

    while( !q.empty() )
    {
        int u = q.front();
        q.pop();
        for( int i = 0; i < graph[u].size(); i++ )
        {
            int v = graph[u][i];

            if( color[v] == White )
            {
                bipartite[v] = 1 - bipartite[u];       /// Conditions for Bipartite Graph.

                color[v] = Black;
                q.push( v );
            }
            else if( bipartite[v] == bipartite[u] )
            {
                isbipartite = false;
            }
        }
    }

    if( isbipartite == true )
    {
        printf("BICOLORABLE.\n");
    }
    else
    {
        printf("NOT BICOLORABLE.\n");
    }
}

void reset()
{
    for( int i = 0; i < res; i++ )
    {
        graph[i].clear();
        color[i] = White;
        bipartite[i] = 0;
    }
}

