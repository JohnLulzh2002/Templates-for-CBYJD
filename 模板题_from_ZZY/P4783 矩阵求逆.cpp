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
inline Lint read(){
	Lint x=0,f=1;char ch;ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N=410;
struct matrix{
	int n,m;
	Lint data[N][N];
	void In(int a,int b){
		n=a;m=b;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		data[i][j]=read();
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
}mat,ans;
matrix operator *(matrix m1,matrix m2){
	matrix t;
	t.n=m1.n;t.m=m2.m;
	for(Lint i=1;i<=m1.n;i++)
	for(Lint j=1;j<=m2.m;j++){
	  	t.data[i][j]=0ll;
	  	for(Lint k=1;k<=m1.m;k++)
	  	t.data[i][j]=(t.data[i][j]+m1.data[i][k]*m2.data[k][j]%mod)%mod;
	}
	return t;
}
matrix power(matrix m1,Lint b){
	matrix rt;rt.init(m1.n,1ll);
	while(b){
		if(b&1ll)rt=rt*m1;
		m1=m1*m1;b>>=1;
	}
	return rt;
}
Lint inv(Lint a){
	Lint ans=1ll,b=mod-2ll;
	while(b){if(b&1ll)ans=a*ans%mod;a=a*a%mod;b>>=1;}
	return ans;
}
bool Inv(matrix m1,matrix &rt){
	int n=m1.n;
	rt.init(n,1ll);
	for(int i=1;i<=n;i++){
	    for(int j=i;j<=n;j++)
	    if(m1.data[j][i]){
	    	m1.R_Swap(i,j);
	    	rt.R_Swap(i,j);
	    	break;
		}
	    if(!m1.data[i][i])return 0;
	    Lint r=inv(m1.data[i][i]);
	    m1.R_Mul(i,r);rt.R_Mul(i,r);
	    for(int j=1;j<=n;j++)
	    if(j!=i){
	    	Lint f=m1.data[j][i];
	    	m1.R_Add(i,-f,j);
	    	rt.R_Add(i,-f,j);
	    }
	}
	return 1;
}
int n;
int main(){
	n=(int)read();
	mat.In(n,n);
	if(!Inv(mat,ans)){printf("No Solution\n");return 0;}
	else ans.Out();
	return 0;
}
