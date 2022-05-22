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
vector<pair<int, int>> c[maxn];
map<pair<int, int>, bool> used;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        LL n, x; cin>>n>>x;
        vector<LL> a(n+5);
        LL ans = 0;
        Fo(i,1,n) {
            cin>>a[i];
            ans += abs(a[i]-a[i-1]);
        }
        cout<<ans<<endl;
    }
    return 0;
}