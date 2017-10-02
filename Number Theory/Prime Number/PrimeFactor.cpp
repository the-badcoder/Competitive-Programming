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
    ll n;
    int digit;
    set <int> dif;

    while( cin >> n ){
        digit = 0;
        for( int i = 0; i < Primes.size() && Primes[i]*Primes[i] <= n; i++ ){
            while( n % Primes[i] == 0 ){
                digit++;
                dif.insert(Primes[i]);
                n /= Primes[i];
            }
        }
        if( n > 1 ){
            dif.insert(n);
            digit++;
        }
        cout << "Total Prime Factor: " << digit << endl;
        cout << "Total Different Prime Factor: " << dif.size() << endl;
        dif.clear();
    }
    return 0;
}
