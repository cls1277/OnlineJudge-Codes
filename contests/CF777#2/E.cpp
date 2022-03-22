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
LL n, a[maxn], ind[maxn], fa[maxn][35], maxx, cnt, vis[maxn];
set<LL>s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n;
    Fo(i,1,n) {
        LL x; cin>>x;
        ind[x]++;
        fa[i][0] = x;
    }
    Fo(i,1,n)
        if(!ind[i])
            cnt++;
    Fo(i,1,30)
        Fo(j,1,n)
            fa[j][i] = fa[fa[j][i-1]][i-1];
    Fo(i,1,n) {
        cin>>a[i];
        if(a[i]<=n) vis[a[i]] = 1;
        maxx = max(maxx, a[i]);
    }
    Fo(i,1,n) {
        if(!vis[i])
            s.insert(i);
        vis[i] = 0;
    }
    LL step=(maxx-n)/cnt;
    Fo(i,1,n) {
        LL x=i;
        Fo(j,0,30)
            if(step&(1<<j))
                x = fa[x][j];
        cout<<x<<endl;
        if(!vis[a[x]]) {
            // cout<<a[x]<<" ";
            vis[a[x]] = 1;
        } else {
            LL temp = *s.lower_bound(a[x]);
            // cout<<temp<<" ";
            s.erase(temp);
        }
    }
    return 0;
}