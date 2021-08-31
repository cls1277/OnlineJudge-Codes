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

const LL maxn = 5005;
struct Pair {
	int x , y;
};
Pair a[maxn] , ans[maxn];
int n , m , cnt;

bool operator < (const Pair &x , const Pair &y) {
	if(x.y==y.y) return x.x<y.x;
	return x.y>y.y;
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>n>>m;
	Fo(i,1,n) cin>>a[i].x>>a[i].y;
	m = floor(m*1.5);
	sort(a+1,a+n+1);
	Fo(i,1,m) ans[i]=a[i],cnt++;
	Fo(i,m+1,n)
		if(a[i].y==a[m].y)
			ans[i]=a[i],cnt++;
		else break;
	cout<<a[m].y<<" "<<cnt<<endl;
	Fo(i,1,cnt)
		cout<<ans[i].x<<" "<<ans[i].y<<endl;
	return 0;
}

