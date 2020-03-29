#include <bits/stdc++.h>
using namespace std;
#define  ll long long int
#define inf std::numeric_limits<double>::infinity()
#define DECI(n) fixed<<showpoint<<setprecision(n)
#define MOD 1000000007LL
#define FOR(i,start,end) for(int i=start;i<end;i++)
#define FORR(i,end,start) for(int i=end-1;i>=start;i--)
#define INPUT(arr,n) FOR(i,0,n)cin>>arr[i];
#define INPUT2d(arr,n,k) FOR(i,0,n)FOR(j,0,k)cin>>arr[i][j];
#define SIZE 100005
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define pb(n) push_back(n)
#define fi first
#define si second

const ll MAXN = 200005;
ll lev[MAXN],h[MAXN],tree[4*MAXN];
vector<ll> v[MAXN];
vector<ll> euler;
vector<ll> L;
ll dfs(ll root, ll parent){
    euler.push_back(root);
    for(ll i=0;i<v[root].size();i++){
        if(v[root][i]!=parent){
            lev[v[root][i]] = lev[root]+1;
            dfs(v[root][i],root);
            euler.push_back(root);
        }
    }
    return 0;
}
void build(ll tree[],ll node,ll start,ll end) {
	
    if(start==end){
    	tree[node] = euler[start];
    }
    else{
    	int mid = (start+end)/2;
    	build(tree,2*node,start,mid);
    	build(tree,2*node+1,mid+1,end);
    	if(lev[tree[2*node]]<lev[tree[2*node+1]])
    	tree[node] = tree[2*node];
    	else
    	tree[node] = tree[2*node+1];
    	
    }
}

ll query(ll tree[], ll node,ll start, ll end, ll l, ll r){
	//cout<<start<<" "<<end<<endl;
	if(r<start||end<l){
		return 0;
	}
	if(l<=start&&end<=r){
		return tree[node];
	}
	ll mid = (start+end)/2;
	ll p1 = query(tree,2*node,start,mid,l,r);
	ll p2 = query(tree,2*node+1,mid+1,end,l,r);
	return (lev[p1]>lev[p2])?p2:p1; 
}
ll process(){
	euler.push_back(0);
	dfs(1,0);
	memset(h,-1,sizeof(h));
	for(ll i=1;i<euler.size();i++){
		if(h[euler[i]]==-1){
			h[euler[i]]=i;
		}
	}
	lev[0] = INT_MAX;
	build(tree,1,1,euler.size()-1);
	return 0;
}
ll LCA(ll x,ll y){
	ll l = min(h[x],h[y]);
	ll r = max(h[x],h[y]);
	return query(tree,1,1,euler.size()-1,l,r);

}

main(){
	ll n;
        cin>>n;
        for(ll i=1;i<=n;i++){
            ll x;
            cin>>x;
            while(x--){
                ll y;
                cin>>y;
                v[i].push_back(y+1);
                v[y+1].push_back(i);
            }
        }
        process();
        ll q;
        cin>>q;
         while(q--){
            ll x,y;
            cin>>x>>y;
            cout<<LCA(x+1,y+1)-1<<"\n";
        }
}
