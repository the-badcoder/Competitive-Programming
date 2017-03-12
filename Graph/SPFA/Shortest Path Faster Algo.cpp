#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
using INF = 2e9;

int i, j, t, n, m, S, T, a, b, w, caseNo = 1;
vector<vii> graph;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d %d %d", &n, &m, &S, &T );
        // UVA: Sending Email.
        graph.assign(n, vii());
        while (m--)
        {
            scanf("%d %d %d", &a, &b, &w );
            graph[a].push_back( ii(b, w) ); // bidirectional
            graph[b].push_back( ii(a, w) );
        }
        // SPFA from source S
        // initially, only S has dist = 0 and in the queue
        vi dist(n, INF);
        dist[S] = 0;
        queue<int> q;
        q.push(S);
        vi in_queue(n, 0 );
        in_queue[S] = 1;

        while (!q.empty() )
        {
            int u = q.front();
            q.pop();
            in_queue[u] = 0;
            for (j = 0; j < (int)graph[u].size(); j++)   // all outgoing edges from u
            {
                int v = graph[u][j].first, weight_u_v = graph[u][j].second;
                if (dist[u] + weight_u_v < dist[v])   // if can relax
                {
                    dist[v] = dist[u] + weight_u_v; // relax
                    if (!in_queue[v])   // add to the queue only if it's not in the queue
                    {
                        q.push(v);
                        in_queue[v] = 1;
                    }
                }
            }
        }

        printf("Case #%d: ", caseNo++);
        if (dist[T] != INF)
        {
            printf("%d\n", dist[T]);
        }
        else
        {
            printf("unreachable\n");
        }
    }

    return 0;
}

