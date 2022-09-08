//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 105;
const LL maxm = 31;
LL n, a[maxn], ans, p[maxn];

bool insert(LL x) {
    Ro(i,maxm,0) {
        if(x&(1LL<<i)) {
            if(!p[i]) {
                p[i] = x;
                return 1;
            } else {
                x ^= p[i];
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n;
    Fo(i,1,n) cin>>a[i];
    sort(a+1, a+n+1);
    Ro(i,n,1) {
        if(!insert(a[i])) {
            ans += a[i];
        }
    }
    cout<<ans;
    return 0;
}