//BITMASK 
//EDITORIAL  - https://codeforces.com/blog/entry/74235

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

main(){
    ll u,v;
    cin>>u>>v;
    if(u>v||u%2!=v%2){
    	cout<<-1;
    	return 0;
    }
    if(u==0){
    	if(v==0){
    		cout<<"0\n";
    		return 0;
    	}
    }
    if(u==v){
    	cout<<1<<endl<<u;
    	return 0;
    }
    ll x = (v-u)/2;
    if(x&u){
    	cout<<3<<"\n"<<u<<" "<<x<<" "<<x;
    	return 0;
    }
    else {

    	cout<<2<<"\n"<<u+x<<" "<<x;
    	return 0;
    }

}
