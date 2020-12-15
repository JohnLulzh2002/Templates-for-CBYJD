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
int n,m;
struct Graph{
	vector<int> P[N];
	int U[N],V[N],edge_cnt;
	void add(int a,int b){
		U[++edge_cnt]=a;V[edge_cnt]=b;
		P[a].push_back(b);
	}
	Lint W[N],val[N];
	int col[N],mark;
	int sta[N],top;
	int low[N],dfn[N],tim;
	void tarjan(int u){
		sta[++top]=u;
		low[u]=dfn[u]=++tim;
		for(auto v:P[u]){
		    if(!dfn[v])tarjan(v);
		    if(!col[v])low[u]=min(low[u],low[v]);
		}
		if(low[u]==dfn[u]){
			mark++;
			while(sta[top+1]!=u){
				col[sta[top]]=mark;
				val[mark]+=W[sta[top]];
				top--;
			}
		}
	}
	void Build_New_Tree(int n){
		for(int i=1;i<=n;i++)
		if(!dfn[i]) tarjan(i);
		for(int i=1;i<=n;i++)P[i].clear();
		for(int i=1;i<=edge_cnt;i++)
		if(col[U[i]]!=col[V[i]])
		P[col[U[i]]].push_back(col[V[i]]);
	}
	Lint dis[N];
	Lint dfs(int a){
		if(dis[a]) return dis[a];
		Lint x=0;
		for(auto v:P[a])x=max(x,dfs(v));
		return dis[a]=x+val[a];
	}
}G; 
int main(){
	n=read();m=read();
	for(int i=1;i<=n;i++)G.W[i]=1ll*read();
	while(m--){
		int a=read(),b=read();
		G.add(a,b);
	}
	G.Build_New_Tree(n);
	Lint ans=0;
	for(int i=1;i<=G.mark;i++)
	if(!G.dis[i])ans=max(ans,G.dfs(i));
	printf("%lld\n",ans);
	return 0;
}

