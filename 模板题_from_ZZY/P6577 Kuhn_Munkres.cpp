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
const Lint inf=1e18;
const double eps=1e-10;
const double pi=acos(-1.0);
inline int read(){
	int x=0,f=1;char ch;ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N=510;
int n,m,e;
struct Graph{
	Lint Map[N][N];
	bool usem[N],usen[N];
	int match[N],pre[N];
	Lint maxn[N],maxm[N],slack[N];
	void Init(int n){
		memset(match,-1,sizeof(match));
		memset(maxn,0,sizeof(maxn));
		memset(maxm,0,sizeof(maxm));
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			Map[i][j]=-inf;
	}
	void add(int a,int b,Lint c){
		Map[a][b]=c;
	}
	void Match(int u){
		Lint y=0,ls=0;
	    memset(pre,0,sizeof(pre));
	    for(int i=1;i<=n;i++)slack[i]=inf;
	    match[y]=u;
	    while(1){
	        u=match[y];
			Lint a=inf;usem[y]=1;
			for(int v=1;v<=n;v++)
			if(!usem[v]){
	            if(slack[v]>maxn[u]+maxm[v]-Map[u][v])	
	            slack[v]=maxn[u]+maxm[v]-Map[u][v],pre[v]=y;
	            if(slack[v]<a)
				a=slack[v],ls=v;
	        }
			for(int v=0;v<=n;v++){	
	            if(usem[v])maxn[match[v]]-=a,maxm[v]+=a;
	            else slack[v]-=a;
	        }
	        y=ls;
	        if(match[y]==-1)break;
	    }
	    while(y){
			match[y]=match[pre[y]];
			y=pre[y];
		}
	}
	Lint Kuhn_Munkres(int n){
		for(int i=1;i<=n;i++){	
			memset(usem,0,sizeof(usem));
			Match(i);
		}
		Lint res=0;
	  	for(int u=1;u<=n;u++)
		if(match[u]!=-1)res+=Map[match[u]][u];
	  	return res;
	}
}G;
int main(){
	n=m=read();e=read();
	G.Init(n);
	while(e--){
		int a=read(),b=read(),c=read();
		G.add(a,b,1ll*c);
	}
	printf("%lld\n",G.Kuhn_Munkres(n));
	for(int i=1;i<=n;i++)
	printf("%d ",G.match[i]);
	printf("\n");
	return 0;
}
