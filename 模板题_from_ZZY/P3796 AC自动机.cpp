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
char s[160][80],word[N];
int cnt[160],n,ans;
struct AC_Automata{
	int son[N][26],fail[N],appear[N];
	int size;
	void clear(int a){
		memset(son[a],0,sizeof(son[a]));
		fail[a]=appear[a]=0;
	}
	void Init(){
		size=0;
		clear(0);
	}
	void Get_trie(char s[],int id){
		int len=strlen(s),now=0;
		for(int i=0;i<len;i++){
			if(!son[now][s[i]-'a'])
			son[now][s[i]-'a']=++size,clear(size);
			now=son[now][s[i]-'a']; 
		}
		appear[now]=id;
	}
	void Get_fail(){
		queue<int> Q;
		for(int i=0;i<26;i++)if(son[0][i]!=0)
		fail[son[0][i]]=0,Q.push(son[0][i]);
		while(!Q.empty()){
			int u=Q.front();Q.pop();
			for(int i=0;i<26;i++)if(son[u][i])
			fail[son[u][i]]=son[fail[u]][i],Q.push(son[u][i]);
			else son[u][i]=son[fail[u]][i];
		}
	}
	int query(char s[]){
		int len=strlen(s),now=0;
	    for(int i=0;i<len;i++){
	    	now=son[now][s[i]-'a'];
	    	for(int t=now;t;t=fail[t])cnt[appear[t]]++;
	    }
	} 
}ACau;
int main(){
	while(n=read()){
    	ACau.Init();
 		for(int i=1;i<=n;i++)
    	scanf("%s",s[i]),ACau.Get_trie(s[i],i);
 		ACau.Get_fail();
 		memset(cnt,0,sizeof(cnt));ans=0;
 		scanf("%s",word);ACau.query(word);
 		for(int i=1;i<=n;i++)ans=max(ans,cnt[i]);
 		printf("%d\n",ans);
 		for(int i=1;i<=n;i++)
 		if(ans==cnt[i])printf("%s\n",s[i]);
  	}
  	return 0;
}

