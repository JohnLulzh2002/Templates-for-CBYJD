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
const int N=2e6+10;
const int M=N<<1;
int n; 
struct Graph{
	vector<int> P[N];
	void add(int a,int b){
		P[a].push_back(b);
	}
	void Get_Edge(int a,int a_yes,int b,int b_yes){
		add(a+(a_yes^1)*n,b+b_yes*n);
	    add(b+(b_yes^1)*n,a+a_yes*n);
	}
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
				top--;
			}
		}
	}
	int ans[N];
	bool two_SAT(){
		for(int i=1;i<=2*n;i++)
		if(!dfn[i]) tarjan(i);
		for(int i=1;i<=n;i++)
		if(col[i]==col[i+n]) return 0;
		else ans[i]=col[i]>col[i+n];
		return 1;
	}
}G;
int m;
int main(){
	n=read();m=read();
	while(m--){
		int a=read(),a_yes=read(),b=read(),b_yes=read();
		G.Get_Edge(a,a_yes,b,b_yes);
	}
	if(G.two_SAT()){
	    printf("POSSIBLE\n");
	    for(int i=1;i<=n;i++)printf("%d ",G.ans[i]);
	}
	else printf("IMPOSSIBLE");
	printf("\n");
	return 0;
}
