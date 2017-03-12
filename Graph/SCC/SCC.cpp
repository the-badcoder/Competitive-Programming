#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define DFS_WHITE 0
#define DFS_BLACK 1
const int res = 1e5 + 10;

int dfs_low[res], dfs_num[res], numSCC, dfsNumberCounter;
bool visited[res];
vi S, graph[res];

void tarjanSCC( int u )
{
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    S.push_back( u );
    visited[u] = DFS_BLACK;

    for( int i = 0; i < graph[u].size(); i++ )
    {
        int v = graph[u][i];

        if( dfs_num[v] == -1 )
        {
            tarjanSCC( v );
        }
        if( visited[v] )
        {
            dfs_low[u] = min( dfs_low[u], dfs_low[v] );
        }
    }

    if( dfs_low[u] == dfs_num[u] )
    {
        printf("SCC %d:", ++numSCC );

        while( 1 )
        {
            int bk = S.back();
            S.pop_back();
            visited[ bk ] = DFS_WHITE;
            printf(" %d", bk );
            if( bk == u ) break;
        }
        printf("\n");
    }
}

int main()
{
    int nodes, edges;

    scanf("%d %d", &nodes, &edges );

    memset( dfs_num, -1, sizeof dfs_num );

    for( int i = 0; i < edges; i++ )
    {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back( v );
    }

    for( int i = 1; i <= nodes; i++ )
    {
        if( dfs_num[i] == -1 )
        {
            tarjanSCC( i );
        }
    }

    return 0;
}


