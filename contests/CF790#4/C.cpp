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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    int t; cin>>t;
    while(t--) {
        int n, m; cin>>n>>m;
        vector<string> a(n);
        Fo(i,0,n-1) cin>>a[i];
        LL ans = INT_MAX;
        Fo(i,0,n-1) {
            Fo(j,i+1,n-1) {
                LL res = 0;
                Fo(k,0,m) {
                    res += abs(a[i][k]-a[j][k]);
                }
                ans = min(ans, res);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}