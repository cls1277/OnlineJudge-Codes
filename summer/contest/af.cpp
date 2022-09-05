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
LL n, m, f[maxn<<1], g[maxn<<1];
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
//        mp[i-x+1] = mp[i+x-1] = 1;
        a[i].l = i-x+1; a[i].r = i+x;
    }
    Fo(i,1,n) {
        cin>>a[i].w;
        a[i].w *= a[i].r-i;
    }
//    for(auto it:mp) mp[it.first] = ++m;
//    Fo(i,1,n) {
//        a[i].l = mp[a[i].l];
//        a[i].r = mp[a[i].r];
//    }
    sort(a+1, a+n+1);
    LL ans = 0;
    Fo(i,1,n) {
    	f[i] = a[i].w;
    	Fo(j,1,i-1) {
    		if(a[i].l>=a[j].r)
    			f[i] = max(f[i], f[j]+a[i].w);
		}
		ans = max(ans, f[i]);
	}
	cout<<ans; 
//    a[0].r = -1;
//    Fo(i,1,n) {
//    	LL l=0, r=i-1, mid;
//    	while(l<r) {
//    		mid = (l+r+1)>>1;
//    		if(a[mid].r<=a[i].l) l=mid;
//    		else r=mid-1;
//		}
//		if(a[r].r<=a[i].l) g[i]=f[r]+a[i].w;
//		else g[i]=a[i].w;
//		f[i] = max(f[i-1], g[i]);
//	} 
//    cout<<f[n];
    return 0;
}
