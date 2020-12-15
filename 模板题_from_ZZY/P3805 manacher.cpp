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
const int N=1e7+1e6+1; 
char s[N],P[N<<1];
int RL[N<<1];
void Manacher(char s[],int n){
	int mr=0,pos=0;
	memset(RL,0,n*sizeof(int));
	for(int i=0;i<n;i++){
	 	mr>i?RL[i]=min(RL[(pos<<1)-i],mr-i):RL[i]=1;
    	while(s[i+RL[i]]==s[i-RL[i]])RL[i]++;
		if(i+RL[i]>mr)mr=i+RL[i],pos=i;
	}
}
void Manacher_Init(char s[]){
	int len=strlen(s);P[0]='$';
	for(int i=1;i<=(len<<1|1);i+=2) P[i]='#';
	for(int i=0;i<len;i++) P[(i<<1)+2]=s[i];
	Manacher(P,len<<1|1);
}
int main(){
	scanf("%s",s);
	Manacher_Init(s);
	int ans=0,len=strlen(s);
	for(int i=0;i<=(len<<1|1);i++)
  	ans=max(ans,RL[i]-1);
  	printf("%d\n",ans);
	return 0;
}

