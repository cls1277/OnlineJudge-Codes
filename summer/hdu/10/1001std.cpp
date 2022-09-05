//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 505;
LL n, m2, cc[maxn<<1], a[maxn];
pair<LL, LL> b[maxn<<1];
bool flag;

void dfs(LL x, LL c[]) {
    if(flag) return ;
    if(x==m2+1) {
        vector<LL> d(n+1, 0);
        Fo(i,1,m2) {
            if(c[i]==1) d[b[i].first]++;
            else d[b[i].second]++;
        }
        LL mx = 0;
        Fo(i,1,n) mx = max(mx, a[i]+d[i]);
        if(a[1]+d[1]==mx) flag = 1;
        return ;
    }
    c[x] = 1;
    dfs(x+1, c);
    c[x] = 2;
    dfs(x+1, c);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        flag = 0;
        LL m1; cin>>n>>m1>>m2;
        Fo(i,1,n) a[i]=0;
        Fo(i,1,m1) {
            LL x, y, z; cin>>x>>y>>z;
            if(z) a[x]++;
            else a[y]++;
        }
        Fo(i,1,m2) cin>>b[i].first>>b[i].second;
        dfs(1, cc);
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}