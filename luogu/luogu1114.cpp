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
    vector<LL> a(n+1);
    Fo(i,1,n) {
        cin>>a[i];
        if(!a[i]) a[i] = -1;
    }
    vector<LL> sum(n+1, 0);
    unordered_map<LL, vector<LL>> mp;
    mp[0].push_back(0);
    Fo(i,1,n) {
        sum[i] = sum[i-1]+a[i];
        // cout<<sum[i]<<' ';
        mp[sum[i]].push_back(i);
    }
    LL ans = 0;
    for(auto it:mp) {
        ans = max(ans, it.second[it.second.size()-1]-it.second[0]);
    }
    cout<<ans;
    return 0;
}