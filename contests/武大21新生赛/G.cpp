//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 1e3+5;
LL n, a[maxn], idx;
unordered_map<LL, LL>mp;

bool  isprime(LL x) {
    Fo(i,2,sqrt(x)) {
        if(x%i==0)
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n;
    Fo(i,1,n) {
        cin>>a[i];
        mp[a[i]] = i;
    }
    LL mx;
    Ro(i,n,2) {
        if(isprime(i)) {
            mx = i;
            idx = mp[mx];
            break;
        }
    }
    LL ans = 0;
    vector<pair<LL, LL>>res;
    Fo(i,1,n-1) {
        if(i+1==mx) continue;
        if(a[i]==i+1) continue;
        if(idx!=i) {
            ans++;
            res.push_back({idx, i});
            LL temp = idx;
            idx = i; mp[a[i]] = temp; a[temp] = a[i]; a[idx] = mx;
        }
        if(idx!=mp[i+1]) {
            ans++;
            res.push_back({idx, mp[i+1]});
            LL temp = idx;
            idx = mp[i+1]; mp[i+1] = temp; a[temp] = i+1; a[idx] = mx;
        }
    }
    cout<<ans<<endl;
    for(auto it:res) cout<<it.first<<' '<<it.second<<endl;
    return 0;
}