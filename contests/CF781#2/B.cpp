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
    LL t; cin>>t;
    while(t--) {
        LL n, mx=0; cin>>n;
        map<LL, LL>cnt;
        Fo(i,1,n) {
            LL x; cin>>x;
            cnt[x]++;
            mx = max(mx, cnt[x]);
        }
        LL x=mx, ans=0;
        while(x<n) {
            ans++;
            LL temp = x;
            x<<=1;
            if(x>n) ans+=n-temp;
            else ans+=temp;
            // cout<<ans<<' '<<x<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}