//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 1e5+5;
struct Seg {
	LL l, r, w;
}a[maxn];
pair<LL, LL> b[maxn];
LL n, f[maxn], c[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n;
    Fo(i,1,n) {
    	LL x; cin>>x;
    	a[i].l = i-x;
    	a[i].r = i+x;
    	b[i] = {i+x, i};
	}
	Fo(i,1,n) cin>>a[i].w;
	sort(b+1, b+n+1);
	Fo(i,1,n) c[i] = b[i].first;
	Fo(i,1,n) {
		LL idx = upper_bound(c+1, c+n+1, i)-c-1;
		Fo(j,1,idx) f[i] = max(f[i], f[a[b[j].second].l-1]+a[b[j].second].w);
	}
	cout<<f[n];
    return 0;
}
