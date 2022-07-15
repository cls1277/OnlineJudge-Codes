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
LL n, m, cnt[maxn];

bool judge(LL x) {
    LL res = n*x, est = 0;
    Fo(i,1,n) {
        // if(!cnt[i]) continue;
        if(cnt[i]<x) {
            if((x-cnt[i])&1) res -= cnt[i]+1;
            else res -= cnt[i];
        } else {
            res -= x;
            est += (cnt[i]-x)*2;
        }
    }
    return (res>=est);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        cin>>n>>m;
        Fo(i,1,n) cnt[i] = 0;
        Fo(i,1,m) {
            LL x; cin>>x;
            cnt[x]++;
        }
        LL l=1, r=2*m;
        while(l<r) {
            LL mid = (l+r)>>1;
            if(judge(mid)) r = mid;
            else l = mid+1;
        }
        cout<<l<<endl;
    }
    return 0;
}