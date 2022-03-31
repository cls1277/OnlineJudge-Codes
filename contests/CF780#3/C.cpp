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
char s[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        cin>>(s+1);
        map<char, LL>pre;
        LL n = strlen(s+1), last = 0;
        LL ans = 0;
        Fo(i,1,n) {
            char c = s[i];
            if(pre[c]) {
                ans += pre[c]-last-1;
                ans += i-pre[c]-1;
                last = i;
                pre.clear();
            } else pre[c] = i;
        }
        cout<<ans+n-last<<endl;
    }
    return 0;
}