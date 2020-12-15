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
		P[b].push_back(a);
	}
	vector<int> P2[N];
	void add2(int a,int b){
		P2[a].push_back(b);
		P2[b].push_back(a);
	}
	int sta[N],top;
	int low[N],dfn[N],tim;
	int mark;
	void tarjan(int u){
		sta[++top]=u;
		low[u]=dfn[u]=++tim;
		for(auto v:P[u]){
			if(!dfn[v]){
				tarjan(v);
				low[u]=min(low[u],low[v]);
		      	if(low[v]==dfn[u]){
					mark++;
					while(sta[top+1]!=v){
						add2(sta[top],mark);
						top--;
					}
					add2(u,mark);
		      	}
			}
			else low[u]=min(low[u],dfn[v]);
		}
	}
	void Solve_Cactaceae(int n){
		mark=n;
		for(int i=1;i<=n;i++)
		if(!dfn[i]) tarjan(i),top=0;
	}
}G; 
int main(){
	n=read();m=read();
	while(m--){
		int a=read(),b=read();
		G.add(a,b);
	}
	G.Solve_Cactaceae(n);
	return 0;
}
/*
9 12
1 2
2 3
1 3
3 4
3 5
4 5
5 6
4 6
3 7
3 8
7 8
7 9
*/
