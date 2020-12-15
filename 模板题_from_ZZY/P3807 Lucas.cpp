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
Lint power(Lint a,Lint b,Lint mod){
	Lint ans=1ll;
	while(b){
		if(b&1ll)ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}
Lint C(Lint n,Lint m,Lint mod){
	Lint a=1ll,b=1ll;
	for(Lint i=1;i<=m;i++)
    a=a*(n-i+1)%mod,b=b*i%mod;
	return (a*(power(b,mod-2,mod)))%mod;
}
Lint Lucas(Lint n,Lint m,Lint mod){
    if(m==0) return 1ll;
    return (Lucas(n/mod,m/mod,mod)*C(n%mod,m%mod,mod))%mod;
}
Lint T,n,m,mod;
int main(){
	T=read();
	while(T--){
		n=read();m=read();mod=read();
		printf("%lld\n",Lucas(n+m,n,mod));
	}
	return 0;
}

