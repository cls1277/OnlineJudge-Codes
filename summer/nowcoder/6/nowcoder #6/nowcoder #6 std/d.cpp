#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int m,pri[2001000];
void sieve(){
	for(int i=2;i<=m;i++){
		if(!pri[i])pri[++pri[0]]=i;
		for(int j=1;j<=pri[0]&&i*pri[j]<=m;j++){pri[i*pri[j]]=true;if(!(i%pri[j]))break;} 
	}
}
ll kth[2001000];
ll g[2001000];
int tot,sml[2001000],lar[2001000];
#define HS(x) ((x)<=m?sml[x]:lar[n/(x)])
ll dfs(ll _n,int _i,int _j,int _k){
	if(_n<=pri[_i])return 0;
	ll ret=0;
	if((max(_j,1)<<1)<=(_k+1)&&(_k&1))ret=g[HS(_n)]-_i;
	for(int i=_i+1;1ll*pri[i]*pri[i]<=_n&&i<=pri[0];i++){
		ll P=pri[i];
		for(int a=1;P<=_n;P*=pri[i],a++){
			ret+=dfs(_n/P,i,max(_j,a),_k+a);
			if(a!=1&&(max(_j,a)<<1)<=_k+a&&!((_k+a)&1))ret++;
		}
	}
	// printf("%lld,%d,%d,%d:%d\n",_n,_i,_j,_k,ret);
	return ret;
}
int main(){
	scanf("%lld",&n),m=sqrt(n),sieve();
	for(ll i=1;i<=n;i=n/(n/i)+1){
		kth[++tot]=n/i;
		HS(kth[tot])=tot;
		g[tot]=kth[tot]-1;
	}
	for(int i=1;i<=pri[0];i++)for(int j=1;j<=tot&&1ll*pri[i]*pri[i]<=kth[j];j++)
		g[j]-=(g[HS(kth[j]/pri[i])]-(i-1));
	// for(int i=1;i<=tot;i++)printf("%lld:%d\n",kth[i],g[i]);
	printf("%lld\n",dfs(n,0,0,0));
	return 0;
}
