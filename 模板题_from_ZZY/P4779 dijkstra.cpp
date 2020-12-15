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
const int N=1e5+10;
const int M=2e5+10;
int n,m,S;
struct Graph{
	struct Edge{
		int v;Lint w;
	};
	vector<Edge> P[N];
	void add(int a,int b,Lint c){
		P[a].push_back((Edge){b,c});
	}
	bool used[N];
	Lint dis[N];
	void dijkstra(int S){
		for(int i=1;i<=n;i++)dis[i]=inf;
		dis[S]=0;
		priority_queue< pair<Lint,int> > Q;
	  	Q.push(make_pair(0,S));
	  	while(!Q.empty()){
		    int u=Q.top().second;Q.pop();
	    	if(used[u])continue;used[u]=1;
		    for(auto v:P[u])
			if(!used[v.v]&&dis[v.v]>dis[u]+v.w){
				dis[v.v]=dis[u]+v.w;
				Q.push(make_pair(-dis[v.v],v.v));
			}
		}
	}
}G;
int main(){
	n=read();m=read();S=read();
	while(m--){
		int a=read(),b=read(),c=read();
		G.add(a,b,1ll*c);
	}
	G.dijkstra(S);
	for(int i=1;i<=n;i++)
	printf("%lld ",G.dis[i]);
	printf("\n");
	return 0;
}
