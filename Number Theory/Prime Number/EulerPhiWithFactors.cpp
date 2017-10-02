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
/* Input:
   123456789
   10000000
   Output:
   82260072
   400000000
*/
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
    ll n, ans;

    while( cin >> n ){
        ans = n;
        for( int i = 0; i < Primes.size() && Primes[i]*Primes[i] <= n; i++ ){
            if( n % Primes[i] == 0 ){
                ans -= ans / Primes[i];
                while( n % Primes[i] == 0 ){
                    n /= Primes[i];
                }
            }
        }
        if( n > 1 ){
            ans -= ans / n;
        }
        cout << "Euler Phi: " << ans << endl;
    }
    return 0;
}

