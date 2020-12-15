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
const int N=1e6+10;
int nex[N];
char s[N],p[N];
void KMP(char s[],char p[]){
	int slen=strlen(s),plen=strlen(p);
	nex[0]=-1;
	for(int i=1,j=0;i<plen;i++){
	  	while(j&&p[j]!=p[i])j=nex[j];
	  	if(p[i]==p[j])j++;
	  	nex[i+1]=j;
	}
	for(int i=0,j=0;i<slen&&j<plen;){
	  	(j==-1||s[i]==p[j])?i++,j++:j=nex[j];
	  	if(j==plen)printf("%d\n",i-j+1),j=nex[j];
	}
}
int main(){
	scanf("%s%s",s,p);
	KMP(s,p);
	for(int i=1;i<=strlen(s);i++)
	printf("%d ",nex[i]);
	printf("\n");
	return 0;
}

