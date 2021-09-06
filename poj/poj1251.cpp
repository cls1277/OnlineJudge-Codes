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

//const LL maxn = ;
struct Edge {
	int from , to , val;
	bool operator < (const Edge &a) const {
		return val<a.val;
	}
};
Edge e[1005];
int n , m , ans , fa[30] , cnt;

int find(int x) {
	if(fa[x]!=x)
		fa[x] = find(fa[x]);
	return fa[x];
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	while(cin>>n&&n) {
		cnt=0; ans=0; m=0; Ms(fa,0);
		Fo(i,1,n-1) {
			char ch; cin>>ch;
			int id1 = ch-'A';
			int k; cin>>k;
			Fo(j,1,k) {
				char op; cin>>op;
				int id2 = op-'A';
				int len; cin>>len;
				e[++cnt].from=id1;
				e[cnt].to=id2;
				e[cnt].val=len;
			}
		}
		sort(e+1,e+cnt+1);
		Fo(i,1,n) fa[i]=i;
		Fo(i,1,cnt) {
			if(m==n-1) break;
			int u = e[i].from , v = e[i].to , fu , fv;
			fu = find(u); fv = find(v);
			if(fu!=fv) {
				m++;
				fa[fu] = fv;
				ans += e[i].val;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

