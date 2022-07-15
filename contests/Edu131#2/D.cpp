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
    LL t; cin>>t;
    while(t--) {
        LL n; cin>>n;
        vector<vector<pair<LL, LL>>> a(n+1);
        vector<LL> ans(n+1);
        Fo(i,1,n) {
            LL x; cin>>x;
            LL l, r;
            if(!x) {
                l = i+1;
                r = n;
            } else {
                l = i/(x+1)+1;
                r = i/x;
            }
            a[l].push_back({r, i});
        }
        set<pair<LL, LL>> s;
        Fo(i,1,n) {
            for(auto it:a[i]) s.insert(it);
            ans[s.begin()->second] = i;
            s.erase(s.begin());
        }
        Fo(i,1,n) cout<<ans[i]<<' ';
        cout<<endl;
    }
    return 0;
}