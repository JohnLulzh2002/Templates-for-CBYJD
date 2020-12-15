#include<iostream>
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
const int N=1e4+10;
const int M=5e5+10;

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
	void SPFA(int S){
		for(int i=1;i<=n;i++)dis[i]=(1ll<<31)-1;
		queue<int> Q;
		used[S]=1;dis[S]=0;
		Q.push(S);
	  	while(!Q.empty()){
		    int u=Q.front();Q.pop();used[u]=0;
		    for(auto v:P[u])
			if(dis[v.v]>dis[u]+v.w){
				dis[v.v]=dis[u]+v.w;
				if(!used[v.v])
				Q.push(v.v),used[v.v]=1;
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
	G.SPFA(S);
	for(int i=1;i<=n;i++)
	printf("%lld ",G.dis[i]);
	printf("\n");
	return 0;
}