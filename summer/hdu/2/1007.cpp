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
        vector<pair<LL, LL>> a(n);
        Fo(i,0,n-1) cin>>a[i].first>>a[i].second;
        sort(a.begin(), a.end());
        LL r=a[0].second, ans=0;
        bool flag = 1;
        Fo(i,1,n-1) {
            if(a[i].first<=r) {
                flag = 0;
                break;
            }
            ans++;
            r = a[i].second;
        }
        if(flag) ans = n;
        cout<<ans<<endl;
    }
    return 0;
}