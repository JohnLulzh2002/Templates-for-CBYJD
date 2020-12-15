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
inline Lint read(){
	Lint x=0,f=1;char ch;ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
Lint phi_mod;
Lint phi(Lint n){
	Lint ans=n,m=sqrt(n);
	for(Lint i=2;i<=m;i++){
		if(n%i==0){
			ans=ans/i*(i-1);
			while(n%i==0) n/=i;	
		}
	}
	if(n>1) ans=ans/n*(n-1);
	return ans;
}
Lint power(Lint a,Lint b,Lint mod){
	Lint ans=1ll;
	while(b){
		if(b&1ll)ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}
Lint gcd(Lint a,Lint b){return b?gcd(b,a%b):a;}
Lint f=0;
Lint Euler_Power(Lint a,Lint b,Lint mod){
	if(mod==1)return 0;
	if(gcd(a,mod)==1)return power(a,b,mod);
	if(f)return power(a,b+phi_mod,mod);
	else return power(a,b,mod);
}
Lint readb(){
	Lint x=0;char ch;ch=getchar();
	while(ch<'0'||ch>'9'){ch=getchar();}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		if(x>phi_mod)f=1,x%=phi_mod;
		ch=getchar();
	}
	return x;
}
Lint a,mod,b;
int main(){
	a=read();mod=read();
	phi_mod=phi(mod);
	b=readb();
	printf("%lld\n",Euler_Power(a,b,mod));
	return 0;
}
