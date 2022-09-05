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
        LL n, m1, m2; cin>>n>>m1>>m2;
        vector<LL> a(n+1, 0);
        Fo(i,1,m1) {
            LL x, y, z; cin>>x>>y>>z;
            if(z) a[x]++;
            else a[y]++;
        }
        queue<pair<LL, LL>> q;
        Fo(i,1,m2) {
            LL x, y; cin>>x>>y;
            q.push({x, y});
        }
        while(!q.empty()) {
            pair<LL, LL> u = q.front(); q.pop();
            LL x = u.first, y = u.second;
            if(x==1||y==1) a[1]++;
            else {
                if(a[x]<a[y]) a[x]++;
                else if(a[x]>a[y]) a[y]++;
                else q.push(u);
            }
        }
        LL mx = 0;
        Fo(i,1,n) mx = max(mx, a[i]);
        if(a[1]==mx) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}