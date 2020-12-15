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
const Lint inf=(1ll<<60);
inline int read(){
	int x=0,f=1;char ch;ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N=5e5+10;
int n,m;
struct Segment_Tree{
	#define ls rt<<1
	#define rs rt<<1|1
	#define lson l,mid,ls
	#define rson mid+1,r,rs
	Lint Max[N<<2],B[N<<2],Sec[N<<2],cnt[N<<2],Sum[N<<2];
	Lint lazy1[N<<2],lazy2[N<<2],lazy3[N<<2],lazy4[N<<2];
	void PushUp(int rt){
		Sum[rt]=Sum[ls]+Sum[rs];
		B[rt]=max(B[ls],B[rs]);
		if(Max[ls]>Max[rs]){
			Max[rt]=Max[ls];
			Sec[rt]=max(Max[rs],Sec[ls]);
			cnt[rt]=cnt[ls];
			return;
		}
		else if(Max[ls]<Max[rs]){
			Max[rt]=Max[rs];
			Sec[rt]=max(Max[ls],Sec[rs]);
			cnt[rt]=cnt[rs];
			return;
		}
		else {
			Max[rt]=Max[ls];
			Sec[rt]=max(Sec[ls],Sec[rs]);
			cnt[rt]=cnt[ls]+cnt[rs];
			return;
		}
	}
	void update(int rt,Lint m,Lint k1,Lint k3,Lint k2,Lint k4){
		Sum[rt]+=k1*cnt[rt]+k2*(m-cnt[rt]);
		B[rt]=max(B[rt],Max[rt]+k3);
		Max[rt]+=k1;
		lazy3[rt]=max(lazy3[rt],lazy1[rt]+k3);lazy1[rt]+=k1;
		lazy4[rt]=max(lazy4[rt],lazy2[rt]+k4);lazy2[rt]+=k2;
		if(Sec[rt]!=-inf) Sec[rt]+=k2;
	}
	void PushDown(int rt,int m){
		Lint tmp=max(Max[ls],Max[rs]);
		if(Max[ls]==tmp)
			update(ls,1ll*(m-(m>>1)),lazy1[rt],lazy3[rt],lazy2[rt],lazy4[rt]);
		else
			update(ls,1ll*(m-(m>>1)),lazy2[rt],lazy4[rt],lazy2[rt],lazy4[rt]);
		if(Max[rs]==tmp)
			update(rs,1ll*(m>>1),lazy1[rt],lazy3[rt],lazy2[rt],lazy4[rt]);
		else
			update(rs,1ll*(m>>1),lazy2[rt],lazy4[rt],lazy2[rt],lazy4[rt]);
		lazy1[rt]=lazy3[rt]=lazy2[rt]=lazy4[rt]=0;
	}
	void build(int l,int r,int rt){
		lazy1[rt]=lazy3[rt]=lazy2[rt]=lazy4[rt]=0;
		if(l==r){
			Max[rt]=B[rt]=Sum[rt]=1ll*read();
			Sec[rt]=-inf;
			cnt[rt]=1;
			return;
		}
		int mid=(l+r)>>1;
		build(lson);build(rson);
		PushUp(rt);
	}
	void update1(int L,int R,Lint c,int l,int r,int rt){
		if(L<=l&&r<=R){
			update(rt,1ll*(r-l+1),c,c,c,c);
			return;
		}
		PushDown(rt,r-l+1);
		int mid=(l+r)>>1;
		if(L<=mid)update1(L,R,c,lson);
		if(R>mid)update1(L,R,c,rson);
		PushUp(rt);
	}
	void update2(int L,int R,Lint c,int l,int r,int rt){
		if(c>=Max[rt])return;
		if(L<=l&&r<=R&&c>Sec[rt]){
			update(rt,1ll*(r-l+1),c-Max[rt],c-Max[rt],0ll,0ll);
			return;
		}
		PushDown(rt,r-l+1);
		int mid=(l+r)>>1;
		if(L<=mid)update2(L,R,c,lson);
		if(R>mid)update2(L,R,c,rson);
		PushUp(rt);
	}
	Lint query3(int L,int R,int l,int r,int rt){
		if(L>r||R<l)return 0;
		if(L<=l&&r<=R)return Sum[rt];
		PushDown(rt,r-l+1);
		int mid=(l+r)>>1;
		return query3(L,R,lson)+query3(L,R,rson);
	}
	Lint query4(int L,int R,int l,int r,int rt){
		if(L>r||R<l)return -inf;
		if(L<=l&&r<=R)return Max[rt];
		PushDown(rt,r-l+1);
		int mid=(l+r)>>1;
		return max(query4(L,R,lson),query4(L,R,rson));
	}
	Lint query5(int L,int R,int l,int r,int rt){
		if(L>r||R<l)return -inf;
		if(L<=l&&r<=R)return B[rt];
		PushDown(rt,r-l+1);
		int mid=(l+r)>>1;
		return max(query5(L,R,lson),query5(L,R,rson));
	}
}Seg;
int main(){
	n=read();m=read();
 	Seg.build(1,n,1);
 	while(m--){
		int op=read(),a,b;
		Lint k;
		switch(op){
			case 1:
				a=read(),b=read(),k=1ll*read();
				Seg.update1(a,b,k,1,n,1);
				break;
			case 2:
				a=read(),b=read(),k=1ll*read();
				Seg.update2(a,b,k,1,n,1);
				break;
			case 3:
				a=read(),b=read();
				printf("%lld\n",Seg.query3(a,b,1,n,1));
				break;
			case 4:
				a=read(),b=read();
				printf("%lld\n",Seg.query4(a,b,1,n,1));
				break;
			case 5:
				a=read(),b=read();
				printf("%lld\n",Seg.query5(a,b,1,n,1));
				break;
		}
	}
	return 0;
}