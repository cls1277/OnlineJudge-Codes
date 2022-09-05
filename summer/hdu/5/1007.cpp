//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 5e5+5;
LL n, k, a[maxn];

struct Edge {
    LL to, next;
};
Edge e[maxn<<2];

LL tot, head[maxn];
bool vis[maxn];

void add(LL x, LL y) {
    tot++;
    e[tot] = {y, head[x]};
    head[x] = tot;
}

LL res;

void dfs(LL x, LL cnt) {
    res = max(res, cnt);
    Eo(i,x,e) {
        LL v = e[i].to;
        if(!vis[v]) {
            vis[v] = 1;
            dfs(v, cnt+1);
        }
    }
}

vector<LL> circle;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        cin>>n>>k;
        Fo(i,1,n) vis[i]=0; circle.clear(); tot=0; Ms(head, 0);
        Fo(i,1,n) cin>>a[i];
        Fo(i,1,n) {
            add(a[a[i]], a[i]);
            add(a[i], a[a[i]]);
            add(i, a[i]);
            add(a[i], i);
        }
        // Fo(i,1,n) {
        //     cout<<i<<":";
        //     Eo(j,i,e) {
        //         cout<<e[j].to<<' ';
        //     }
        //     cout<<endl;
        // }
        Fo(i,1,n) {
            if(!vis[i]) {
                vis[i] = 1;
                res = 1;
                dfs(i, 1);
                if(res!=1) circle.push_back(res);
            }
        }
        for(auto it:circle) cout<<it<<' ';
        cout<<endl;
        
    }
    return 0;
}
