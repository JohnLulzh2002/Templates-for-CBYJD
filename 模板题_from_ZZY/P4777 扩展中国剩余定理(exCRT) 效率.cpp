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
const int N=1e5+10;
inline Lint read(){
	Lint x=0,f=1;char ch;ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline Lint Mul(Lint a,Lint b,Lint mod){
  	Lint d=(Lint)floor(a*(double)b/mod+0.5);
  	Lint ret=a*b-d*mod;
  	return ret<0?ret+mod:ret;
}
void exgcd(Lint a,Lint b,Lint &d,Lint &x,Lint &y){
	if(!b){d=a;x=1ll;y=0ll;return;}
	exgcd(b,a%b,d,y,x);y-=x*(a/b);
}
Lint ex_Chinese_Reminder(Lint *c,Lint *mod,int n){
	Lint Mod=mod[1],ret=c[1],x,y,d;
	for(int i=2;i<=n;i++){
		exgcd(Mod,mod[i],d,x,y);
		if((ret-c[i])%d)return -1;
		x=Mul((ret-c[i])/d,x,mod[i]);
		ret-=Mod*x;Mod=Mod/d*mod[i];
	}
	return (ret%Mod+Mod)%Mod;
}
int n;
Lint a[N],b[N];
int main(){
	n=read();
	for(int i=1;i<=n;i++)
	a[i]=1ll*read(),b[i]=1ll*read();
	printf("%lld\n",ex_Chinese_Reminder(b,a,n));
	return 0;
}
