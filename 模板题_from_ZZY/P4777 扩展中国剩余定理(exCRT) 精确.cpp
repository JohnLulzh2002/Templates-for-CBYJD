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
	a=(a+mod)%mod;b=(b+mod)%mod;
	if(a<b)swap(a,b);
	Lint ans=0ll;
	for(;b;b>>=1,a=(a+a)%mod)
	if(b&1ll)ans=(ans+a)%mod;
	return ans;
}
void exgcd(Lint a,Lint b,Lint &d,Lint &x,Lint &y){
	if(!b){d=a;x=1ll;y=0ll;return;}
	exgcd(b,a%b,d,y,x);y-=x*(a/b);
}
Lint Mod(Lint a,Lint b){
	a%=b;return a<0?a+b:a;
}
Lint ex_Chinese_Reminder(Lint *c,Lint *mod,int n){
	Lint d,x,y;
	for(Lint i=1;i<n;i++){
		exgcd(mod[i],mod[i+1],d,x,y);
		mod[i+1]=mod[i]/d*mod[i+1];
		c[i+1]=Mod(Mul((c[i+1]-c[i]),Mul(x,(mod[i]/d),mod[i+1]),mod[i+1])+c[i],mod[i+1]);
	}
	return Mod(c[n],mod[n]);
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
