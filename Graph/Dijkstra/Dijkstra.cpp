#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 1e9;
const int res = 1e6 + 10;
typedef pair < int, int > ii;
typedef vector < int > vi;
typedef vector < ii > vii;

int s, path[res];

int main()
{
    int V, E, u, v, w, loop = 0, test;

    scanf("%d", &test );

    while( test-- )
    {
        vector < vii > graph;
        scanf("%d %d", &V, &E, &s ); // edges, nodes and source;
        graph.assign( V + 1, vii() ); // 1 based index -_-.

        for( int i = 1; i <= E; i++ )
        {
            scanf("%d %d %d", &u, &v, &w ); // edges and cost.
            //u--, v--; // for 0 based.
            graph[u].push_back( ii( v, w ) );
            graph[v].push_back( ii( u, w ) );
        }

        vi dist( V + 1, INF ); // 1 based index -_-.
        dist[s] = 0; // set dist of source == 0.

        priority_queue < ii, vector <ii>, greater <ii> > pq;
        pq.push( ii( 0, s ) ); // push source with dist 0.
        // ^to sort the pairs by increasing distance from s.

        while( !pq.empty() )
        {
            ii front = pq.top();
            pq.pop(); // greedy: pick shortest unvisited vertex.
            int d = front.first, u = front.second;
            if( d > dist[u] ) continue; // important;

            for( int j = 0; j < (int) graph[u].size(); j++ )
            {
                ii v = graph[u][j];
                if( dist[u] + v.second < dist[v.first] )
                {
                    path[v.first] = u;
                    dist[v.first] = dist[u] + v.second;
                    pq.push( ii(dist[v.first], v.first) );
                }
            }
        }

        if( dist[V] == INF )
        {
            printf("Case %d: Impossible\n", ++loop );
        }
        else
        {
            printf("Case %d: %d\n", ++loop, dist[V] );
        }
    }
    return 0;
}
