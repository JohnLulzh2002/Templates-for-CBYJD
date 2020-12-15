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
const int N=2010;
const int M=1e6+10;
int n,m,e;
struct Graph{
	vector<int> P[N];
	void add(int a,int b){
		P[a].push_back(b);
	}
	bool used[N];
	int match[N<<1];
	bool dfs(int u){
		for(auto v:P[u])
		if(!used[v]){
			used[v]=1;
			if(!match[v]||dfs(match[v]))
			{match[v]=u;return 1;}
		}
		return 0;
	}
	int Hungary(int n){
		int ans=0;
		for(int i=1;i<=n;i++){
			memset(used,0,(n+1)*sizeof(bool));
			if(dfs(i))ans++;
		}
		return ans;
	}
}G;
int main(){
	n=read();m=read();e=read();
	while(e--){
		int a=read(),b=read();
		G.add(a,b);
	}
	printf("%d\n",G.Hungary(n));
	return 0;
}
