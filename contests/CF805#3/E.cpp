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

LL n, cnt, tot, head[maxn], vis[maxn];
bool op;

struct Node {
    LL to, next;
}e[maxn<<1];

void add(LL x, LL y) {
    tot++;
    e[tot].next = head[x];
    e[tot].to = y;
    head[x] = tot;
}

void dfs(LL x, LL f) {
    Eo(i,x,e) {
        LL v = e[i].to;
        if(vis[v]) {
            if(v!=f) op = 1;
            continue;
        }
        cnt++;
        vis[v] = 1;
        dfs(v, x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        map<LL, LL> ops;
        Ms(vis, 0);
        Ms(head, 0);
        tot = 0;
        cin>>n;
        bool flag = 1;
        Fo(i,1,n) {
            LL x, y; cin>>x>>y;
            ops[x]++; ops[y]++;
            if(x==y||ops[x]>2||ops[y]>2) {
                flag = 0;
            }
            add(x, y);
            add(y, x);
        }
        if(flag) {
            Fo(i,1,n)
                if(!vis[i]) {
                    cnt = 1;
                    vis[i] = 1;
                    op = 0;
                    dfs(i, i);
                    if(cnt&1||!op) flag = 0;
                    if(!flag) {
                        break;
                    }
                }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}