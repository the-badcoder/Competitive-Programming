/// Bismillah Hir Rahmanir Rahim

#include <bits/stdc++.h>

using namespace std;

#define PI                    acos(-1.0)
#define Pi                    3.141592653589793
#define ff                    first
#define ss                    second
#define mp                    make_pair
#define pb                    push_back
#define eb                    emplace_back
#define mod                   1e7
#define space                 " "
#define all(x)                (x).begin(), (x).end()
#define clr(ar)               memset(ar, 0, sizeof(ar))

/*
template <class T> T gcd(T a,T b){ if(b == 0) return a; return gcd( b,a % b ); }
template <class T> T lcm(T a, T b ){ return ( a * b ) / gcd( a,b ); }
template<class T> string ToString(const T &x){ stringstream s; s << x; return s.str(); }
template<class T> int ToInteger(const T &x){ stringstream s; s << x; int r; s >> r; return r; }
*/


typedef  long long int            ll;
typedef  map<string,int>          msi;
typedef  map<int,int>	          mii;
typedef  map<ll, ll>              mll;
typedef  map<char,int>            mci;
typedef  map<char,string>         mcs;
typedef  map<int,string>	      mis;
typedef  pair<int,int> 	          pii;
typedef  pair<string, int>        psi;
typedef  pair<string, string>     pss;
typedef  vector<int> 	          vi;
typedef  vector<string> 	      vs;
typedef  vector<char>	          vc;
typedef  vector< pii >            vii;


template<class T1> void deb(T1 e1)
{
    cout << e1 << endl;
}
template<class T1,class T2> void deb(T1 e1, T2 e2)
{
    cout << e1 << space << e2 << endl;
}
template<class T1,class T2,class T3> void deb(T1 e1, T2 e2, T3 e3)
{
    cout << e1 << space << e2 << space << e3 << endl;
}

#define sf                    scanf
#define pf                    printf

#define sf1(a)                scanf("%d", &a)
#define sf2(a,b)              scanf("%d %d",&a, &b)
#define sf3(a,b,c)            scanf("%d %d %d", &a, &b, &c)

#define sf1ll(a)              scanf("%I64d", &a)
#define sf2ll(a,b)            scanf("%I64d %I64d", &a, &b)
#define sf3ll(a,b,c)          scanf("%I64d %I64d %I64d", &a, &b, &c)

#define READ                  freopen("input.txt", "r", stdin);
#define WRITE                 freopen("output.txt", "w", stdout);
/// The End.


const int INF = INT_MAX;
const int res = 2e4 + 5;

int nodes;
vi graph[res];
vii bridges;
vi points;
int dfs_num[res], dfs_low[res], dfs_parent[res], rootChildren, dfsRoot, dfsNumberCounter, cc;
bool articulation_vertex[res];

void reset();

void articulationPointAndBridge( int u )
{
    dfs_low[u] = dfs_num[u] = ++dfsNumberCounter;

    for( int i = 0; i < graph[u].size(); i++ )
    {
        int v = graph[u][i];

        if( dfs_num[v] == 0 )
        {
            dfs_parent[v] = u;

            if( u == dfsRoot )
            {
                rootChildren++;  // special case.
            }

            articulationPointAndBridge( v );

            dfs_low[u] = min( dfs_low[u], dfs_low[v] );

            if( dfs_low[v] >= dfs_num[u] )
            {
                articulation_vertex[u] = true; // for point.
            }
            if( dfs_low[v] > dfs_num[u] )
            {
                //printf("Edge (%d %d) is a bridge.\n", u, v ); // for bridge.
                bridges.push_back( { u, v } );
            }
        }
        else if( v != dfs_parent[u] )
        {
            dfs_low[u] = min( dfs_low[u], dfs_num[v] ); // a back edge and not direct cycle, update dfs_low[u].
        }
    }
}

int main()
{
    //WRITE;
    int edges, sum, total, test, loop = 0;

    sf1( test );

    while( test-- )
    {
        reset();

        sf2( nodes, edges );

        while( edges-- )
        {
            int u, v;

            sf2( u, v );
            //u--, v--; // for 0 based.

            graph[u].push_back( v );
            graph[v].push_back( u );
        }

        for( int i = 1; i <= nodes; i++ ) // for bridges printing.
        {
            /// be carefull about 0 and 1 based index.
            if( dfs_num[i] == 0 )
            {
                dfsRoot = i;
                rootChildren = 0;
                articulationPointAndBridge( i );
                articulation_vertex[dfsRoot] = (rootChildren > 1);
            }
        }

        for( int i = 1; i <= nodes; i++ ) // for articulations point.
        {
            /// be carefull about 0 and 1 based index.
            if( articulation_vertex[i] )
            {
                points.push_back( i );
                cc++; // num of a.points.
                //printf("%d\n", i );
            }
        }

        printf("Case %d: %d\n", ++loop, cc );
    }
}

void reset()
{
    clr( articulation_vertex );
    for( int i = 1; i <= res; i++ )
    {
        graph[i].clear();
    }
    clr( dfs_num );
    clr( dfs_low );
    clr( dfs_parent );
    dfsNumberCounter = 0;
    dfsRoot = 0;
    cc = 0;
    rootChildren = 0;
}

