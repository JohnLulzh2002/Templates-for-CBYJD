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
	void add(int a,int b){
		P[a].push_back(b);
	}
	bool used[N];
	int sta[N],top;
	int low[N],dfn[N],tim;
	void tarjan(int u,int rt){
		int num=0;
		low[u]=dfn[u]=++tim;
		for(auto v:P[u]){
		    if(!dfn[v]){
		    	tarjan(v,rt);
		    	low[u]=min(low[u],low[v]);
		    	if(low[v]==dfn[u]&&u!=rt&&!used[u])
		    	sta[++top]=u,used[u]=1;
		    	if(u==rt)num++;
			}
		    low[u]=min(low[u],dfn[v]);
		}
		if(u==rt&&num>=2&&!used[u])
  		sta[++top]=u,used[u]=1;
	}
	void Find_Cut_Vertex(int n){
		for(int i=1;i<=n;i++)
		if(!dfn[i]) tarjan(i,i);
		sort(sta+1,sta+top+1);
	}
}G;
int main(){
	n=read();m=read();
	while(m--){
		int a=read(),b=read();
		G.add(a,b);G.add(b,a);
	}
	G.Find_Cut_Vertex(n);
	printf("%d\n",G.top);
	for(int i=1;i<=G.top;i++)
	printf("%d ",G.sta[i]);
	printf("\n");
	return 0;
}