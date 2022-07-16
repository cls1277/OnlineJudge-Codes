//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 45;
LL n, c, q, b[maxn];
string str;
pair<LL, LL> a[maxn];

char dfs(LL x) {
    if(x-1<str.length()) return str[x-1];
    LL idx = lower_bound(b, b+c+1, x)-b;
    if(!idx) return str[x-1];
    return dfs(x-b[idx-1]+a[idx].first-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        cin>>n>>c>>q>>str;
        Fo(i,1,c) cin>>a[i].first>>a[i].second;
        b[0] = str.length();
        Fo(i,1,c) {
            LL len = a[i].second-a[i].first+1;
            b[i] = b[i-1]+len;
        }
        Fo(i,1,q) {
            LL x; cin>>x;
            cout<<dfs(x)<<endl;
        }
    }
    return 0;
}