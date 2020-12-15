#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<queue>
#include<cmath>
#define Lint long long
using namespace std;
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
void exgcd(Lint a,Lint b,Lint &d,Lint &x,Lint &y){
	if(!b){d=a;x=1ll;y=0ll;return;}
	exgcd(b,a%b,d,y,x);y-=x*(a/b);
}
Lint inv(Lint a,Lint p){
	Lint d,x,y;exgcd(a,p,d,x,y);
	return (x+p)%p;
}
Lint fac(Lint n,Lint p,Lint pc){
	if(n==0)return 1;
	Lint ret=1;
	for(Lint i=2;i<=pc;i++)if(i%p)ret=(ret*i)%pc;
	ret=power(ret,n/pc,pc);
	for(Lint i=2;i<=n%pc;i++)if(i%p)ret=(ret*i)%pc;
	return (ret*fac(n/p,p,pc))%pc;
}
Lint C(Lint n,Lint m,Lint p,Lint pc){
	if(n<m)return 0;
	Lint a=fac(n,p,pc),b=fac(m,p,pc),c=fac(n-m,p,pc);
	Lint k=0;
	for(Lint i=n;i;i/=p)k+=i/p;
	for(Lint i=m;i;i/=p)k-=i/p;
	for(Lint i=n-m;i;i/=p)k-=i/p;
	return a*inv(b,pc)%pc*inv(c,pc)%pc*power(p,k,pc)%pc;
}
Lint exLucas(Lint n,Lint m,Lint mod){
	Lint ret=0,P=mod;
	for(Lint i=2;i<=P;i++)
    if(P%i==0){
		Lint pc=1;
		while(P%i==0)P/=i,pc*=i;
		(ret+=C(n,m,i,pc)*(mod/pc)%mod*inv(mod/pc,pc)%mod)%=mod;
	}
	return ret;
}
int main(){
	Lint n=read(),m=read(),mod=read();
	printf("%lld\n",exLucas(n,m,mod));
	return 0;
}