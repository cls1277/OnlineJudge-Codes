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

const LL maxn = 1e3+5;
LL f[maxn], n, x, l[maxn], w[maxn], u[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>x;
    Fo(i,1,n) cin>>l[i]>>w[i]>>u[i];
    // Fo(i,0,x) {
    //     Fo(j,1,n) {
    //         if(i>=u[j]) f[i]=max(f[i]+l[j], f[i-u[j]]+w[j]);
    //         else f[i]+=l[j];
    //     }
    // }
    Fo(i,1,n)
        Ro(j,x,0) {
            if(j>=u[i]) f[j]=max(f[j]+l[i], f[j-u[i]]+w[i]);
            else f[j]+=l[i];
        }
    cout<<f[x]*5;
    return 0;
}