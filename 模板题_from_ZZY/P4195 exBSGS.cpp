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
Lint gcd(Lint a,Lint b){return b?gcd(b,a%b):a;}
Lint Baby_Step_Giant_Step(Lint a,Lint b,Lint c,Lint d){
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
Lint ex_Baby_Step_Giant_Step(Lint a,Lint b,Lint c){
	a%=c;b%=c;
	if(b==0||c==0)return -1;
	if(a==0)return b?-1:0;
	int d=1ll,k=0ll;
	for(int g=gcd(a,c);g!=1ll;g=gcd(a,c)){
		if(b%g)return -1;
		c/=g;b/=g;d=d*(a/g)%c;k++;
		if(b==d)return k;
	}
	int ans=Baby_Step_Giant_Step(a,b,c,d);
	return ans==-1?-1:ans+k;
}
int main(){
	while(1){
		int a=read(),c=read(),b=read(),ans;
    	if(!a&&!b&&!c)break;
    	if(~(ans=ex_Baby_Step_Giant_Step(a,b,c)))cout<<ans<<endl;
    	else cout<<"No Solution"<<endl;
	}
	return 0;
}

