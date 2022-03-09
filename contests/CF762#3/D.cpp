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

const LL maxn = 1e5+5;
LL m, n;
vector<LL>a[maxn];

bool check(LL x) {
    Fo(i,0,n-1) {
        LL cnt = 0;
        Fo(j,1,m)
            if(a[j][i]>=x)
                cnt++;
        if(!cnt) return false;
    }
    Fo(i,1,m) {
        LL cnt = 0;
        Fo(j,0,n-1)
            if(a[i][j]>=x)
                cnt++;
        if(cnt>=2) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        cin>>m>>n;
        LL l=0,r=0,ans;
        Fo(i,1,m)
            Fo(j,1,n) {
                LL x; cin>>x;
                a[i].push_back(x);
                r=max(r,x);
            }
        while(l<=r) {
            LL mid=(l+r)>>1;
            // cout<<mid<<endl;
            if(check(mid)) {
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        cout<<ans<<endl;
        Fo(i,1,m) a[i].clear();
    }
    return 0;
}