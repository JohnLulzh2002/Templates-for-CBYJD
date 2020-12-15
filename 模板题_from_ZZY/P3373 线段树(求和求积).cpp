#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<queue>
#include<cmath>
#define Lint long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch;ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N=100010;
int n,m,Mod;
struct Segment_Tree{
	#define ls rt<<1
	#define rs rt<<1|1
	#define lson l,mid,ls
	#define rson mid+1,r,rs
	Lint add[N<<2],sum[N<<2],mul[N<<2];
	void PushUp(int rt){
		sum[rt]=(sum[ls]+sum[rs])%Mod;
	}
	void PushDown(int rt,int m){
		if(mul[rt]!=1){
			(mul[ls]*=mul[rt])%=Mod;
			(mul[rs]*=mul[rt])%=Mod;
			(add[ls]*=mul[rt])%=Mod;
			(add[rs]*=mul[rt])%=Mod;
			(sum[ls]*=mul[rt])%=Mod;
			(sum[rs]*=mul[rt])%=Mod;
			mul[rt]=1;
		}
		if(add[rt]){
			(add[ls]+=add[rt])%=Mod;
			(add[rs]+=add[rt])%=Mod;
			(sum[ls]+=(m-(m>>1))*(add[rt]))%=Mod;
			(sum[rs]+=(m>>1)*add[rt])%=Mod;
			add[rt]=0;
		}
	}
	void build(int l,int r,int rt){
		add[rt]=0;mul[rt]=1;
		if(l==r){sum[rt]=read();mul[rt]=1;;return;}
		int mid=(l+r)>>1;
		build(lson);build(rson);
		PushUp(rt);
	}
	void update_mul(int L,int R,int c,int l,int r,int rt){
		if(L<=l&&r<=R){
			(add[rt]*=c)%=Mod;
			(mul[rt]*=c)%=Mod;
			(sum[rt]*=c)%=Mod;
			return;
		}
		PushDown(rt,r-l+1);
		int mid=(l+r)>>1;
		if(L<=mid)update_mul(L,R,c,lson);
		if(R>mid)update_mul(L,R,c,rson);
		PushUp(rt);
	}
	void update_add(int L,int R,int c,int l,int r,int rt){
		if(L<=l&&r<=R){
			add[rt]+=c;sum[rt]+=c*(r-l+1);
			return;
		}
		PushDown(rt,r-l+1);
		int mid=(l+r)>>1;
		if(L<=mid)update_add(L,R,c,lson);
		if(R>mid)update_add(L,R,c,rson);
		PushUp(rt);
	}
	Lint query(int L,int R,int l,int r,int rt){
		if(L>r||R<l)return 0;
		if(L<=l&&r<=R)return sum[rt];
		PushDown(rt,r-l+1);
		int mid=(l+r)>>1;
		return (query(L,R,lson)+query(L,R,rson))%Mod;
	}
}Seg;
int main(){
	n=read();m=read();Mod=read();
 	Seg.build(1,n,1);
 	while(m--){
 		int op=read(),a=read(),b=read();
 		if(op==1)Seg.update_mul(a,b,read(),1,n,1);
		else if(op==2)Seg.update_add(a,b,read(),1,n,1);
		else printf("%lld\n",Seg.query(a,b,1,n,1));
	}
	return 0;
}