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
char GG[N<<1];
struct Sam{
	int len[N<<1],son[N<<1][26],fa[N<<1];
	int last,size=1;
	int newnote(){
		size++;
		memset(son[size],0,sizeof(son[size]));
		fa[size]=len[size]=0;
		return size;
	}
	void insert(int c){
		int p=last,np=newnote();
		last=np;
		len[np]=len[p]+1;
		for(;p&&!son[p][c];p=fa[p])son[p][c]=np;
		if(!p)fa[np]=1;
		else{
			int q=son[p][c];
			if(len[q]==len[p]+1)fa[np]=q;
			else{
				int nq=newnote();
				len[nq]=len[p]+1;
				memcpy(son[nq],son[q],sizeof(son[q]));
				fa[nq]=fa[q];fa[q]=fa[np]=nq;
				for(;son[p][c]==q;p=fa[p])son[p][c]=nq;
			}
		}
	}
	void Insert(char s[]){
		last=1;
		int len=strlen(s);
		for(int i=0;i<len;i++)insert(s[i]-'a');
	}
	Lint Get_ans(){
        Lint ans=0ll;
        for(int i=2;i<=size;i++)
		ans+=1ll*(len[i]-len[fa[i]]);
        return ans;
    }
}Sam;
int main(){
	int n=read();
	while(n--){
		scanf("%s",GG);
	 	Sam.Insert(GG);
	}
 	printf("%lld\n",Sam.Get_ans());
	return 0;
}
