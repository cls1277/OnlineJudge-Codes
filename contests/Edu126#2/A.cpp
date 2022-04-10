//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 30;
LL n, a[maxn], b[maxn], c[maxn], d[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        cin>>n;
        LL ans = 0;
        Fo(i,1,n) cin>>a[i], c[i]=a[i];
        Fo(i,1,n) cin>>b[i], d[i]=b[i];
        Fo(i,2,n)
            if(abs(b[i]-a[i-1])+abs(a[i]-b[i-1])<abs(b[i]-b[i-1])+abs(a[i]-a[i-1]))
                swap(a[i], b[i]);
        Fo(i,1,n-1) ans+=abs(a[i+1]-a[i]);
        Fo(i,1,n-1) ans+=abs(b[i+1]-b[i]);
        swap(c[1], d[1]);
        LL res = 0;
        Fo(i,2,n)
            if(abs(d[i]-c[i-1])+abs(c[i]-d[i-1])<abs(d[i]-d[i-1])+abs(c[i]-c[i-1]))
                swap(c[i], d[i]);
        Fo(i,1,n-1) res+=abs(c[i+1]-c[i]);
        Fo(i,1,n-1) res+=abs(d[i+1]-d[i]);        
        cout<<min(ans, res)<<endl;
    }
    return 0;
}