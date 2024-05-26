#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N=1e7+1;

vector<int> dp(N+1,1);
vector<int> primes;

void sieve(){
    for(int i=2;i<=N;i++){
        if(dp[i]!=1) continue;
        
        for(int j=i;j<=N;j+=i){
            dp[j]=i;
        }
        if(dp[i]==i) primes.push_back(i);
    }
    
}

set<int> prime_factorization(int x){
    set<int> st;
    string val=to_string(x);
    sort(val.begin(), val.end());
    do {
        int temp=stoi(val);
        for(int prime:primes){
            if(prime*prime > temp) break;
            int ct=0;
            while(temp % prime == 0){
                ++ct;
                temp/=prime;
            }
            if(ct>0){
                st.insert(prime);
            }
        }
        if(temp>1){
            st.insert(temp);
        }
    } while(next_permutation(val.begin(), val.end()));
    
    return st;
}

signed main() {
    fastio();
    sieve();
    int tc=1;
    cin>>tc;
    while(tc--){
        int x,y;
        cin>>x>>y;
        
        set<int> st1=prime_factorization(x);
        set<int> st2=prime_factorization(y);
        int ans=1;
        for(int i: st1){
            if(st2.find(i)!=st2.end()){
                ans=max(ans,i);
            }
        }
        cout<<ans<<endl;
    }
}