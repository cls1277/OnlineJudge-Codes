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
LL sum[maxn];

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
        Fo(i,1,n) cin>>a[i];
        sort(a.begin()+1, a.begin()+n+1);
        Fo(i,1,n) sum[i]=sum[i-1]+a[i];
        LL ans = 0;
        Fo(i,1,n) {
            LL y = x-sum[i-1], res = 0;
            // while(y>0) {
            //     if(y>=a[i]) {
            //         a[i]++;
            //         y-=i-1;
            //         res++;
            //     } else break;
            // }
            if(y>=a[i]) res = (y-a[i])/i+1;
            ans += res;
        }
        Fo(i,1,n) sum[i]=0;
        cout<<ans<<endl;
    }
    return 0;
}
