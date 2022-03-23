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
LL n, d, a[maxn];

bool judge(LL x) {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL  t; cin>>t;
    while(t--) {
        cin>>n>>d;
        Fo(i,1,n) cin>>a[i];
        LL l=0, r=d;
        while(l<r) {
            LL mid=(l+r+1)>>1;
            if(judge(mid)) l=mid;
            else r=mid-1;
            cout<<mid<<" "<<judge(mid)<<endl;
        }
        cout<<l<<endl;
    }
    return 0;
}