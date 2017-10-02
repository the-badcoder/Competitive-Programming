#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
bool flag [N];
vector <int> prime;

void sieve ()
{
    memset (flag, true, sizeof (flag));

    flag [0] = flag [1] = false;

    for ( int i = 4; i < N; i += 2 )
        flag [i] = false;

    for ( int i = 3; i * i <= N; i++ )
    {
        if ( flag [i] == true )
        {
            for ( int j = i * i; j < N; j += 2 * i )
                flag [j] = false;
        }
    }

    prime.clear ();
    prime.push_back (2);

    for ( int i = 3; i < N; i += 2 )
    {
        if ( flag [i] )
            prime.push_back (i);
    }
}

int main ()
{
    sieve ();

    vector <int> twinPrime;

    for ( size_t i = 1; i < prime.size(); i++ )
    {

        if ( prime [i] == prime [i-1] + 2 )
            twinPrime.push_back (prime [i-1] );
    }

    int n, c = 0;

    while ( scanf ("%d", &n) != EOF )
    {

        printf ("(%d, %d)\n", twinPrime [ n - 1 ], twinPrime [ n - 1 ] + 2);
    }

    return 0;
}
