#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<cmath>
#include<map>
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
Lint Baby_Step_Giant_Step(Lint a,Lint b,Lint c,Lint d=1){
	map<int,int>hash;hash.clear();b%=c;
	int t=(int)sqrt(c)+1;
	for(int i=0;i<t;i++)
		hash[(int)(b*power(a,i,c)%c)]=i;
	a=power(a,t,c);
	if(a==0){
		if(b==0)return 1;
		return -1;
	}
	for(int i=1,val;i<=t;i++){
		int j=hash.find(val=d*power(a,i,c)%c)==hash.end()?-1:hash[val];
    	if(j>=0&&i*t-j>=0)return i*t-j;
	}
	return -1;
}
Lint P,B,N,ans;
int main(){
	P=read();B=read();N=read();
	ans=Baby_Step_Giant_Step(B,N,P);
	if(ans==-1)printf("no solution\n");
	else printf("%lld\n",ans);
	return 0;
}

