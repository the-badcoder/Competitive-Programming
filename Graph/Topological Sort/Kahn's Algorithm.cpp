#include <bits/stdc++.h>

// Uva: 11060.

using namespace std;
const int res = 1e5 + 5;

int in_degree[res];
vector <int> graph[res], topsort;

int main()
{
    int v, e;

    scanf("%d %d", &v, &e );

    for( int i = 0; i < e; i++ )
    {
        int u, v;
        scanf("%d %d", &u, &v );
        graph[u].push_back( v );
        in_degree[v]++;
    }

    priority_queue<int, vector <int>, greater<int> > q;
    // enqueue nodes with 0 incoming degree into priority queue.

    for( int i = 0; i < v; i++ )
    {
        if( in_degree[i] == 0 )
        {
            q.push( i );
        }
    }

    while( !q.empty() )
    {
        int u = q.top();
        topsort.push_back( u );
        q.pop();

        for( int i = 0; i < graph[u].size(); i++ )
        {
            int v = graph[u][i];
            //remove all outgoing edges from the vertex u;
            in_degree[v]--;
            // if such removal cause vertex v to have 0 incoming degree
            // enqueue it
            if( in_degree[v] == 0 )
            {
                q.push( v );
            }
        }
    }

    for( auto it: topsort )
    {
        cout << it << " ";
    }

    return 0;
}
