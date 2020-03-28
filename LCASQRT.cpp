//REFERENCE  : https://www.topcoder.com/community/competitive-programming/tutorials/range-minimum-query-and-lowest-common-ancestor/
//RUN FOR IT
#include <bits/stdc++.h>
using namespace std;
#define  ll long long int

const ll MAXN = 100005;
ll par[MAXN] , lev[MAXN] , P[MAXN];
vector<ll> v[MAXN];
ll bsize,maxh;
bool visited[MAXN];
ll dfs(ll root, ll parent){
    maxh = max(lev[root],maxh);
    cout<<root<<" "<<lev[root]<<endl;
    for(ll i=0;i<v[root].size();i++){
        if(v[root][i]!=parent){
            lev[v[root][i]] = lev[root]+1;
            par[v[root][i]] = root;
            dfs(v[root][i],root);
        }
    }
}
void traverse(ll node){
    if(lev[node]<bsize)
        P[node]=1;
    else 
        if(!(lev[node]%bsize))
            P[node] = par[node];
        else P[node] = P[par[node]];

    for(ll i=0;i<v[node].size();i++){
        if(v[node][i]!=par[node]){
            traverse(v[node][i]);
        }
    }
}
ll LCA(ll x, ll  y){
    while(P[x]!=P[y]){
        if(lev[x]>lev[y])
            x = P[x];
        else 
            y=P[y];
    }
    while(x!=y){
        if(lev[x]>lev[y])
            x  = par[x];
        else y = par[y];

    }
    return x;
}
main(){
    for(ll i=0;i<10;i++){
        ll x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0);
    bsize = sqrt(maxh);
    traverse(1);    
    //cout<<LCA(7,6);
    //cout<<LCA(11,8);
    //cout<<LCA(5,5);
}
