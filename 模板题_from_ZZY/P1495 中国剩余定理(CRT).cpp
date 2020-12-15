#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<queue>
#include<cmath>
#define Lint long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch;ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N=100;
void exgcd(Lint a,Lint b,Lint &d,Lint &x,Lint &y){
	if(!b){d=a;x=1ll;y=0ll;return;}
	exgcd(b,a%b,d,y,x);y-=x*(a/b);
}
Lint Chinese_Reminder(Lint c[],Lint mod[],int n){
  Lint Mod=1ll,ret=0ll;
  for(int i=1;i<=n;i++) Mod*=mod[i];
  for(int i=1;i<=n;i++){
    Lint m=Mod/mod[i];
    Lint d,x,y;exgcd(m,mod[i],d,x,y);
    (ret+=m%Mod*x%Mod*c[i]%Mod+Mod)%=Mod;
  }
  return ret;
}
int n;
Lint a[N],b[N];
int main(){
	n=read();
	for(int i=1;i<=n;i++)
	a[i]=1ll*read(),b[i]=1ll*read();
	printf("%lld\n",Chinese_Reminder(b,a,n));
	return 0;
}