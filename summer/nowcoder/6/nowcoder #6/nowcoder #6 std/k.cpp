#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<bitset>
#include<cassert>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(((long long)(n))-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mk make_pair
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
inline void read(long long &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
const int mod=1065977431;
int qp(int x,int y){int z=1;while(y){if(y&1){z=1ll*z*x%mod;}x=1ll*x*x%mod;y/=2;}return z;}
long long n;
int m,k,q,i,j,g[10000005],tg[10000005];
int pw[10000005];
int prod[10000005],iprod[10000005],tmp[10000005];
int pwq(int x){return qp(q,x);}
vector<int> mul(vector<int> a,vector<int> b)
{
	vector<int> c(a.size()+b.size()-1,0);int i,j;
	fz0k(i,a.size())fz0k(j,b.size()) c[i+j]=(c[i+j]+1ll*a[i]*b[j])%mod;
	return c;
}
int main()
{
//	freopen("inversion.in","r",stdin);freopen("inversion.out","w",stdout);
	read(n);read(m);read(k);read(q);
	assert(1<=n&&n<=1e18);assert(0<=m&&m<=n&&m<=1e7);assert(0<=k&&k<=n&&k<=30);assert(2<=q);
	pw[0]=1;fz1(i,10000002) pw[i]=1ll*pw[i-1]*q%mod;
	int tcoef=pwq((mod-1)-1ll*m*(m-1)/2%(mod-1));
	vector<int> sf,sh;
	sf=(vector<int>){1,pwq(n%(mod-1))};
	sh=(vector<int>){1,1};
	set<long long> _;
	fz1(i,k){
		long long x;int y;read(x);read(y);
		assert(1<=x&&x<=n);assert(0<=y&&y<=1);assert(!_.count(x));_.insert(x);
		if(y) m--,tcoef=1ll*tcoef*pwq((n-x)%(mod-1))%mod;
		sf=mul(sf,(vector<int>){1,pwq((n-x)%(mod-1))});
		sh=mul(sh,(vector<int>){1,pwq((n-x+1)%(mod-1))});
	}
	if(m<0||m>n-k){puts("0");return 0;}
	prod[0]=iprod[0]=1;fz1(i,m) prod[i]=tmp[i]=(sf[0]+1ll*(mod-sh[0])*pw[i])%mod;
	fz1(i,m) prod[i]=1ll*prod[i]*prod[i-1]%mod;
	iprod[m]=qp(prod[m],mod-2);fd1(i,m) iprod[i-1]=1ll*iprod[i]*tmp[i]%mod;
	g[0]=tg[0]=1;
	fz1(i,m){
		int coef=1ll*iprod[i]*prod[i-1]%mod;assert(coef);
		unsigned long long cur=0;int tms=0;
		fz1(j,sh.size()-1)if(i>=j){cur=(cur+1ll*sh[j]*tg[i-j]);if(!((++tms)&15))cur%=mod;}
		fz1(j,sf.size()-1)if(i>=j){cur=(cur+1ll*(mod-sf[j])*g[i-j]);if(!((++tms)&15))cur%=mod;}
		g[i]=cur%mod*coef%mod;tg[i]=1ll*g[i]*pw[i]%mod;
	}
	printf("%lld\n",1ll*tcoef*g[m]%mod);
	return 0;
}
