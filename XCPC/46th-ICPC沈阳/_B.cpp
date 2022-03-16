//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef int LL;
#define INF 2147483647
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define ls x<<1
#define rs x<<1|1
#define endl '\n'

const LL maxn = 1e5+5;
LL n, m, mw, k;
struct Node {
    LL a, b, c;
};
Node e[maxn<<1];
LL color[maxn], ans;
struct Edge {
    LL to, next, len;
}g[maxn<<2];
LL head[maxn], tot;
pair<LL,LL>q[maxn];

void add(LL x, LL y, LL z) {
    tot++;
    g[tot].next = head[x];
    g[tot].to = y;
    g[tot].len = z;
    head[x] = tot;
}

LL bfs(LL x) {
    LL hed=0, tail=-1;
    q[++tail]=make_pair(x,x);
    while(tail>=hed) {
        pair<LL,LL>u=q[hed];
        hed++;
        Eo(i,u.first,g) {
            LL v=g[i].to, w=g[i].len;
            if(v==u.second) continue;
            if(color[v]) {
                if((w==1&&color[v]==color[u.first])||(w==0&&color[v]!=color[u.first]))
                    return -1;
            }
            if(color[v]) continue;
            if(w==1) {
                color[v]=3-color[u.first];
                q[++tail] = make_pair(v,u.first);
            } else {
                color[v]=color[u.first];
                q[++tail] = make_pair(v,u.first);               
            }
        }
    }
    return 0;
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
        e[i] = {x,y,z};
        mw = max(mw , z);
    }
    while(mw) {
        k++;
        mw>>=1;
    }
    Fo(i,0,k-1) {
        LL sum1=0, sum2=0;
        tot=0; Ms(head,0); Ms(g,0);
        Fo(j,1,m) {
            LL w=(e[j].c>>i)&1;
            add(e[j].a,e[j].b,w);
            add(e[j].b,e[j].a,w);
        }
        Ms(color,0);
        Fo(j,1,n) {
            if(!color[j]) {
                color[j] = 1;
                sum1 = bfs(j);
                if(sum1==-1) {
                    cout<<"-1";
                    return 0;
                }
            }
        }
        Fo(j,1,n) if(color[j]==2) sum1++;            
        Ms(color,0);
        Fo(j,1,n) {
            if(!color[j]) {
                color[j] = 2;
                bfs(j);
            }
        }
        Fo(j,1,n) if(color[j]==2) sum2++;            
        ans+=min(sum1,sum2)*(1<<i);
    }
    cout<<ans;
    return 0;
}