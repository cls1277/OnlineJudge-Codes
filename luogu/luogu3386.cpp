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

const LL maxn = 505;
int n , m , e , a[maxn][maxn] , b[maxn] , ans;
bitset<maxn>vis;

bool jud(int x) {
	Fo(i,1,m)
		if(a[x][i]&&!vis[i]) {
			vis[i] = 1;
			if(!b[i]||jud(b[i])) {
				b[i] = x;
				return 1;
			}
		}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>n>>m>>e;
	Fo(i,1,e) {
		int x , y;
		cin>>x>>y;
		a[x][y] = 1;
	}
	Fo(i,1,n) {
		vis.reset();
		if(jud(i))
			ans++;
	}
	cout<<ans;
	return 0;
}

