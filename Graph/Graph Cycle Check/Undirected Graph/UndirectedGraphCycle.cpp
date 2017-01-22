#include <bits/stdc++.h>

using namespace std;

#define DFS_BLACK 1
#define DFS_WHITE 0

const int maxn = 5000;
vector <int> graph[maxn];
bool used[maxn];
int nodes, edges, from, to, cc, cycle, flag = 0;
bool Hascycle;

void dfs( int u, int parent )
{
    used[u] = DFS_BLACK;

    for( auto child: graph[u] )
    {
        if( used[child] == DFS_WHITE )
        {
            dfs( child, u );
        }
        else if( child != parent )
        {
            Hascycle = true;
            return;
        }
    }
}

int main()
{
    scanf("%d %d", &nodes, &edges );

    for( int i = 0; i < edges; i++ )
    {
        scanf("%d %d", &from, &to );

        graph[from].push_back( to );
        graph[to].push_back( from );
    }

    memset( used, 0, sizeof used );

    for( int i = 1; i <= nodes; i++ )
    {
        if( used[i] == DFS_WHITE )        /// Connected Component
        {
            cc++;
            dfs( i, -1 );
        }
    }

    for( int i = 1; i <= nodes; i++ )
    {
        if( used[i] == DFS_WHITE )
        {
            dfs( i, -1 );
            if( Hascycle )
            {
                break;
            }
        }
    }

    if( Hascycle ) cout << "CYCLE FOUND\n";
    else cout << "NO CYCLE\n";

    return 0;
}


