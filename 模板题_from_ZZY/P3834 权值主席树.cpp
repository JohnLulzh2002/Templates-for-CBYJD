#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<cmath>
#define Lint long long
using namespace std;
const int inf=0x7fffffff;
const double eps=1e-10;
const double pi=acos(-1.0);
inline int read(){
	int x=0,f=1;char ch;ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N=2e5+10;;
int root[N];
struct Chairman_Tree{
	#define lson l,mid,ls[rt]
	#define rson mid+1,r,rs[rt]
	Lint Sum[N<<5];
	int ls[N<<5],rs[N<<5];
	int size=0;
	int newnode(int p){
		int rt=++size;
		Sum[rt]=Sum[p];
		ls[rt]=ls[p];
		rs[rt]=rs[p];
		return rt;
	}
	void PushUp(int rt){Sum[rt]=Sum[ls[rt]]+Sum[rs[rt]];}
	int build(int l,int r){
		int rt=newnode(0);
		if(l==r)return rt;
		int mid=l+r>>1;
		ls[rt]=build(l,mid);
		rs[rt]=build(mid+1,r);
		PushUp(rt);
		return rt;
	}
	int update(int id,int l,int r,int p){
		int rt=newnode(p);
		if(l==r){Sum[rt]++;return rt;}
		int mid=l+r>>1;
		if(id<=mid)ls[rt]=update(id,lson);
		else rs[rt]=update(id,rson);
		PushUp(rt);
		return rt;
	}
	int query(int k,int l,int r,int rt,int rt_){
		if(l>=r)return l;
		int x=Sum[ls[rt_]]-Sum[ls[rt]];
		int mid=l+r>>1;
		if(x>=k)return query(k,lson,ls[rt_]);
		return query(k-x,rson,rs[rt_]);
	}
}CHT;
int n,q,m; 
int data[N],a[N];
int lisan(int *x){
	for(int i=1;i<=n;i++)
	data[i]=x[i];
	sort(data+1,data+1+n);
	int len=unique(data+1,data+1+n)-data-1;
	for(int i=1;i<=n;i++)
	x[i]=lower_bound(data+1,data+1+len,x[i])-data;
	return len;
}
int main(){
	n=read();q=read();
	for(int i=1;i<=n;i++)a[i]=read();
	m=lisan(a);
	root[0]=CHT.build(1,m);
	for(int i=1;i<=n;i++)
    root[i]=CHT.update(a[i],1,m,root[i-1]);
	for(int i=1;i<=q;i++){
		int x=read(),y=read(),z=read();
		int t=CHT.query(z,1,m,root[x-1],root[y]);
		printf("%d\n",data[t]);
	}
	return 0;
}

