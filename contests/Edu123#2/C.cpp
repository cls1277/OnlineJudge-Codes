//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 5e3+5;
LL a[maxn], sum[maxn], f[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        LL n, x; cin>>n>>x;
        Fo(i,1,n) f[i] = -INT_MAX, sum[i]=0;
        Fo(i,1,n) {
            cin>>a[i];
            sum[i]=sum[i-1]+a[i];
        }
        Fo(len,1,n) 
            Fo(l,1,n) {
                LL r = l+len-1;
                if(r>n) break;
                f[len] = max(f[len], sum[r]-sum[l-1]);
            }
        Fo(i,0,n) {
            LL ans = 0;
            Fo(len,1,n)
                ans = max(ans, f[len]+min(i, len)*x);
            cout<<ans<<' ';
        }
        cout<<endl;
    }
    return 0;
}