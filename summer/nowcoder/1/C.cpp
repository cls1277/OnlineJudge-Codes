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
    LL n, m, k, q; cin>>n>>m>>k>>q;
    vector<set<LL>> a(m+1);
    vector<pair<LL, LL>> b(k+1);
    Fo(i,1,k) {
        LL x, y; cin>>x>>y;
        b[i] = {x, y};
        a[y].insert(x);
    }
    while(q--) {
        vector<LL> ans(m+1, 0);
        LL id, x, y; cin>>id>>x>>y;
        a[b[id].second].erase(b[id].first);
        b[id] = {x, y};
        a[y].insert(x);
        Fo(i,1,m) {
            if(!a[i].size()) ans[i] = n;
            else ans[i] = (*a[i].begin())-1;
        }
        double mx = 0;
        Fo(i,2,m) {
            if(mx) ans[i] = (int)min((double)ans[i], (i-1)*1.0/mx-(1e-6));
            if(!a[i].size()) continue;
            double k = (i-1)*1.0/(*a[i].begin());
            mx = max(mx, k);
        }
        mx = 0;
        Ro(i,m-1,1) {
            if(mx) ans[i] = (int)min((double)ans[i], (i-m)*1.0/mx-(1e-6));
            if(!a[i].size()) continue;
            double k = (i-m)*1.0/(*a[i].begin());
            mx = min(mx, k);
        }
        LL res = 0;
        Fo(i,1,m) res+=ans[i];
        cout<<res<<endl;
    }
    return 0;
}
