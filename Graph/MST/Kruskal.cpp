#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

#define WRITE  freopen("output.txt", "w", stdout);

const int maxn = 1e5 + 5;
int Rank[maxn], p[maxn];
int numSets;
vector <int> setSize;
map <string, int> m;

struct DisjointSet
{
    void make_set( int x )
    {
        numSets = x;
        setSize.assign( x + 1 , 1 );       /// 1 Based.
        for( int i = 1; i <= x; i++ )
        {
            Rank[i] = 0;
            p[i] = i;
        }
    }

    int findSet( int x )
    {
        return ( p[x] == x ) ? x : ( p[x] = findSet( p[x] ) );
    }

    bool isSameSet( int i, int j )
    {
        return findSet(i) == findSet(j);
    }

    void unionSet( int i, int j )
    {
        if( !isSameSet( i, j ) )
        {
            numSets--;
            int x = findSet(i), y = findSet(j);

            if( Rank[x] > Rank[y] )
            {
                p[y] = x;
                setSize[x] += setSize[y];
            }
            else
            {
                p[x] = y;
                setSize[y] += setSize[x];

                if( Rank[x] == Rank[y] )
                {
                    Rank[y]++;
                }
            }
        }
    }

    int numofdisjointset()
    {
        return numSets;
    }
    int sizeOfSet(int i)
    {
        return setSize[findSet(i)];
    }

} UF;

int main()
{
    int V, E, u, v, w, mst_cost, test, taka, sum, loop = 0, total, cost;
    vector <int> store;
    string s, s1;

    scanf("%d", &test );

    while( test-- )
    {
        scanf("%d %d %d", &V, &E, &taka );

        vector < pair < int, ii > > Edgelist;

        Edgelist.clear();
        sum = 0;
        mst_cost = 0;

        for( int i = 0; i < E; i++ )
        {
            cin >> u >> v >> w;
            Edgelist.push_back( make_pair( w, ii ( u, v ) ) );  // Reverse Sort with : -w.
        }

        sort( Edgelist.begin(), Edgelist.end() );
        UF.make_set( V );

        for( int i = 0; i < E; i++ )
        {
            if( !UF.isSameSet( Edgelist[i].second.first, Edgelist[i].second.second ) )
            {
                mst_cost += Edgelist[i].first;
                UF.unionSet( Edgelist[i].second.first, Edgelist[i].second.second );
            }
        }

        printf("%d\n", mst_cost );
        sum = mst_cost = 0;
    }

    return 0;
}

