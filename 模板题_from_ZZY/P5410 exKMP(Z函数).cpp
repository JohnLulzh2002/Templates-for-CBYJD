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
inline int read(){
	int x=0,f=1;char ch;ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N=2e7+10;
int z[N<<1];
char s[N],p[N<<1];
Lint ans;
void exKMP(char s[]){
	int slen=strlen(s);
	memset(z,0,slen*sizeof(int));
	z[0]=slen;
	for(int i=1,l=0,r=0;i<slen;i++){
		if(i<=r)z[i]=min(z[i-l],r-i+1);
		while(i+z[i]<slen&&s[z[i]]==s[z[i]+i])z[i]++;
		if(i+z[i]-1>r)l=i,r=i+z[i]-1;
	}
}
int main(){
	scanf("%s%s",s,p);
	int slen=strlen(s),plen=strlen(p);
	exKMP(p);ans=0;
	for(int i=0;i<plen;i++)ans^=1ll*(z[i]+1)*(i+1);
	printf("%lld\n",ans);
	for(int i=0,j=plen;i<=slen;i++,j++)p[j]=s[i];
	exKMP(p);ans=0;
	for(int i=0;i<slen;i++)ans^=1ll*(z[i+plen]+1)*(i+1);
	printf("%lld\n",ans);
	return 0;
}

