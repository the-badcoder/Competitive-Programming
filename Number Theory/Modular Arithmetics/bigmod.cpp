/// Bismillah Hir Rahmanir Rahim
#include <bits/stdc++.h>

using namespace std;

using ll = long long int;

ll bigmod( ll b, ll p, ll m )
{
    if( p == 0 ) return 1 % m;

    if( p % 2 == 0 )
    {
        ll y = bigmod( b, p / 2, m );
        return (y * y) % m;
    }

    else
    {
        return ( b * bigmod( b, p - 1, m ) ) % m;
    }
}

int main()
{
    ll b, p, m, sum;

    while( cin >> b >> p >> m )
    {

        sum = bigmod(b, p, m);

        cout << sum << endl;
    }
    return 0;
}

