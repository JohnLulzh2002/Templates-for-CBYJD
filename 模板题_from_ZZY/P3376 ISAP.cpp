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
const int N=10100;
const int M=10100;
int n,m,S,T;
struct Graph{
	int p;
	struct Edge{
		int v;Lint w;
	};
	vector<Edge> E;
	vector<int> P[N],cur[N];
	void add(int a,int b,Lint c){
		E.push_back((Edge){b,c});
		P[a].push_back(p++);
	}
	
	int dis[N],num[N];
	void bfs(int T){
		memset(dis,0,(n+1)*sizeof(int));
		memset(num,0,(n+1)*sizeof(int));
		for(int i=1;i<=n;i++)cur[i]=P[i];
		++num[++dis[T]];
		queue<int> Q;Q.push(T);
		while(!Q.empty()){
			int u=Q.front();Q.pop();
		    for(auto v:P[u])
			if(!dis[E[v].v]){
				++num[dis[E[v].v]=dis[u]+1];
				Q.push(E[v].v);
			}
		}
	}
	Lint Augment(int u,int S,int T,Lint mi_flow){
		if(u==T)return mi_flow;
		Lint flow=0;
		for(auto v:cur[u])
		if(E[v].w&&dis[E[v].v]==dis[u]-1){
			Lint f=Augment(E[v].v,S,T,min(mi_flow,E[v].w));
			flow+=f;mi_flow-=f;E[v].w-=f;E[v^1].w+=f;
			if(!mi_flow)return flow;
		}
		if(!(--num[dis[u]]))dis[S]=n+1;
		++num[++dis[u]];cur[u]=P[u];
		return flow;
	}
	Lint ISAP(int S,int T){
		bfs(T);
		Lint ret=Augment(S,S,T,inf);
		while(dis[S]<=n) ret+=Augment(S,S,T,inf);
		return ret;
	}
}G;
int main(){
	n=read();m=read();S=read(),T=read();
	while(m--){
		int a=read(),b=read(),c=read();
		G.add(a,b,1ll*c);
		G.add(b,a,0ll);
	}
	printf("%lld\n",G.ISAP(S,T));
	return 0;
}

