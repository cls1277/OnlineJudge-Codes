//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define INF 2147483647
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define ls x<<1
#define rs x<<1|1
#define endl '\n'

const LL maxn = 2e5+5;
#define pii pair<LL,LL>
LL n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        cin>>n>>m; LL ans=0;
        vector<pair<pii,LL>>a,b;
        Fo(i,1,m) {
            LL x, y; cin>>x>>y;
            a.push_back({{y,x},i});
        }
        sort(a.begin(), a.end());
        n<<=1;
        for(int i=0; i<n; i++) {
            b.push_back({{a[i].first.second, a[i].first.first},a[i].second});
            ans += a[i].first.first;
        }
        sort(b.begin(), b.end());
        cout<<ans<<endl;
        n>>=1;
        for(int i=0; i<n; i++)
            cout<<b[i].second<<" "<<b[2*n-1-i].second<<endl;
        cout<<endl;
    }
    return 0;
}