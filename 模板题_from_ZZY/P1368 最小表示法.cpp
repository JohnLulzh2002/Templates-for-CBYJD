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
int A[300010<<1];
int id,n;
int get_id(int S[]){
//	int n=strlen(S);
    int s=0,t=1,k=0;
    while(s<n&&t<n&&k<n){
        int ls=S[(s+k)%n]-S[(t+k)%n];
        if(ls==0) k++;
        else{
            ls>0?s+=k+1:t+=k+1;
            if(s==t)t++;
            k=0;
        }
    }
  	return min(s,t);
}
int main(){
	n=read();
	for(int i=0;i<n;i++)A[i]=read();A[n]='\0';
	id=get_id(A);
	for(int j=0;j<n;j++)
	printf("%d ",A[(j+id)%n]);
	printf("\n");
	return 0;
}