#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define Size 10000007

bool flag[Size];
vector <ll> Primes;

void seive()
{
    memset( flag, true, sizeof(flag) );

    flag[0] = flag[1] = false; /// True,When Needed.

    for( int i = 4; i <= Size; i += 2 ){
        flag[i] = false;
    }
    for( int i = 3; i * i <= Size; i += 2 ){
        if( flag[i] == true ){
            for( int j = i * i; j <= Size; j += (i << 2) ){
                flag[j] = false;
            }
        }
    }
}

int main()
{
    seive();
    Primes.clear();
    Primes.push_back(2);
    for( int i = 3; i <= Size; i += 2 ){
        if( flag[i] == true ){
            Primes.push_back(i);
        }
    }
    ll n, power, ans, sum;

    while( cin >> n ){
        ans = 1;
        sum = 1;
        for( int i = 0; i < Primes.size() && Primes[i]*Primes[i] <= n; i++ ){
            power = 0;
            while( n % Primes[i] == 0 ){
                power++;
                n /= Primes[i];
            }
            ans *= ( pow( Primes[i], power+1 ) - 1 );
            ans /= ( Primes[i] - 1 );
        }
        if( n > 1 ){
            sum *= pow( n, 2 );
            sum /= ( n - 1 );
        }
        cout << "Sum Of Divisors: " << sum*ans << endl;

    }
    return 0;
}


