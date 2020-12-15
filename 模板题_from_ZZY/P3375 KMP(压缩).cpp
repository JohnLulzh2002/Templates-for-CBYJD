#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
const int N=1e6+10;
int nex[N];
char s[N],p[N];
void KMP(char s[],char p[]){
	int slen=strlen(s),plen=strlen(p);
	nex[0]=-1;
	for(int j=0,k=-1;j<slen;)
	(k==-1||s[j]==s[k])?nex[++j]=++k:k=nex[k];
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