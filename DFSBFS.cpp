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

const ll SIZE = 100005;
vector<ll> v[SIZE];
bool visited[SIZE];
ll dfs(ll root){

	if(visited[root])return 0;
	visited[root]=1;
	cout<<root<<"\n";
	for(auto i:v[root]){
		if(!visited[i]){
			dfs(i);
		}
	}
}
ll bfs(ll root){
	queue<ll> q;
	q.push(root);
	visited[root]=1;
	while(!q.empty()){
		ll x = q.top();
		q.pop();
		for(auto i:v[x]){
			if(!visited[i]){
				q.push(i);
				visited[i]=1;
			}
		}
	}
}

main(){
  //make graph
}
