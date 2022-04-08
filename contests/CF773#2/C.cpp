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
LL n, x, a[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        LL ans = 0;
        cin>>n>>x;
        set<LL>s;
        map<LL, LL>cnt;
        Fo(i,1,n) {
            cin>>a[i];
            cnt[a[i]]++;
            s.insert(a[i]);
        }
        for(auto it:s) {
            if(!cnt[it]) continue;
            if(cnt[it]<=cnt[it*x]) {
                cnt[it*x]-=cnt[it];
            } else {
                ans += cnt[it]-cnt[it*x];
                cnt[it*x]=0;
                cnt[it]-=cnt[it*x];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}