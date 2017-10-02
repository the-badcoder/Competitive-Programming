#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int res = 1e5 + 10;

ll a[res], tree[ res * 4 ];

void build( int node, int b, int e )
{
    if( b == e )
    {
        tree[node] = a[b];
        return;
    }
    int left = node * 2;
    int right = left + 1;
    int mid = ( b + e ) / 2;

    build( left, b, mid );
    build( right, mid + 1, e );
    tree[node] = tree[left] + tree[right];
}

ll query( int node, int b, int e, int i, int j )
{
    if( i > e or j < b )
    {
        return 0;
    }
    if( b >= i and e <= j )
    {
        return tree[node];
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = ( b + e ) / 2;

    ll p1 = query( left, b, mid, i, j );
    ll p2 = query( right, mid + 1, e, i, j );
    return p1 + p2;
}

void update( int node, int b, int e, int i, ll value )
{
    if( i > e or i < b ){
        return;
    }
    if( b >= i and e <= i ){
        tree[node] = value;
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = ( b + e ) / 2;

    update( left, b, mid, i, value );
    update( right, mid + 1, e, i, value );
    tree[ node ] = tree[left] + tree[right];
}

int main()
{

    return 0;
}
