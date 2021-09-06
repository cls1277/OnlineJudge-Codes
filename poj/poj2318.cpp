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
int x1 , x2 , qnmd , y2 , n , m , u[maxn] , d[maxn] , ans[maxn];

bool jud(int x , int a , int b) {
	return (u[x]-a)*(y2-b)-(d[x]-a)*(qnmd-b)<=0;
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	while(cin>>n) {
		Ms(ans,0);
		if(!n) break;
		cin>>m>>x1>>qnmd>>x2>>y2;
		Fo(i,0,n-1)
			cin>>u[i]>>d[i];
		Fo(i,1,m) {
			int x , y;
			cin>>x>>y;
			int l=0 , r=n , mid;
			while(l<r) {
				mid = (l+r)>>1;
				if(jud(mid,x,y)) r=mid;
				else l = mid+1;
			}
			ans[l]++;
		}
		Fo(i,0,n)
			cout<<i<<": "<<ans[i]<<endl;
		cout<<endl;
	}
	return 0;
}

