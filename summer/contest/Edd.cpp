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
LL n, m, f[maxn<<1];
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
    cin>>n;
    Fo(i,1,n) {
        LL x; cin>>x;
        mp[i-x] = mp[i+x-1] = 1;
        a[i].l = i-x; a[i].r = i+x-1;
    }
    Fo(i,1,n) {
        cin>>a[i].w;
        a[i].w *= a[i].r-i+1;
    }
    for(auto it:mp) mp[it.first] = ++m;
    Fo(i,1,n) {
        a[i].l = mp[a[i].l];
        a[i].r = mp[a[i].r];
    }
    sort(a+1, a+n+1);
    LL j=1;
    Fo(i,1,m) {
        f[i] = f[i-1];
        while(j<=n&&i==a[j].r) {
            f[i] = max(f[i], f[a[j].l]+a[j].w);
            j++;
        }
    }
    cout<<f[m];
    return 0;
}
