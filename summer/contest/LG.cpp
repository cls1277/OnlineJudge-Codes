//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 1e6+5;
struct Seg {
    LL l, r, w;
}a[maxn];
LL n, m, r, f[maxn<<1];
map<LL, LL> mp;

bool operator < (const Seg &x, const Seg &y) {
    return x.r<y.r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>m>>r;
	Fo(i,1,m) {
		cin>>a[i].l>>a[i].r>>a[i].w;
		a[i].r += r;	
	}
    sort(a+1, a+m+1);
    LL j=1;
    Fo(i,1,n) {
        f[i] = f[i-1];
        while(j<=m&&i==a[j].r) {
            f[i] = max(f[i], f[a[j].l]+a[j].w);
            j++;
        }
    }
    cout<<f[n];
    return 0;
}
