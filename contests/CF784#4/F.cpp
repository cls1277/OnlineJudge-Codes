//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 2e5+5;
LL c[maxn], b[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        Ms(b, 0);
        Ms(c, 0);
        LL n; cin>>n; LL ans = 0;
        vector<LL> a(n+1);
        Fo(i,1,n) cin>>a[i];
        Fo(i,1,n) b[i]=b[i-1]+a[i];
        reverse(a.begin(), a.end());
        Fo(i,0,n-1) c[i+1]=c[i]+a[i];
        Fo(i,1,n) {
            LL idx = lower_bound(c+1, c+n+1, b[i])-c;
            if(idx+i>n) break;
            if(b[i]!=c[idx]) continue;
            ans = idx+i;
        }
        cout<<ans<<endl;
    }
    return 0;
}