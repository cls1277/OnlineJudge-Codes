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
using namespace std;
typedef long long LL;
#define PI acos(-1)
#define INF 2147483647
#define eps 1e-7
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define lowbit(_) _&(-_)
inline LL read() {
	LL x = 0, f = 1;char c = getchar();
	while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
	while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
	return x * f;
}

#define MAXN 50005

LL n , m , f[MAXN][25] , d[MAXN][25] , a[MAXN] , lg[MAXN];

void init() {
//	Ms(d,0x3f);
/*	Fo(i,1,n)
		Fo(j,1,20)
			d[i][j] = INF;*/
	Fo(i,1,n) f[i][0] = d[i][0] = a[i];
	for(int i=1; (1<<i)<=n; i++)
		for(int j=1; j+(1<<i-1)<=n; j++) {
			f[j][i] = max(f[j][i-1] , f[j+(1<<i-1)][i-1]);
			d[j][i] = min(d[j][i-1] , d[j+(1<<i-1)][i-1]);	
		}
	Fo(i,1,n) lg[i] = log2(i);
}

LL query(LL l , LL r) {
	LL k = lg[r-l+1];
	return max(f[l][k] , f[r-(1<<k)+1][k])-min(d[l][k] , d[r-(1<<k)+1][k]);
}

int main() {
//	freopen("data.txt","r",stdin);
	n=read(); m=read();
	Fo(i,1,n) a[i]=read();
	init();
	Fo(i,1,m) {
		LL l , r;
		l=read(); r=read();
		printf("%lld\n",query(l,r));
	}
	return 0;
}

