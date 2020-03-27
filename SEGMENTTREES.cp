#include <bits/stdc++.h>
using namespace std;
#define  ll long long int


const ll MAXN=200000;
ll n, tree[4*MAXN],lazy[4*MAXN],clazy[4*MAXN];
ll a[MAXN];
//sum query
void build(ll a[],ll tree[],ll node,ll start,ll end) {
    if(start==end){
    	tree[node] = a[start];
    }
    else{
    	int mid = (start+end)/2;
    	build(a,tree,2*node,start,mid);
    	build(a,tree,2*node+1,mid+1,end);
    	tree[node] = tree[2*node] + tree[2*node+1];
    }
}

ll query(ll a[],ll tree[], ll node,ll start, ll end, ll l, ll r){
	if(r<start ||end<l){
		return 0;
	}
	if(l<=start&&end<=r){
		return tree[node];
	}
	ll mid = (start+end)/2;
	ll p1 = query(a,tree,2*node,start,mid,l,r);
	ll p2 = query(a,tree,2*node+1,mid+1,end,l,r);
	return (p1+p2); 
}
void updateRange(ll a[],ll tree[], ll node,ll start, ll end, ll l, ll r,ll val){
	if(clazy[node]!=0){
		tree[node]+=(end-start+1)*lazy[node]; //sum updated
		if(start!=end){
			lazy[node*2]+=lazy[node];
			clazy[node*2] = 1;
			lazy[node*2+1]+=lazy[node];
			clazy[node*2+1] = 1;
		}
		clazy[node]=0;
		lazy[node]=0;
	}
	if(start>end||start>r||end<l)
		return;
	if(start>=l&&end<=r){
		tree[node]+=(end-start+1)*val;
		if(start!=end){
			clazy[node*2]=1;
			clazy[node*2+1]=1;
			lazy[node*2]+=val;
			lazy[node*2+1]+=val;
		}
		return;
	}
	int mid = (start+end)/2;
	updateRange(a,tree,node*2,start,mid,l,r,val);
	updateRange(a,tree,node*2,mid+1,end,l,r,val);
	tree[node] = tree[node*2]+tree[node*2+1];
}
main(){
	ll n = 5;
    build(a,tree,1,1,n);
    cout<<1<<endl;
    updateRange(a,tree,1,1,n,1,3,5);
    cout<<query(a,tree,1,1,n,1,4);

    cout<<query(a,tree,1,1,n,4,4);
}
