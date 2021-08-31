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

const LL maxn = 2e5+5;
map<LL,bool>vis;
map<LL,LL>cnt;
LL n , c , a[maxn] , ans;

bool cmp(LL x , LL y) {
	return x>y;
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>n>>c;
	Fo(i,1,n) cin>>a[i],cnt[a[i]]++;
	sort(a+1,a+n+1,cmp);
	//cout<<a[1];
	Fo(i,1,n) {
		if(vis[a[i]]) continue;
		ans+=cnt[a[i]]*cnt[a[i]-c];
		if(cnt[a[i]]&&cnt[a[i]-c]) vis[a[i]] = 1;
	}
	cout<<ans;
	return 0;
}

