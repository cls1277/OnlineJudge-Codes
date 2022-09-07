//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

//const LL maxn = ;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL T; cin>>T;
    while(T--) {
        LL ans = 0;
        LL n; cin>>n;
        vector<LL> a(n+2, 0);
        Fo(i,1,n) cin>>a[i];
        LL p = 1;
        while(p<=n) {
            if(a[p]==p) p++;
            else {
                LL mx = max(a[p], a[p+1]);
                LL p2 = p+1;
                while(p2 < mx) {
                    p2++;
                    mx = max(mx, a[p2]);
                }
                ans += p2-p+1;
                p = p2+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}