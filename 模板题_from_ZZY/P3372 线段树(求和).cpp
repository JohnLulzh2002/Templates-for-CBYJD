#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
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
const int N=100010;
struct Segment_Tree{
	#define ls rt<<1
	#define rs rt<<1|1
	#define lson l,mid,ls
	#define rson mid+1,r,rs
	long long lazy[N<<2],sum[N<<2];
	void PushUp(int rt){sum[rt]=sum[ls]+sum[rs];}
	void PushDown(int l,int r,int rt){
		if(!lazy[rt])return;
		lazy[ls]+=lazy[rt];
		lazy[rs]+=lazy[rt];
		int mid=(l+r)>>1;
		sum[ls]+=lazy[rt]*(mid-l+1);
		sum[rs]+=lazy[rt]*(r-mid);
		lazy[rt]=0;
	}
	void build(int l,int r,int rt){
		if(l==r){
			scanf("%lld",&sum[rt]);
			return;
		}
		int mid=(l+r)>>1;
		build(lson);build(rson);
		PushUp(rt);
	}
	void update(int L,int R,long long c,int l,int r,int rt){
		if(L<=l&&r<=R){
			lazy[rt]+=c;
			sum[rt]+=c*(r-l+1);
			return;
		}
		PushDown(l,r,rt);
		int mid=(l+r)>>1;
		if(L<=mid)update(L,R,c,lson);
		if(R>mid)update(L,R,c,rson);
		PushUp(rt);
	}
	long long query(int L,int R,int l,int r,int rt){
		if(L<=l&&r<=R)return sum[rt];
		PushDown(l,r,rt);
		int mid=(l+r)>>1;
		long long ret=0ll;
		if(L<=mid)ret+=query(L,R,lson);
		if(R>mid)ret+=query(L,R,rson);
		return ret;
	}
}Seg;
int n,m,l,r;
long long op,c;
int main(){
 	n=read();m=read();
 	Seg.build(1,n,1);
 	for(int i=1;i<=m;i++){
 		op=read();l=read();r=read();
 		if(op==1)scanf("%lld",&c),Seg.update(l,r,c,1,n,1);
 		else printf("%lld\n",Seg.query(l,r,1,n,1));
	}
	return 0;
}