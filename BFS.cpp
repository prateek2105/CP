#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int bfs(int start, int n,vector<int> &dist,vector<int> g[],vector<int> &parent) {
    
    queue<int> q;
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        
        int node = q.front();
        q.pop();
        
        for (int i=0;i<g[node].size();i++) {
            int neighbor=g[node][i];
            if (dist[neighbor] == INT_MAX) {
                parent[neighbor]=node;
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }
    
    int ans=0,ma=0;
    for(int i=1;i<=n;i++){
        if(dist[i]>ma){
            ma=dist[i];
            ans=i;
        }
    }
    return ans;
    
}


signed main() {
    fastio();
    
    int tc=1;
    cin>>tc;
    while(tc--){
        int n;cin>>n;
        vector<int> g[n+1];
        for(int i=1;i<=n-1;i++){
            int x,y;cin>>x>>y;
            g[y].push_back(x);
            g[x].push_back(y);
        }
        vector<int> dist(n+1, INT_MAX);
        vector<int> parent(n+1,-1);
        int val1=bfs(1,n,dist,g,parent);
        vector<int> dist1(n+1, INT_MAX);
        vector<int> parent1(n+1,-1);
        int val2=bfs(val1,n,dist1,g,parent1);
        int total=dist1[val2]+1;
        vector<char> ans(n+1,'0');
        int ct=1;
        int temp=val2;
        int r=0,b=0;
        while(temp!=-1){
            if(ct<=total/2){
                ans[temp]='R';
                r++;
            }else{
                ans[temp]='B';
                b++;
            }
            ct++;
            temp=parent1[temp];
            
        }
        for(int i=1;i<=n;i++){
            if(ans[i]=='0'){
                if(r<=b){
                    ans[i]='R';
                    r++;
                }else{
                    ans[i]='B';
                    b++;
                }
            }
        }
        for(int i=1;i<=n;i++){
            cout<<ans[i];
        }
        cout<<endl;
    }
}
