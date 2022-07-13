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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);   
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        LL n; cin>>n;
        string str; cin>>str;
        LL cnt[30]; Ms(cnt, 0);
        for(int i=0; i<str.length(); i++) {
            cnt[str[i]-'A']++;
        }
        LL ans = 0;
        Fo(i,0,25) {
            if(!cnt[i]) continue;
            ans += cnt[i]+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}