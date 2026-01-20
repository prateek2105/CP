#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std; 


const int N = (int)1e6+10;
 
ll factorialNumInverse[N + 1];
 
ll naturalNumInverse[N + 1];
 
ll fact[N + 1];
 
void InverseofNumber(ll p)
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
void InverseofFactorial(ll p)
{
    factorialNumInverse[0] = factorialNumInverse[1] = 1;
 
   
    for (int i = 2; i <= N; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}
 
void factorial(ll p)
{
    fact[0] = 1;
 
   
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % p;
    }
}
 
ll Binomial(ll N, ll R, ll p)
{
   
    ll ans = ((fact[N] * factorialNumInverse[R])
              % p * factorialNumInverse[N - R])
             % p;
    return ans;
}


signed main() {
    
    fastio();

    int  p = 1000000007; 
    InverseofNumber(p);
    InverseofFactorial(p);
    factorial(p);

    
}
