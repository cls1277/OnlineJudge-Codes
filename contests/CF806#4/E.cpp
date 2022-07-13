//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

//const LL maxn = ;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        LL n; cin>>n;
        vector<string> mp;
        Fo(i,1,n) {
            string str; cin>>str;
            mp.push_back(str);
        }
        LL ans = 0;
        for(int i=0; i<(n+1)/2; i++) {
            for(int j=0; j<n/2; j++) {
                LL x = (mp[i][j]-'0')+(mp[j][n-i-1]-'0')+(mp[n-i-1][n-j-1]-'0')+(mp[n-j-1][i]-'0');
                ans += min(x, 4-x);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}