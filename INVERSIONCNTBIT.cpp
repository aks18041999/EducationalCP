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
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define pb(n) push_back(n)
#define fi first
#define si second

const ll MAXN = 100005;
ll c[MAXN],bt[MAXN],a[MAXN];
ll n;
//2D bit same as this only have x and y

ll read(ll x){
    ll sum = 0;
    for(;x>0;x-=(x&(-x)))
        sum+=bt[x];
    return sum;
}
void update(ll x,ll val){
    //a[x] = val;
    for(;x<=n;x+=(x&-(x)))
        bt[x]+=val;
}
main(){
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];
    map<ll,ll>  mp;
    ll temp[n+1];
    for(ll i=1;i<=n;i++)temp[i] = a[i];
    sort(temp+1,temp+n+1);
    for(ll i=1;i<=n;i++){
        mp[temp[i]] = i;
    }
    ll sum = 0;
    for(ll i=n;i>=1;i--){
        sum+=read(mp[a[i]]-1);
        update(mp[a[i]],1);
    }
    cout<<sum<<"\n";
}
