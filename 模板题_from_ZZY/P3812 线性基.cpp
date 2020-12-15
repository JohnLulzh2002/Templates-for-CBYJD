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
const int Lim=63;
struct Linear_Base{
	Lint a[Lim+10];
	void insert(Lint x){
		for(int i=Lim;i>=0;i--)
		if(x&(1ll<<i))
			if(!a[i]){a[i]=x;return;}
			else x^=a[i];
	}
	bool check(Lint x){
		for(int i=Lim;i>=0;i--)
		if(x&(1ll<<i))
			if(!a[i])return 0;
			else x^=a[i];
		return 1;
	}
	Lint querymax(Lint res){
		for(int i=Lim;i>=0;i--)
		res=max(res,res^a[i]);
		return res;
	}
	Lint querymin(Lint res){
		for(int i=Lim;i>=0;i--)
		if(res&(1ll<<i))res^=a[i];
		return res;
	}
	Lint querykth(int k){
		Lint tmp[Lim+1],res=0,cnt=0;
		for(int i=0;i<=Lim;i++){
			for(int j=i-1;j>=0;j--)
			if(a[i]&(1ll<<j))a[i]^=a[j];
			if(a[i])tmp[cnt++]=a[i];
		}
		for(int i=0;i<cnt;i++)
		if(k&(1ll<<i))res^=tmp[i];
		return res;
	}
	void merge(const Linear_Base &b){
  		for(int i=0;i<=Lim;i++) insert(b.a[i]);
	}
}LB;
Lint x;
int main(){
	int n=(int)read();
	while(n--)x=read(),LB.insert(x);
	printf("%lld\n",LB.querymax(0));
	return 0;
}

