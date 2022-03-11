//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define INF 2147483647
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define ls x<<1
#define rs x<<1|1
#define endl '\n'

const LL maxn = 2e5+5;
LL a[maxn], b[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        LL n; cin>>n;
        Fo(i,1,n) cin>>a[i];
        Fo(i,1,n) cin>>b[i];
        LL c0=INF, c1=INF, c2=INF, c3=INF;
        Fo(i,1,n) {
            c0 = min(c0, abs(a[1]-b[i]));
            c1 = min(c1, abs(a[n]-b[i]));
            c2 = min(c2, abs(b[1]-a[i]));
            c3 = min(c3, abs(b[n]-a[i]));
        }
        LL ans = min({c0+c1+c2+c3,abs(a[1]-b[n])+c1+c2,abs(a[n]-b[1])+c0+c3,abs(a[1]-b[1])+c3+c1,abs(a[n]-b[n])+c0+c2,abs(a[n]-b[1])+abs(a[1]-b[n]),abs(a[1]-b[1])+abs(a[n]-b[n])});
        cout<<ans<<endl;
    }
    return 0;
}