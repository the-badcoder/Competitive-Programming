#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int sz = 5e5 + 10;

long long phi[sz];

void call_phi()
{
    int i, j;
    phi[1] = 1;
    for( int i = 2; i < sz; i++ )
    {
        phi[i] = i;
    }
    for( i = 2; i < sz; i++ )
    {
        if( phi[i] == i )
        {
            for( j = i; j < sz; j += i )
            {
                phi[j] -= phi[j] / i;
            }
        }
    }
}

int main()
{
    call_phi();
    int test, loop = 0;
    long long a, b, sum;
    ll x, y;

    cin >> test;

    while( test-- )
    {
        cin >> x;

        cout << phi[ x ] << endl;
    }
}

