#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<cctype>
using namespace std;
const int inf=0x7fffffff;
const double eps=1e-10;
const double pi=acos(-1.0);
//char buf[1<<15],*S=buf,*T=buf;
//char getch(){return S==T&&(T=(S=buf)+fread(buf,1,1<<15,stdin),S==T)?0:*S++;}
inline long long read(){
	long long x=0,f=1;char ch;ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=0;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch&15);ch=getchar();}
	if(f)return x;else return -x;
}
const int Lim=60;
struct Linear_Base{
  long long a[Lim+10];
  void insert(long long x){
    for(int i=Lim;i>=0;i--)if(x&(1ll<<i)){
	    if(!a[i]){a[i]=x;return;}
	    else x^=a[i];
		}
  }
  bool check(long long x){
    for(int i=Lim;i>=0;i--)if(x&(1ll<<i)){
	    if(!a[i])return 0;
	    else x^=a[i];
		}
    return 1;
  }
  long long querymax(long long res){
    for(int i=Lim;i>=0;i--)if((res^a[i])>res)res^=a[i];
    return res;
  }
  long long querymin(long long res){
    for(int i=Lim;i>=0;i--)if(res&(1ll<<i))res^=a[i];
    return res;
  }
  long long querykth(int k){
    long long tmp[Lim+1],res=0,cnt=0;
    for(int i=0;i<=Lim;i++){
      for(int j=i-1;j>=0;j--)if(a[i]&(1ll<<j))a[i]^=a[j];
      if(a[i])tmp[cnt++]=a[i];
    }
    for(int i=0;i<cnt;i++)if(k&(1ll<<i))res^=tmp[i];
    return res;
  }
  void merge(const Linear_Base &other)
	{for(int i=0;i<=Lim;i++) insert(other.a[i]);}
}LB;
int main(){
  int n=(int)read();
  for(int i=1;i<=n;i++)
	{long long x=read();LB.insert(x);}
  printf("%lld\n",LB.querymax(0));
  return 0;
}
