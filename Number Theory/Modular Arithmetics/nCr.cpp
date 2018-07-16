#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int res = 1e6 + 1;
const ll mod = 1e9 + 7;

ll factorial[ res ], dp[ res ], ans;
int n, a, b;

void pre_cal()
{
    factorial[ 0 ] = 1ll;
    for( int i = 1; i <= res; i++ )
    {
        factorial[ i ] = ( factorial[ i - 1 ] * i ) % mod;
    }
}

ll bigMod( ll b, ll p, ll m )
{
    if( p == 0 ) return 1 % m;
    if( p % 2 == 0 )
    {
        ll y = bigMod( b, p / 2, m );
        return ( y * y ) % m;
    }
    else
    {
        return ( b * bigMod( b, p - 1, m ) ) % m;
    }
}

ll nCr( ll n, ll r )
{
    ll nFact = factorial[ n ];
    nFact = ( nFact * bigMod( factorial[ r ], mod - 2, mod ) ) % mod;
    nFact = ( nFact * bigMod( factorial[ n - r ], mod - 2, mod ) ) % mod;
    return nFact;
}

int main()
{
    pre_cal();

    return 0;
}
