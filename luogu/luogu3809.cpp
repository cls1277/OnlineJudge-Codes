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

const LL maxn = 1e6+5;
char str[maxn];
int n , m , rk[maxn<<1] , prk[maxn<<1] , sa[maxn] , id[maxn] , sum[maxn];

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	scanf("%s",str+1);
	n=strlen(str+1), m=max(n,127);
	Fo(i,1,n) sum[rk[i]=str[i]]++;
	Fo(i,1,m) sum[i]+=sum[i-1];
	Ro(i,n,1) sa[sum[rk[i]]--]=i;
	for(int w=1; w<n; w<<=1) {
		Ms(sum,0);
		Fo(i,1,n) id[i]=sa[i];
		Fo(i,1,n) sum[rk[id[i]+w]]++;
		Fo(i,1,m) sum[i]+=sum[i-1];
		Ro(i,n,1) sa[sum[rk[id[i]+w]]--]=id[i];
		Ms(sum,0);
		Fo(i,1,n) id[i]=sa[i];
		Fo(i,1,n) sum[rk[id[i]]]++;
		Fo(i,1,m) sum[i]+=sum[i-1];
		Ro(i,n,1) sa[sum[rk[id[i]]]--]=id[i];
		memcpy(prk,rk,sizeof(rk));
		int p=0;
		Fo(i,1,n) {
			if(prk[sa[i]]==prk[sa[i-1]]&&prk[sa[i]+w]==prk[sa[i-1]+w])
				rk[sa[i]]=p;
			else rk[sa[i]]=++p;
		}
	}
	Fo(i,1,n) printf("%d ",sa[i]);
	return 0;
}

