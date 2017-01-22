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
#define INF                   2147483647
#define space                 " "
#define all(x)                (x).begin(), (x).end()
#define clr(ar)               memset(ar, 0, sizeof(ar))

/*
template <class T> T gcd(T a,T b){ if(b == 0) return a; return gcd( b,a % b ); }
template <class T> T lcm(T a, T b ){ return ( a * b ) / gcd( a,b ); }
template<class T> string ToString(const T &x){ stringstream s; s << x; return s.str(); }
template<class T> int ToInteger(const T &x){ stringstream s; s << x; int r; s >> r; return r; }
*/


typedef  long long int           ll;
typedef  map<string,int>         msi;
typedef  map<int,int>	         mii;
typedef  map<ll, ll>             mll;
typedef  map<char,int>           mci;
typedef  map<int,string>	     mis;
typedef  pair<int,int> 	         pii;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef  vector<int> 	         vi;
typedef  vector<string> 	     vs;
typedef  vector<char>	         vc;
typedef  vector<bool>            vb;
typedef  vector< pii >           vii;


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

const int maxn = 1234;
int Rank[maxn], p[maxn];
vi setSize;
int numSets;

struct DisjointSet
{
    void make_set( int n )
    {
        numSets = n;       /// it will count number of disjointset.
        setSize.assign(n, 1); /// initially setsize is 1;

        for( int i = 0; i < n; i++ )
        {
            Rank[i] = 0;      /// at first time all rank  == 0;
            p[i] = i;         /// parent[i] == i;
        }
    }

    int findSet( int i )
    {
        return ( p[i] == i ) ? i : ( p[i] = findSet( p[i] ) ); /// Path Comperssions.
    }

    bool isSameSet( int i, int j )
    {
        return findSet(i) == findSet(j); /// return true or false;
    }

    void unionSet( int i, int j )
    {
        if( !isSameSet( i, j ) )
        {
            numSets--;
            int x = findSet( i ), y = findSet( j ); /// Finding Parents.

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
        return numSets;    /// Return component or numofdisjointset;
    }
    int sizeOfSet(int i)
    {
        return setSize[findSet(i)];
    }

} UF;

int main()
{
    int n;

    cin >> n;

    UF.make_set(n); // create 5 disjoint sets
    printf("%d\n", UF.numofdisjointset()); // 5
    UF.unionSet(0, 1);
    printf("%d\n", UF.numofdisjointset()); // 4
    UF.unionSet(2, 3);
    printf("%d\n", UF.numofdisjointset()); // 3
    UF.unionSet(4, 3);
    printf("%d\n", UF.numofdisjointset()); // 2
    //UF.unionSet(1, 3);
    printf("isSameSet(2, 1) = %d\n", UF.isSameSet(2, 1)); // will return 0 (false)
    printf("isSameSet(4, 3) = %d\n", UF.isSameSet(4, 3)); // will return 1 (true)

    for (int i = 0; i < 5; i++) // findSet will return 1 for {0, 1} and 3 for {2, 3, 4}
        printf("findSet(%d) = %d, sizeOfSet(%d) = %d\n", i, UF.findSet(i), i, UF.sizeOfSet(i));
    UF.unionSet(2, 0);
    printf("%d\n", UF.numofdisjointset()); // 1
    for (int i = 0; i < 5; i++) // findSet will return 3 for {0, 1, 2, 3, 4}
        printf("findSet(%d) = %d, sizeOfSet(%d) = %d\n", i, UF.findSet(i), i, UF.sizeOfSet(i));

}

