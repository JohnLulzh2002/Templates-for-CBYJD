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
int n,m,S;
bool ans[100001000];
struct Graph{
	struct Edge{
		int v;Lint w;
	};
	vector<Edge> P[N];
	void add(int a,int b,Lint c){
		P[a].push_back((Edge){b,c});
	}
	int root,sum;
	int f[N],size[N];
	Lint dis[N];
	bool used[N];
	void getroot(int u,int fa){
	  	size[u]=1;f[u]=0;
	  	for(auto v:P[u]){
	    	if(used[v.v]||v.v==fa) continue;
	    	getroot(v.v,u);
	    	size[u]+=size[v.v];
	    	f[u]=max(f[u],size[v.v]);
	  	}
	  	f[u]=max(f[u],sum-size[u]);
	  	if(f[u]<f[root]) root=u;
	}
	struct node{Lint dis;int id;}rp[1001000];
	int top,cnt;
	void getdis(int rt,int u,int fa,int turn){
	  	for(auto v:P[u])
	  	if(!used[v.v]&&v.v!=fa){
	    	ans[dis[v.v]=dis[u]+v.w]=1;
	    	if(u==rt)turn=++cnt;
	    	rp[++top]=(node){dis[v.v],turn};
			getdis(rt,v.v,u,turn);
	  	}
	}
	void getans(int u){
	  	dis[u]=0;top=0;cnt=0;
	  	getdis(u,u,0,cnt);
	  	for(int i=1;i<=top;i++)
	  	for(int j=i+1;j<=top;j++)
	  	if(rp[i].id!=rp[j].id)
	  	ans[rp[i].dis+rp[j].dis]=1;
	  	
	  	used[u]=1;
	  	for(auto v:P[u])
	  	if(!used[v.v]){
	    	sum=size[v.v];
	    	Point_Solve(v.v);
	  	}
	}
	void Point_Solve(int a){
		root=0;getroot(a,0);
	    getans(root);
	}
}G;
int main(){
	n=read();m=read();
	for(int i=1;i<n;i++){
		int a=read(),b=read(),c=read();
		G.add(a,b,1ll*c);
		G.add(b,a,1ll*c);
	}
	G.sum=G.f[0]=n;
  	G.Point_Solve(1);
  	while(m--){
    	int K=read();
    	if(ans[K]) printf("AYE\n");
    	else printf("NAY\n");
  	}
	return 0;
}
