//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 3e5+5;
LL n, k, a[maxn], f[maxn];
bool vis[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        cin>>n>>k;
        Fo(i,1,n) {
            vis[i] = 0;
            f[i] = 0;
        }
        Fo(i,1,n) cin>>a[i];
        LL cnt = 0;
        while(cnt<min(n+1, k)) {
            Fo(i,1,n-1) {
                if(vis[i]) continue;
                bool flag = 0;
                for(LL j=1; i+j<=n; j++) {
                    if(vis[i+j]) continue;
                    if(a[i+j]>a[i]) {
                        cnt++;
                        flag = 1;
                        vis[i] = 1;
                    }
                    break;
                }
                if(flag) break;
            }
        }
        // Fo(i,1,n) cout<<vis[i]<<' ';
        // cout<<endl;
        vector<LL> b, c;
        Fo(i,1,n) {
            if(!vis[i]) b.push_back(a[i]);
            else c.push_back(a[i]);
        }
        LL m = b.size()-1;
        f[m] = b[m];
        Ro(i,m-1,0) {
            f[i] = max(f[i+1], b[i]);
        }
        // Fo(i,0,m) cout<<f[i]<<' ';
        // cout<<endl;
        unordered_map<LL, multiset<LL, greater<LL>>> ans;
        for(auto it:c) {
            LL idx = upper_bound(f+m+1, f+1, it)-f;
            // cout<<it<<'-'<<idx<<' ';
            ans[idx].insert(it);
        }
        // cout<<endl;
        for(LL i=0; i<=m; i++) {
            cout<<b[i]<<' ';
            for(auto it2:ans[i]) {
                cout<<it2<<' ';
            }
        }
        for(auto it2:ans[m+1]) {
            cout<<it2<<' ';
        }
        cout<<endl;
    }
    return 0;
}