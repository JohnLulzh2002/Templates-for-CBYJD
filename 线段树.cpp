#include<iostream>
#define ll long long
using namespace std;
ll n,m,tt,x,y,k;
ll a[1000003],t[4000009],lazy[4000009];
int ls(int p){
	return p*2;
}
int rs(int p){
	return p*2+1;
}
void pushup(int p){
	t[p]=t[ls(p)]+t[rs(p)];
}
void build(int l,int r,int p){
	if(l==r) {
		t[p]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,ls(p));
	build(mid+1,r,rs(p));
	pushup(p);
}
void pushdown(int l,int r,int p){
	int mid=(l+r)/2;
	lazy[ls(p)]+=lazy[p];
	lazy[rs(p)]+=lazy[p];
	t[ls(p)]+=lazy[p]*(mid+1-l);
	t[rs(p)]+=lazy[p]*(r-(mid+1)+1);
	lazy[p]=0;
}
void update(int L,int R,int l,int r,int p,ll k){
	if(L<=l&&r<=R) {
		lazy[p]+=k;
		t[p]+=k*(r-l+1);
		return;
	}
	pushdown(l,r,p);
	int mid=(l+r)/2;
	if(L<=mid) update(L,R,l,mid,ls(p),k);
	if(R>mid) update(L,R,mid+1,r,rs(p),k);
	pushup(p); 
}
ll query(int L,int R,int l,int r,int p){
	ll res=0;
	if(L<=l&&r<=R) return t[p];
    int mid=(l+r)/2;
    pushdown(l,r,p);
    if(L<=mid) res+=query(L,R,l,mid,ls(p));
    if(R>mid) res+=query(L,R,mid+1,r,rs(p));
    return res;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	build(1,n,1);
//	for(int i=1;i<=4*n;i++) cout<<t[i]<<" ";
//	cout<<endl;
	for(int i=1;i<=m;i++) {
		cin>>tt;
		if(tt==1) {
			cin>>x>>y>>k;
			update(x,y,1,n,1,k);
		} 
		else{
			cin>>x>>y;
			cout<<query(x,y,1,n,1)<<endl;
		}
	}
}
