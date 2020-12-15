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
int n;
Lint mod;
const int N=2*1e6+10;
struct Segment_Tree{
	#define ls rt<<1
	#define rs rt<<1|1
	#define lson l,mid,ls
	#define rson mid+1,r,rs
	long long lazy[N<<2],sum[N<<2],v[N];
	void PushUp(int rt){sum[rt]=sum[ls]+sum[rs];}
	void PushDown(int l,int r,int rt){
		if(!lazy[rt])return;
		(lazy[ls]+=lazy[rt])%=mod;
		(lazy[rs]+=lazy[rt])%=mod;
		int mid=(l+r)>>1;
		(sum[ls]+=lazy[rt]*(mid-l+1)%mod)%=mod;
		(sum[rs]+=lazy[rt]*(r-mid)%mod)%=mod;
		lazy[rt]=0;
	}
	void build(int l,int r,int rt){
		if(l==r){
			if(l==r){sum[rt]=v[l]%mod;return;}
			return;
		}
		int mid=(l+r)>>1;
		build(lson);build(rson);
		PushUp(rt);
	}
	void update(int L,int R,long long c,int l,int r,int rt){
		if(L<=l&&r<=R){
			(lazy[rt]+=c)%=mod;
			(sum[rt]+=c*(r-l+1))%=mod;
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
		if(L<=mid)(ret+=query(L,R,lson))%=mod;
		if(R>mid)(ret+=query(L,R,rson))%=mod;
		return ret;
	}
}Seg;
struct Tree_Chain_Dissection{
	vector<int> P[N];
	void add(int a,int b){
		P[a].push_back(b);
		P[b].push_back(a);
	}
	
	int idx[N];
	Lint w[N];
	int deep[N],fa[N],son[N],num[N];
	int cnt,top[N];
	int dfs1(int u,int f,int dep){
	  	deep[u]=dep;fa[u]=f;num[u]=1;
	  	int maxson=-1;
	  	for(auto v:P[u])
	  	if(v!=f){
	    	num[u]+=dfs1(v,u,dep+1);
	    	if(num[v]>maxson) 
	    	maxson=num[v],son[u]=v;
	  	}
	  	return num[u];
	}
	void dfs2(int u,int topf){
	  	idx[u]=++cnt;
	  	Seg.v[cnt]=w[u];
	  	top[u]=topf;
	  	if(!son[u])return;
	  	dfs2(son[u],topf);
	  	for(auto v:P[u])
	  	if(!idx[v])dfs2(v,v);
	}
	void Init(int rt){
	 	dfs1(rt,0,1);
		dfs2(rt,rt);
	  	Seg.build(1,n,1);
	}
	Lint Query_Chain(int x,int y){
	  	Lint ans=0;
	  	while(top[x]!=top[y]){
	    	if(deep[top[x]]<deep[top[y]])swap(x,y);
	    	(ans+=Seg.query(idx[top[x]],idx[x],1,n,1))%=mod;
	    	x=fa[top[x]];
	  	}
	  	if(deep[x]>deep[y])swap(x,y);
	  	(ans+=Seg.query(idx[x],idx[y],1,n,1))%=mod;
	  	return ans;
	}
	void Update_Chain(int x,int y,Lint val){
	  	while(top[x]!=top[y]){
	    	if(deep[top[x]]<deep[top[y]]) swap(x,y);
	    	Seg.update(idx[top[x]],idx[x],val,1,n,1);
	    	x=fa[top[x]];
	  	}
	  	if(deep[x]>deep[y]) swap(x,y);
	  	Seg.update(idx[x],idx[y],val,1,n,1);
	}
	Lint Query_Tree(int x){
		return Seg.query(idx[x],idx[x]+num[x]-1,1,n,1);
	}
	void Update_Tree(int x,Lint val){
		Seg.update(idx[x],idx[x]+num[x]-1,val,1,n,1);
	}
}TCD;
int m,rt;
int main(){
	n=read();m=read();rt=read();mod=read();
 	for(int i=1;i<=n;i++)TCD.w[i]=read();
 	for(int i=1;i<n;i++){
	 	int a=read(),b=read();
		TCD.add(a,b);
	}
 	TCD.Init(rt);
 	while(m--){
 		int op,a,b,c;
 		op=read();
 		if(op==1)a=read(),b=read(),c=read(),TCD.Update_Chain(a,b,1ll*c%mod);
    	else if(op==2)a=read(),b=read(),printf("%lld\n",TCD.Query_Chain(a,b));
    	else if(op==3)a=read(),c=read(),TCD.Update_Tree(a,1ll*c%mod);
    	else a=read(),printf("%lld\n",TCD.Query_Tree(a));
  	}
	return 0;
}
