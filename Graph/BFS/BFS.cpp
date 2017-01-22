#include <bits/stdc++.h>

using namespace std;

const int res = 1e5 + 5;
vector <int> graph[res];
int visited[res], dist[res], path[res], start, nodes;

void printPath(int u)
{
    if ( u == start )
    {
        printf("%d", u);
        return;
    }
    printPath( path[u] );   // recursive call: to make the output format: s -> ... -> t
    printf(" %d", u);
}

void bfs( int s  )
{
    queue <int> q;
    q.push( s );

    visited[s] = 1;
    dist[s] = 0;            // Distance of source = 0.
    path[s] = -1;           // Path of source = -1.

    while( !q.empty() )
    {
        int u = q.front();
        q.pop();

        for( int i = 0; i < graph[u].size(); ++i )
        {
            int v = graph[u][i];

            if( visited[ v ] == 0 )
            {
                visited[v] = 1;
                dist[v] = dist[u] + 1;
                path[v] = u;                    // Set Parent of v is u.
                q.push( v );
            }
        }
    }
}

int main()
{
    int nodes, edges, u, v, yourpath;

    scanf("%d %d", &nodes, &edges );

    for( int i = 0; i < edges; i++ )
    {
        scanf("%d %d", &u, &v );

        graph[u].push_back( v );
        graph[v].push_back( u );
    }

    printf("Enter The Path You Want To Print:\n");
    scanf("%d", &yourpath);

    bfs( 0 );                    // Call BFS.
    printPath( yourpath );       // Call PrintPath.

    return 0;
}


