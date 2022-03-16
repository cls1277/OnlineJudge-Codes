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
LL n, m, mw, k;
struct Node {
    LL a, b, c;
};
Node e[maxn<<1];
LL color[maxn], ans, fa[maxn], cnt;

LL find(LL x) {
    while(x!=fa[x]) x=fa[x]=fa[fa[x]];
    return x;
}

void dfs(LL x, LL f, vector<LL> g[], LL c) {
    for(int i=0; i<g[x].size(); i++) {
        LL v=g[x][i], m=find(v);
        if(v==f||color[v]) continue;
        if(color[v]&&color[v]==color[x]) {
            cout<<"-1";
            exit(0);
        }
        color[v] = 3-c;
        color[m] = 3-c;
        dfs(v,x,g,3-c);
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
        e[i] = {x,y,z};
        mw = max(mw , z);
    }
    while(mw) {
        k++;
        mw>>=1;
    }
    Fo(i,0,k-1) {
        Fo(j,1,n) fa[j]=j;
        vector<LL>g[maxn];
        Fo(j,1,m) {
            LL w=(e[j].c>>i)&1;
            if(w==1) {
                g[e[j].a].push_back(e[j].b);
                g[e[j].b].push_back(e[j].a);
            } else {
                LL p=find(e[j].a), q=find(e[j].b);
                if(p!=q) fa[p]=q;
            }
        }

        LL sum1 = 0, sum2 = 0;
        Ms(color,0);
        LL o = 1;
        Fo(j,1,n)
            if(!color[j]) {
                color[j] = 1;
                dfs(j,j,g,1);
                Fo(r,1,n) {
                    LL t=find(r);
                    if(!color[t]) continue;
                    color[r] = color[t];
                }
            }

        Fo(j,1,n)
            if(color[j]==2)
                sum1++;
        
        // LL temp[maxn];
        // Fo(j,1,n) temp[j]=color[j];

       Ms(color,0); o=2;
        Fo(j,1,n)
            if(!color[j]) {
                color[j] = 2;
                dfs(j,j,g,o);

                Fo(r,1,n) {
                    LL t=find(r);
                    if(!color[t]) continue;
                    color[r] = color[t];
                }
            }
        Fo(j,1,n)
            if(color[j]==2)
                sum2++;
        if(sum2>sum1) {
            ans+=sum1*(1<<i);
            // Fo(j,1,n) cout<<temp[j]-1<<" ";
        }
        else {
            ans+=sum2*(1<<i);
            // Fo(j,1,n) cout<<color[j]-1<<" ";
        }
        // cout<<endl;
    }
    cout<<ans;
    return 0;
}