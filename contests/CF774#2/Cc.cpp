//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

// const LL maxn = 1e12;
LL a[15]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200};

LL count(LL x) {
    LL res = 0;
    while(x) {
        res += (x&1);
        x>>=1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        LL n; cin>>n; LL ans = INT_MAX;
        Fo(i,0,(1<<15)-1) {
            LL m = n, idx = 0, cnt = 0, tmp = i;
            while(tmp) {
                if(tmp&1==1) {
                    cnt++;
                    m -= a[idx];
                }
                idx++;
                tmp>>=1;
            }
            if(m<0) continue;
            ans = min(ans, cnt+count(m));
        }
        cout<<ans<<endl;
    }
    return 0;
}