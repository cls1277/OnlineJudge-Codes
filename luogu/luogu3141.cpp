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

const LL maxn = 3e5+5;
LL n , m , a[maxn] , b[maxn] , A , B , p1 , p2 , row , col , ans , x[maxn] , y[maxn];

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>A>>B>>n>>m;
	Fo(i,1,n) cin>>a[i];
	Fo(i,1,m) cin>>b[i];
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	x[n+1] = A-a[n]; y[m+1] = B-b[m];
	Fo(i,1,n) x[i]=a[i]-a[i-1];
	Fo(i,1,m) y[i]=b[i]-b[i-1];
	n++; m++;
	sort(x+1,x+n+1); sort(y+1,y+m+1);
	ans=x[1]*(m-1)+y[1]*(n-1);
	p1=p2=2; row=col=1;
	while(p1<=n&&p2<=m) {
		if(x[p1]<=y[p2]) ans+=x[p1]*(m-row),p1++,col++;
		else ans+=y[p2]*(n-col),p2++,row++;
	}
	cout<<ans;
	return 0;
}

