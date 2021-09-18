//By cls1277
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<stack>
#include<sstream>
#include<set>
#include<cassert>
#include<bitset>
using namespace std;
typedef long long LL;
#define PI acos(-1)
#define INF 2147483647
#define eps 1e-7
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define lowbit(_) _&(-_)
inline LL read() {
	LL x = 0, f = 1;char c = getchar();
	while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
	while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
	return x * f;
}

const LL maxn = 1e7+5;
LL a , b , c , T , prime[maxn] , cnt , ans , tt=1;
bitset<maxn>vis;

void init() {
	vis.reset();
	vis[1]=1; cnt=0;
	for(int i=2; i<=maxn; i++) {
		if(!vis[i]) prime[++cnt]=i;
		for(int j=1; j<=cnt&&prime[j]*i<=maxn; j++) {
			vis[prime[j]*i]=1;
			if(i%prime[j]==0) break; 
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>T;
	init();
	while(T--) {
		cin>>a>>b; c=a; ans=1;
		Fo(i,1,cnt) {
			int res=0;
			while(c%prime[i]==0) {
				c/=prime[i];
				res++;
			}
			//if(res) cout<<prime[i]<<" "<<res<<endl;
			ans*=(res+1);
		}
		for(int i=1; i<b; i++) {
			if(i*i==a) {
				ans--; continue;
			}
			if(i>a/i) break;
			if(a%i==0)
				ans-=2;
		}	
		if(ans%2) ans=(ans-1)/2+1;
		else ans/=2;
		cout<<"Case "<<(tt++)<<": "<<ans<<endl;
	} 
	return 0;
}

