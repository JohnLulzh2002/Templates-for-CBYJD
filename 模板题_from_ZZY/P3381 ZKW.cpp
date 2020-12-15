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
const int N=5e3+10;
const int M=200010;
int n,m,S,T;
struct Graph{
	int p;
	struct Edge{
		int v;Lint w,val;
	};
	vector<Edge> E;
	vector<int> P[N];
	void add(int a,int b,Lint c,Lint d){
		E.push_back((Edge){b,c,d});
		P[a].push_back(p++);
	}
	Lint dis[N];
	bool dijkstra(int S,int T){
		for(int i=0;i<=n;i++)dis[i]=inf;
		dis[S]=0;
		priority_queue< pair<Lint,int> > Q;
	  	Q.push(make_pair(0,S));
	  	while(!Q.empty()){
		    int u=Q.top().second;Q.pop();
		    for(auto v:P[u])
			if(E[v^1].w&&dis[E[v].v]>dis[u]-E[v].val){
				dis[E[v].v]=dis[u]-E[v].val;
				Q.push(make_pair(-dis[E[v].v],E[v].v));
			}
		}
		return dis[T]<inf;
	}
	bool vis[N];
	Lint Augment(int u,int T,Lint &Mincost,Lint mi_flow){
		vis[u]=1;
		if(u==T)return mi_flow;
		Lint flow=0;vis[u]=1;
		for(auto v:P[u])
		if(!vis[E[v].v]&&E[v].w&&dis[E[v].v]==dis[u]-E[v].val){
			Lint f=Augment(E[v].v,T,Mincost,min(mi_flow,E[v].w));
			flow+=f;mi_flow-=f;E[v].w-=f;E[v^1].w+=f;
			Mincost+=f*E[v].val;
			if(!mi_flow)return flow;
		}
		return flow;
	}
	void ZKW(int S,int T,Lint &Maxflow,Lint &Mincost){
		Maxflow=Mincost=0;
		while(dijkstra(T,S)){
			vis[T]=1;
			while(vis[T])
		    memset(vis,0,(n+1)*sizeof(bool)),
			Maxflow+=Augment(S,T,Mincost,inf);
		}
	}
}G;
Lint Maxflow,Mincost;
int main(){
	n=read();m=read();S=read(),T=read();
	while(m--){
		int a=read(),b=read(),c=read(),d=read();
		G.add(a,b,1ll*c,d);
		G.add(b,a,0ll,-d);
	}
	G.ZKW(S,T,Maxflow,Mincost);
	printf("%lld %lld\n",Maxflow,Mincost);
	return 0;
}

