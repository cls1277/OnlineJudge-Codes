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
#define fi first
#define se second
inline LL read() {
	LL x = 0, f = 1;char c = getchar();
	while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
	while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
	return x * f;
}

const LL maxn = 10;
pair<double,double>a[maxn];
double d1 , c , e , d2 , p , ans , d3 , d0 , pm=INF;
int n , now;

int main() {
	//ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>d1>>c>>d2>>p>>n;
	Fo(i,1,n) cin>>a[i].fi>>a[i].se;
	a[0]=make_pair(0,p);
	d3=c*d2;
	Fo(i,1,n)
		if(a[i].first-a[i-1].first>d3) {
			cout<<"No Solution";
			return 0;
		}
	while(d0<d1) {
		for(int i=now+1;a[i].first-d0<=d3&&i<=n; i++) {
			if(pm>a[i].second) {
				pm=a[i].second;
				now=i;
			}
		}
		if(pm<=p) {
			ans+=p*((a[now].first-d0)/d2-e);
			e=(a[now].first-d0)/d2;
		} else if(d1-d0>d3) {
			ans+=(c-e)*p;
			e=c;
		} else {
			ans+=((d1-d0)/d2-e)*p;
			break;
		}
		e=e-(a[now].first-d0)/d2;
		d0=a[now].fi;
		p=pm; pm=INF;
	}
	/*a[n+1].fi=d1-a[n].fi; a[n+1].se=0;
	if(n) {
		if(c*d2<a[1].fi) {
			cout<<"No Solution";
			return 0;
		}
		if(a[1].se<p) ans+=p*(a[1].fi/d2);
		else ans+=p*c;
		Fo(i,1,n) {
			if(c*d2<a[i+1].first-a[i].first) {
				cout<<"No Solution";
				return 0;
			}
			if(a[i+1].se<a[i].se) ans+=a[i].se*((a[i+1].first-a[i].first)/d2);
			else ans+=a[i].se*c;
		}
	}*/
	printf("%.2lf",ans);
	return 0;
}

