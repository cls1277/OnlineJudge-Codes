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

const LL maxn = 2e5+5;
LL n, m;
struct Node {
    LL a, b, c;
}e[maxn];
LL wm, k;

LL dfn[maxn], low[maxn], idx, cnt, color[maxn];
bool ins[maxn];//是否在栈里
stack<LL>st;

void tarjan(LL x, vector<LL>g[]) {
    dfn[x] = low[x] = ++idx;
    st.push(x); ins[x] = 1;
    for(LL i=0; i<g[x].size(); i++) {
        LL v=g[x][i];
        if(!dfn[v]) {
            tarjan(v, g);
            low[x] = min(low[x],low[v]);
        } else if(ins[v]) {
            low[x] = min(low[x],dfn[v]);
        }
    }
    if(dfn[x]==low[x]) {
        cnt++; LL temp;
        do {
            temp = st.top();
            ins[temp] = 0;
            color[temp] = cnt;
            st.pop();
        }while(temp!=x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>m;
    Fo(i,1,m) {
        LL x, y, z; cin>>x>>y>>z;
        e[i] = {x, y, z};
        wm = max(wm, z);
    }
    while(wm) {
        k++;
        wm>>=1;
    }
    Fo(i,0,k-1) {
        Ms(dfn, 0); idx=0; Ms(low, 0); Ms(ins, 0);
        while(st.size()) st.pop();
        vector<LL>g[maxn];
        Fo(j,1,m) {
            LL w=(e[j].c>>i)&1, x=e[j].a, y=e[j].b;
            if(w) {
                g[x].push_back(y+n);
                g[y].push_back(x+n);
                g[x+n].push_back(y);
                g[y+n].push_back(x);
            } else {
                g[x].push_back(y);
                g[x+n].push_back(y+n);
                g[y].push_back(x);
                g[y+n].push_back(x+n);
            }
        }
        Fo(j,1,2*n)
            if(!dfn[j])
                tarjan(j, g);
        // Fo(j,1,n) {
        //     if(color[j]==color[j+n]) {
        //         cout<<"-1";
        //         return 0;
        //     }
            
        // }
        Fo(j,1,n) cout<<color[j]<<" "<<color[j+n]<<endl;
        return 0;
    }
    return 0;
}