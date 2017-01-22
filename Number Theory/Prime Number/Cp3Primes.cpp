#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef map<int, int> mii;

ll _sieve_size;
bitset<10000010> bs;   // 10^7 should be enough for most cases
vi primes;   // compact list of primes in form of vector<int>

void sieve(ll upperbound)            // create list of primes in [0..upperbound]
{
    _sieve_size = upperbound + 1;                   // add 1 to include upperbound
    bs.set();                                                 // set all bits to 1
    bs[0] = bs[1] = 0;                                     // except index 0 and 1
    for (ll i = 2; i <= _sieve_size; i++) if (bs[i])
        {
            // cross out multiples of i starting from i * i!
            for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
            primes.push_back((int)i);  // also add this vector containing list of primes
        }
}                                           // call this method in main method

bool isPrime(ll N)                   // a good enough deterministic prime tester
{
    if (N <= _sieve_size) return bs[N];                   // O(1) for small primes
    for (int i = 0; i < (int)primes.size(); i++)
        if (N % primes[i] == 0) return false;
    return true;                    // it takes longer time if N is a large prime!
}                      // note: only work for N <= (last prime in vi "primes")^2

vi primeFactors(ll N)
{
    vi factors;
    ll PF_idx = 0, PF = primes[PF_idx];     // using PF = 2, 3, 4, ..., is also ok
    while (N != 1 && (PF * PF <= N))     // stop at sqrt(N), but N can get smaller
    {
        while (N % PF == 0)
        {
            N /= PF;    // remove this PF
            factors.push_back(PF);
        }
        PF = primes[++PF_idx];                              // only consider primes!
    }
    if (N != 1) factors.push_back(N);     // special case if N is actually a prime
    return factors;         // if pf exceeds 32-bit integer, you have to change vi
}

ll numPF(ll N)
{
    ll PF_idx = 0, PF = primes[PF_idx], ans = 0;
    while (N != 1 && (PF * PF <= N))
    {
        while (N % PF == 0)
        {
            N /= PF;
            ans++;
        }
        PF = primes[++PF_idx];
    }
    if (N != 1) ans++;
    return ans;
}

ll numDiffPF(ll N)
{
    ll PF_idx = 0, PF = primes[PF_idx], ans = 0;
    while (N != 1 && (PF * PF <= N))
    {
        if (N % PF == 0) ans++;                           // count this pf only once
        while (N % PF == 0) N /= PF;
        PF = primes[++PF_idx];
    }
    if (N != 1) ans++;
    return ans;
}

ll sumPF(ll N)
{
    ll PF_idx = 0, PF = primes[PF_idx], ans = 0;
    while (N != 1 && (PF * PF <= N))
    {
        while (N % PF == 0)
        {
            N /= PF;
            ans += PF;
        }
        PF = primes[++PF_idx];
    }
    if (N != 1) ans += N;
    return ans;
}

ll numDiv(ll N)
{
    ll PF_idx = 0, PF = primes[PF_idx], ans = 1;             // start from ans = 1
    while (N != 1 && (PF * PF <= N))
    {
        ll power = 0;                                             // count the power
        while (N % PF == 0)
        {
            N /= PF;
            power++;
        }
        ans *= (power + 1);                              // according to the formula
        PF = primes[++PF_idx];
    }
    if (N != 1) ans *= 2;             // (last factor has pow = 1, we add 1 to it)
    return ans;
}

ll sumDiv(ll N)
{
    ll PF_idx = 0, PF = primes[PF_idx], ans = 1;             // start from ans = 1
    while (N != 1 && (PF * PF <= N))
    {
        ll power = 0;
        while (N % PF == 0)
        {
            N /= PF;
            power++;
        }
        ans *= ((ll)pow((double)PF, power + 1.0) - 1) / (PF - 1);         // formula
        PF = primes[++PF_idx];
    }
    if (N != 1) ans *= ((ll)pow((double)N, 2.0) - 1) / (N - 1);        // last one
    return ans;
}

ll EulerPhi(ll N)
{
    ll PF_idx = 0, PF = primes[PF_idx], ans = N;             // start from ans = N
    while (N != 1 && (PF * PF <= N))
    {
        if (N % PF == 0) ans -= ans / PF;                // only count unique factor
        while (N % PF == 0) N /= PF;
        PF = primes[++PF_idx];
    }
    if (N != 1) ans -= ans / N;                                     // last factor
    return ans;
}

int main()
{
    sieve(10000000);
    printf("%d\n", isPrime(2147483647));
    printf("%d\n", isPrime(136117223861LL));

    vi res = primeFactors(2147483647);
    for (vi::iterator i = res.begin(); i != res.end(); i++) printf("> %d\n", *i);

    res = primeFactors(136117223861LL);
    for (vi::iterator i = res.begin(); i != res.end(); i++) printf("# %d\n", *i);

    res = primeFactors(142391208960LL);
    for (vi::iterator i = res.begin(); i != res.end(); i++) printf("! %d\n", *i);

    printf("numPF(%d) = %lld\n", 50, numPF(50));
    printf("numDiffPF(%d) = %lld\n", 50, numDiffPF(50));
    printf("sumPF(%d) = %lld\n", 50, sumPF(50));
    printf("numDiv(%d) = %lld\n", 50, numDiv(50));
    printf("sumDiv(%d) = %lld\n", 50, sumDiv(50));
    printf("EulerPhi(%d) = %lld\n", 50, EulerPhi(50));

    return 0;
}
