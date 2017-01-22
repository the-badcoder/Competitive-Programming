#include <bits/stdc++.h>

using namespace std;

/// Problem: Lightoj: Drunk.

#define DFS_BLACK 1
#define DFS_WHITE 0

const int maxn = 2e4 + 10;
int used[maxn], color[maxn];
vector <int> graph[maxn];
bool Hascycle;
map <string, int> m;

void reset();

void dfs( int u )
{
    used[u] = color[u] = DFS_BLACK;

    for( int i = 0; i < graph[u].size(); i++ )
    {
        if( color[ graph[u][i] ] )
        {
            Hascycle = 1;
            return;
        }
        else if( used[ graph[u][i] ] == DFS_WHITE )
        {
            dfs( graph[u][i] );
        }
    }
    color[u] = 0;
}

int main()
{
    int test, x, n, loop = 0;

    cin >> test;

    while( test-- )
    {
        n = 0;
        scanf("%d", &x );

        while( x-- )
        {
            string s, s1;
            cin >> s >> s1;

            if( !m.count(s) )
            {
                m[s] = ++n;
            }
            if( !m.count(s1) )
            {
                m[s1] = ++n;
            }

            graph[ m[s] ].push_back( m[s1] );
        }

        memset( used, 0, sizeof used );
        memset( color, 0, sizeof color );

        for( int i = 1; i <= n; i++ )
        {
            if( used[i] == DFS_WHITE )
            {
                dfs( i );

                if( Hascycle )
                {
                    break;
                }
            }
        }

        if( Hascycle  )
        {
            printf("Case %d: No\n", ++loop );
        }
        else
        {
            printf("Case %d: Yes\n", ++loop );
        }
        reset();
        m.clear();
    }
    return 0;
}

void reset()
{
    Hascycle = false;
    for( int i = 0; i <= maxn; i++ )
    {
        graph[i].clear();
    }
}

