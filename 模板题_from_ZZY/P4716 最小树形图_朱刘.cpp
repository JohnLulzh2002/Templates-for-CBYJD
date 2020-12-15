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
const int N=110;
const int M=10010;
int n; 
struct Graph{
	struct Edge{
		int u,v;Lint w;
	}E[M];
	int cnt;
	void add_edge(int a,int b,Lint w){
		E[++cnt]=(Edge){a,b,w};
	}
	int k[N],idx[N],tim;
	int cost[N],fa[N],rt[N];
	Lint mincost[N];
	Lint Zhu_Liu(int n,int root){
		Lint ans=0;
		while(1){
			memset(mincost,127,sizeof(mincost));
			memset(idx,-1,sizeof(idx));
			memset(rt,0,sizeof(rt));
			for(int i=1;i<=cnt;i++)
			if(E[i].w<mincost[E[i].v]&&E[i].u!=E[i].v){
				mincost[E[i].v]=E[i].w;
				fa[E[i].v]=E[i].u;
			}
			mincost[root]=0;tim=0;
			for(int i=1;i<=n;i++){
				if(mincost[i]==mincost[0])return -1;
				ans+=mincost[i];
				int u=i;
				while(rt[u]!=i&&u!=root)
					rt[u]=i,u=fa[u];
				if(u!=root&&idx[u]==-1){
					tim++;
					for(int j=fa[u];j!=u;j=fa[j])
					idx[j]=tim;
					idx[u]=tim;
				}
			}
			if(tim==0)break;
			for(int i=1;i<=n;i++)
			if(idx[i]==-1)idx[i]=++tim;
			for(int i=1;i<=cnt;i++){
				int v=E[i].v;
				E[i].u=idx[E[i].u];
				E[i].v=idx[E[i].v];
				if(E[i].u!=E[i].v)E[i].w-=mincost[v];
			}
			n=tim;root=idx[root];
		}
		return ans;
	}
}G;
int m,root;
int main(){
	n=read();m=read();root=read();
	while(m--){
		int a=read(),b=read(),c=read();
		G.add_edge(a,b,1ll*c);
	}
	printf("%lld\n",G.Zhu_Liu(n,root));
	return 0;
}
