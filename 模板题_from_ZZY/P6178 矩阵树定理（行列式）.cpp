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
const Lint mod=1e9+7;
inline int read(){
	int x=0,f=1;char ch;ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N=410;
Lint inv(Lint a){
	Lint ans=1ll,b=mod-2ll;
	while(b){if(b&1ll)ans=a*ans%mod;a=a*a%mod;b>>=1;}
	return ans;
}
struct matrix{
	int n,m;
	Lint data[N][N];
	void In(int a,int b){
		n=a;m=b;
	}
	void Out(){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
			printf("%lld ",data[i][j]);
			printf("\n");
		}
	}
	void init(int a,Lint v){
		n=m=a;
		memset(data,0,sizeof(data));
		for(Lint i=1;i<=n;i++)data[i][i]=1;
	}
	void R_Swap(int i,int j)
	{for(int k=1;k<=n;k++)swap(data[i][k],data[j][k]);}
	void R_Mul(int i,Lint v)
	{for(int j=1;j<=n;j++)data[i][j]=data[i][j]*v%mod;}
	void R_Add(int i,Lint v,int j)
	{for(int k=1;k<=n;k++)data[j][k]=(data[j][k]+v*data[i][k]%mod+mod)%mod;}
	Lint val(){
		Lint ans=1ll;
		for(int i=2;i<=n;i++){
			for(int j=i+1;j<=n;j++)
			if(!data[i][i]&&data[j][i])
			{R_Swap(i,j);ans=-ans;break;}
			Lint r=inv(data[i][i]);
			ans=(ans*data[i][i])%mod;
			for(int j=i+1;j<=n;j++)
			R_Add(i,mod-data[j][i]*r%mod,j);
		}
		return (ans+mod)%mod;
	}
}mat;
void Add_DG(int u,int v,Lint w){
	(mat.data[u][v]-=w)%=mod;
	(mat.data[v][v]+=w)%=mod;
}
void Add_UG(int u,int v,Lint w){
	(mat.data[u][v]-=w)%=mod;
	(mat.data[v][v]+=w)%=mod;
	(mat.data[v][u]-=w)%=mod;
	(mat.data[u][u]+=w)%=mod;
}
int n,m,t;
int u,v,w;
int main(){
	n=read();m=read();t=read();
	mat.In(n,n);
	for(int i=1;i<=m;i++){
		u=read();v=read();w=read();
		if(t)Add_DG(u,v,1ll*w);
		else Add_UG(u,v,1ll*w);
	}
	printf("%lld\n",mat.val());
	return 0;
}