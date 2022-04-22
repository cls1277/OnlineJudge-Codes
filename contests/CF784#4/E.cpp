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
LL n, a[2][15];
map<string, int>mp;
vector<string>v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        mp.clear();
        v.clear();
        LL ans = 0;
        cin>>n; string str;
        Ms(a, 0);
        Fo(i,1,n) {
            cin>>str; mp[str]++;
            if(mp[str]==2) v.push_back(str);
            a[0][str[0]-'a']++;
            a[1][str[1]-'a']++;
        }
        Fo(i,0,10) {
            ans += (a[0][i]-1)*a[0][i]/2;
            ans += (a[1][i]-1)*a[1][i]/2;
        }
        for(auto i:v) {
            ans -= mp[i]*(mp[i]-1);
        }
        cout<<ans<<endl;
    }
    return 0;
}