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

LL  ans;

void build(LL x, LL l, LL r) {
    ans = max(ans, x);
    if(l==r) return;
    LL mid = (l+r)>>1;
    build(x<<1, l, mid);
    build(x<<1|1, mid+1, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    Fo(i,2047,2049) {
        ans = 0;
        cout<<i<<": ";
        build(1, 1, i);
        cout<<ans<<endl;
    }
    return 0;
}