#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int res = 1e6 + 10;

ll a[res], tree[res * 4], lazy[res * 4];

void pushDown( int node, int b, int e )
{
    if( lazy[ node ] == 0 ) return;
    int mid = ( b + e ) >> 1;
    int Left = node << 1;
    int Right = Left | 1;
    lazy[ Left ] += lazy[ node ];
    lazy[ Right ] += lazy[ node ];
    tree[ Left ] += ( mid - b + 1 ) * lazy[ node ];
    tree[ Right ] += ( e - mid ) * lazy[ node ];
    lazy[ node ] = 0;
}

void update( int node, int b, int e, int i, int j, ll value )
{
    if( b > j || e < i ) return;
    if( b >= i && e <= j )
    {
        tree[ node ] += ( e - b + 1 );
        lazy[ node ] += value;
        return;
    }
    pushDown( node, b, e );
    int mid = ( b + e ) >> 1;
    int Left = node << 1;
    int Right = Left | 1;
    update( Left, b, mid, i, j, value );
    update( Right, mid + 1, e, i, j, value );
    tree[ node ] = tree[ Left ] + tree[ Right ];
}

ll query( int node, int b, int e, int i, int j )
{
    if( b > j || e < i ) return 0;
    if( b >= i && e <= j ) return tree[ node ];
    pushDown( node, b, e );
    int mid = ( b + e ) >> 1;
    int Left = node << 1;
    int Right = Left | 1;
    return query( Left, b, mid, i, j ) + query( Right, mid + 1, e, i, j );
}

int main()
{


    return 0;
}
