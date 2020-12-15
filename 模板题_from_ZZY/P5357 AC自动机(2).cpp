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
const int N=2000010;
char s[N],word[N];
int mp[N];
int n;
struct AC_Automata{
	int son[N][26],fail[N],cnt[N],du[N];
	int size;
	void Get_trie(char s[],int id){
		int len=strlen(s),now=0;
		for(int i=0;i<len;i++){
			if(!son[now][s[i]-'a'])
			son[now][s[i]-'a']=++size;
			now=son[now][s[i]-'a']; 
		}
		mp[id]=now;
	}
	void Get_fail(){
		queue<int> Q;
		for(int i=0;i<26;i++)if(son[0][i]!=0)
		fail[son[0][i]]=0,Q.push(son[0][i]);
		while(!Q.empty()){
			int u=Q.front();Q.pop();
			for(int i=0;i<26;i++)if(son[u][i])
				fail[son[u][i]]=son[fail[u]][i],
				du[fail[son[u][i]]]++,
				Q.push(son[u][i]);
			else son[u][i]=son[fail[u]][i];
		}
	}
	void query(char s[]){
		int len=strlen(s),now=0;
	    for(int i=0;i<len;i++)
		now=son[now][s[i]-'a'],cnt[now]++;
		queue<int> Q;
	    for(int i=1;i<=size;i++)
	    if(!du[i])Q.push(i);
	    while(!Q.empty()){
	        int u=Q.front();Q.pop();
	        cnt[fail[u]]+=cnt[u];
	        du[fail[u]]--;
	        if(!du[fail[u]])Q.push(fail[u]);
	    }
	    return;
	}
}ACau;
int main(){
	n=read();
 	for(int i=1;i<=n;i++)
    scanf("%s",s),ACau.Get_trie(s,i);
 	ACau.Get_fail();
 	scanf("%s",word);ACau.query(word);
    for(int i=1;i<=n;i++)
	printf("%d\n",ACau.cnt[mp[i]]);
  	return 0;
}

