//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 1e5+5;
LL b[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        LL n; cin>>n;
        cout<<n<<endl;
        vector<pair<LL, LL>> a(n+1);
        unordered_map<LL, bool> mp;
        unordered_map<LL, bool> vis;        
        Fo(i,1,n) {
            cin>>a[i].first;
            cout<<a[i].first<<' ';
            mp[a[i].first] = 1;
            a[i].second = i;
        }
        cout<<endl;
        if(mp.size()==1) {
            cout<<"NO"<<endl;
            continue;
        }
        sort(a.begin(), a.end());
        vector<LL> c(n+1, 0);
        Fo(i,1,n) b[i] = a[i].first;
        LL cnt = 0;
        vector<LL> d;
        Fo(i,1,n) {
            if(!mp[i]) {
                d.push_back(i);
                continue;
            }
            LL idx = upper_bound(b+1, b+n+1, i)-b;
            if(idx>n) {
                Fo(j,i,n) d.push_back(j);
                break;
            }
            c[idx] = i;
        }
        LL p = 0;
        Ro(i,n,1) {
            if(c[i]) continue;
            c[i] = d[p];
            if(p==d.size()-1) break;
            p++;
        }
        vector<LL> ans(n+1);
        Fo(i,1,n) ans[a[i].second] = c[i];
        // cout<<"YES"<<endl;
        Fo(i,1,n) cout<<ans[i]<<' ';
        cout<<endl;
    }
    return 0;
}
