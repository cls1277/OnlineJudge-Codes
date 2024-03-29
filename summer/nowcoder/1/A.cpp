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
    LL n; cin>>n;
    vector<pair<LL, LL>> a(n+1);
    Fo(i,1,n) {
        LL x, r; cin>>x>>r;
        a[i] = {x-r, x+r};
    }
    sort(a.begin()+1, a.end());
    LL pre = a[1].second, ans = 0;
    Fo(i,2,n) {
        if(a[i].first>pre) {
            ans += a[i].first-pre;
        }
        pre = max(pre, a[i].second);
    }
    cout<<ans;
    return 0;
}