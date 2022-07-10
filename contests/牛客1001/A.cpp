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
LL n, m, a[maxn], b[maxn], idx, ans;
unordered_map<LL, LL> cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n;
    Fo(i,1,n) {
        LL x; cin>>x;
        cnt[x]++;
    }
    cin>>m;
    Fo(i,1,m) {
        cin>>a[i];
    }
    Fo(i,1,m) {
        cin>>b[i];
    }
    Fo(i,1,m) {
        if(cnt[a[i]]>ans) {
            idx = i;
            ans = cnt[a[i]];
        } else if(cnt[a[i]]==ans) {
            if(cnt[b[i]]>cnt[b[idx]]) {
                idx = i;
            }
        }
    }
    cout<<idx;
    return 0;
}