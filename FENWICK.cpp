//FENWICK TREE IMPLEMENTATION
//REFERENCE TOPCODER
#include <bits/stdc++.h>
using namespace std;
#define  ll long long int

const ll MAXN = 100005;
ll c[MAXN],bt[MAXN],a[MAXN];
ll n;
//2D bit same as this only have x and y

//USE IF YOU NEED TO MAKE A TREE //NOT USED IN INVERSION COUNT
void make_tree(){
    for(ll i=1;i<=n;i++){
        c[i] = c[i-1]+a[i];
    }
    for(ll i=1;i<=n;i++){
        ll x = (i&(-i));
        ll r = i-x+1;
        bt[i] = c[i]-c[r-1];
    }
}
ll read(ll x){
    ll sum = 0;
    for(;x>0;x-=(x&(-x)))
        sum+=bt[x];
    return sum;
}
void update(ll x,ll val){
    //a[x] = val; //USE IF YOU UPDATE A[i]
    for(;x<=n;x+=(x&-(x)))
        bt[x]+=val;
}
//noy used fi you have a[i] array
ll readsingle(ll x){
    ll sum = bt[x];
    if(x>0){
        ll z = x-(x&(-x));
        x--;
        while(x!=z){
            sum-=bt[x];
            x -= (x&(-x));
        }
    }
    return sum;
}
/*
make_tree();
    cout<<read(10)-read(7);
    update(5,4);
    cout<<read(8)-read(4);
*/
main(){
}
