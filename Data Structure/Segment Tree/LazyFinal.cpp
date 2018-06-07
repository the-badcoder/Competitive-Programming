#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int res = 1e5 + 10;

/// UPDATE TREE == ADD "VALUE" [ L, R ]. That's why += lazy[ node ].

ll a[ res ], tree[ res * 4 ], lazy[ res * 4 ];

void build_tree( int node, int b, int e )
{
    if( b > e ) return;
    if( b == e )
    {
        tree[ node ] = a[ b ];
        return;
    }
    int mid = ( b + e ) / 2;
    int Left = node * 2;
    int Right = node * 2 + 1;
    build_tree( Left, b, mid );
    build_tree( Right, mid + 1, e );
    tree[ node ] = tree[ Left ] + tree[ Right ];
}

void pushDown( int node, int b, int e )
{
    if( lazy[ node ] != 0 )
    {
        tree[ node ] += ( e - b + 1 ) * lazy[ node ]; // update it.
        if( b != e )
        {
            lazy[ node * 2 ] += lazy[ node ];
            lazy[ node * 2 + 1 ] += lazy[ node ];
        }
        lazy[ node ] = 0; // reset.
    }
}

void update_tree( int node, int b, int e, int i, int j, ll value )
{
    pushDown( node, b, e );

    if( i > e || j < b )
    {
        return;
    }
    if( b >= i && e <= j )
    {
        tree[ node ] += ( e - b + 1 ) * value;
        if( b != e )
        {
            lazy[ node * 2 ] += value;
            lazy[ node * 2 + 1 ] += value;
        }
        return;
    }
    int mid = ( b + e ) / 2;
    int Left = node * 2;
    int Right = node * 2 + 1;
    update_tree( Left, b, mid, i, j, value );
    update_tree( Right, mid + 1, e, i, j, value );

    tree[ node ] = tree[ Left ] + tree[ Right ];
}

ll query( int node, int b, int e, int i, int j )
{
    if( i > e or j < b )
    {
        return 0;
    }

    pushDown( node, b, e );

    if( b >= i && e <= j )
    {
        return tree[ node ];
    }

    int mid = ( b + e ) >> 1;
    int Left = node << 1;
    int Right = Left | 1;
    return query( Left, b, mid, i, j ) + query( Right, mid + 1, e, i, j );
}


int main()
{
    return 0;
}
