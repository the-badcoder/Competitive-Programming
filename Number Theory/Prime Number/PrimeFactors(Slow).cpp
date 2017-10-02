#include <bits/stdc++.h>

using namespace std;

/// Input: 100
/// Output: 2 2 5 5

void primeFactors( int n )
{
     while( n % 2 == 0 ){
        printf("%d ", 2);
        n /= 2;
     }

     for( int i = 3; i <= sqrt(n); i += 2 ){
        while( n % i == 0 ){
            printf("%d ", i );
            n /= i;
        }
     }
     if( n > 2 ){
        printf("%d ", n );
     }
}

int main()
{
    int n;
    cin >> n;

    primeFactors(n);
    return 0;
}
