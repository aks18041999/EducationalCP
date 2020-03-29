//LCA in logn nlogn
//TOPCODER TUTORIAL

#include <bits/stdc++.h>
using namespace std;
#define  ll long long int

const ll MAXN = 200005;
ll par[MAXN] , lev[MAXN] , P[MAXN][32];
vector<ll> v[MAXN];
ll dfs(ll root, ll parent){
    for(ll i=0;i<v[root].size();i++){
        if(v[root][i]!=parent){
            lev[v[root][i]] = lev[root]+1;
            par[v[root][i]] = root;
            dfs(v[root][i],root);
        }
    }
    return 0;
}
//comput the tabl
void traverse(ll n){
    for(ll i=1;i<=n;i++){
        for(ll j=0;1<<j<=n;j++)P[i][j]=-1;
    }
    for(ll i=1;i<=n;i++)P[i][0]=par[i];
    for(ll j=1;1<<j<=n;j++){
        for(ll i=1;i<=n;i++)
        if(P[i][j-1]!=-1)
            P[i][j] = P[P[i][j-1]][j-1];
    }
}
ll LCA(ll x, ll  y){
    if(lev[x]<lev[y])
        swap(x,y);
    ll jump;
    for(jump = 1;1<<jump<=lev[x];jump++);
    jump--;
    
    for(ll i=jump;i>=0;i--){
        if(lev[x]-(1<<i)>=lev[y])
            x = P[x][i];
    }
    if(x==y)return x;
    for(ll i=jump;i>=0;i--){
        if(P[x][i]!=-1&&P[x][i]!=P[y][i])
        x = P[x][i],y = P[y][i];
    }
    return par[x];
}
main(){
   		dfs(1,0);
        traverse(n);
      	LCA(x,y);
}
