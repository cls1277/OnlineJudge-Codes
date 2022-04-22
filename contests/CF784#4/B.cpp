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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t, n; cin>>t;
    while(t--) {
        map<int, int>cnt;
        cin>>n;
        LL ans = -1;
        Fo(i,1,n) {
            int x;
            cin>>x;
            cnt[x]++;
            if(cnt[x]>=3&&ans==-1) {
                ans = x;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}