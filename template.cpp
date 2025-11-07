int binpow(int x,int n) {
    x%=M;
    if(n==0) return 1; 
    else if(n==1) return x; 
    int p = binpow(x*x, n/2);if(n%2) return p*x%M; else return p;}
ll gcd(ll a, ll b){
    if(b == 0) return a; 
    return gcd(b, a%b);
}
ll lcm(ll a, ll b){
    return a*b/gcd(a,b);
}
vi factors(ll n){ vi fac; for (ll i = 1; i * i <= n; i++){ if (n % i == 0){ fac.pb(i); if (i * i != n)fac.pb(n / i); } } return fac; }

int mod_div(int p, int q){ 
    return p%M * binpow(q,M-2) % M;
}

vi fact, ifact;
void factCompute(int N=1e6) {
    fact.assign(N+1, 1);
    ifact.assign(N+1, 1);
    fr(i,1,N+1){ 
        fact[i] = fact[i-1] * i % M;
    }
    ifact[N] = mod_div(1, fact[N]); 
    forrr(i,N-1,0) {
        ifact[i] = ifact[i+1] * (i+1) % M; 
    }
}

int ncr(int n, int r) {
    if(r > n) return 0; 
    return fact[n] * ifact[n-r] % M * ifact[r] % M;
}

vi spf, primes;
void sieve(int N=1e7){
    spf.assign(N+1,0); 
    fr(i,0,N+1) spf[i]=i;
    for(int i=2; i*i<=N; i++) {
        if(spf[i]==i){ 
            for(int j=i*i; j<=N; j+=i){ 
                spf[j]=min(spf[j],i);
            }
        }
    }
    fr(i,2,N+1){ 
        if(spf[i]==i) primes.pb(i);
    }
}
