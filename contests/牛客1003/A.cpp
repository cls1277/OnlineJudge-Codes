//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

// const LL maxn = ;
LL n, L, ans;
vector<pair<LL, LL>> a, b;

bool cmp(pair<LL, LL> x, pair<LL, LL> y) {
    return (x.first>y.first);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>L;
    Fo(i,1,n) {
        LL x, y; cin>>x>>y;
        a.push_back({x, y});
    }
    Fo(i,1,L) {
        LL x, y; cin>>x>>y;
        b.push_back({x, y});
    }
    sort(a.begin(), a.end(), cmp);
    for(auto it:a) {
        LL idx = -1, res = -1;
        for(int i=0; i<b.size(); i++) {
            auto it2 = b[i];
            if(!it2.second) continue;
            if(it2.first>=it.first&&it2.first<=it.second) {
                if(it2.first > res) {
                    res = it2.first;
                    idx = i;
                }
            }
        }
        if(idx!=-1) {
            ans++;
            b[idx].second--;
        }
    }
    cout<<ans;
    return 0;
}