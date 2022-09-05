//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 3e5+5;
const LL mod = 998244353;
LL p[maxn], q[maxn], s[maxn<<1], n, b[maxn], c[maxn], f[2][maxn<<1], e[maxn], g[maxn];
pair<LL, LL> a[maxn], d[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        cin>>n;
        Fo(i,1,n) {
            LL x; cin>>x;
            p[i] = a[i].first = x;
            a[i].second = i;
        }
        Fo(i,1,n) {
        	LL x; cin>>x;
        	q[i] = d[i].first = x;
        	d[i].second = i;
		}
        Fo(i,1,2*n) cin>>s[i];
        sort(a+1, a+n+1);
        sort(d+1, d+n+1);
        Fo(i,1,n) {
        	b[i] = a[i].first;	
        	e[i] = d[i].first;
		}
        Fo(i,1,2*n) {
        	c[i] = lower_bound(b+1, b+n+1, s[i])-b;	
			g[i] = lower_bound(e+1, e+n+1, s[i])-e;
		}
		f[0][0] = f[0][1] = 1;
		Fo(i,1,2*n) {
			LL x, y;
			x = c[i], y = i-x;
			if(y>=0) {
				if(!x) f[i&1][x] = 1;
				else f[i&1][x] = f[(i-1)&1][x-1];
			}
			LL tmpx = x, tmpy = y;
			y = g[i], x = i-y;
			if(x==tmpx&&y==tmpy) continue;
			if(x>=0) f[i&1][x] = f[(i-1)&1][x];
		}
        cout<<f[0][n]<<endl;
    }
    return 0;
}
