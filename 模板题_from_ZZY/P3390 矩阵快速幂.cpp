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
struct matrix{
	int n,m;
	Lint data[101][101];
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
		return ;
	}
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
int n;
Lint b;
int main(){
	n=(int)read(),b=read();
	mat.In(n,n);
	ans=power(mat,b);
	ans.Out();
	return 0;
}
