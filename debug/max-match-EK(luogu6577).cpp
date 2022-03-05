//By cls1277
#ifdef ONLINE_JUDGE
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef long long LL;
#define PI acos(-1)
const LL INF = 1e18;
// #define INF 2147483647
#define eps 1e-7
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define lowbit(_) _&(-_)
#define mk(_,__) make_pair(_,__)
#define pii pair<int,int>
#define ls x<<1
#define rs x<<1|1
#define endl '\n'
inline LL read() {
    LL x = 0, f = 1;char c = getchar();
    while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
    while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
    return x * f;
}

const LL maxn = 505;
LL n, m, a[maxn][maxn], b[maxn], ex[maxn], ey[maxn], slack[maxn];
bool vx[maxn], vy[maxn];
LL mx[maxn], my[maxn];

bool judge(LL x) {
    vy[x] = 1;
    Fo(i,1,n) { // for in x
        if(vx[i]) continue;
        LL d=ex[i]+ey[x]-a[x][i];
        if(!d) {
            vx[i] = 1;
            if(!b[i]||judge(b[i])) {
                b[i] = x;
                return 1;
            }
        } else slack[i]=min(slack[i],d);
    }
    return 0;
}

bool _judge(LL x) {
    LL pre[maxn];
    bool vis[maxn]; Ms(vis,0);
    pre[x] = -1;
    vy[x] = 1;
    queue<LL>q;
    q.push(x);
    while(!q.empty()) {
        LL u=q.front(); q.pop();
        Fo(i,1,n) {
            if(a[i][u]&&!vis[i]) {
                LL d=ex[i]+ey[u]-a[u][i];
                if(!d) {
                    vis[i] = 1;
                    if(mx[i]) {
                        q.push(mx[i]);
                        pre[mx[i]] = u;
                    } else {
                        while(u!=-1) {
                            LL temp = my[u];
                            my[u] = i;
                            mx[i] = u;
                            u = pre[u];
                            i = temp;
                        }
                        return true;
                    }    
                } else slack[i]=min(slack[i],d);
            }
        }
    }
    return false;
}

LL KM() {
    Ms(b,0);
    Ms(ex,0);
    Fo(i,1,n)
        Fo(j,1,n)
            ey[i]=max(ey[i],a[i][j]);
    Fo(i,1,n) { //for in y
        // Ms(slack,0xfffffff);
        Fo(j,1,n) slack[j]=INF;
        while(1) {
            Ms(vx,0); Ms(vy,0);
            if(_judge(i)) break;
            LL d=INF;
            Fo(j,1,n)
                if(!vx[j])
                    d=min(d,slack[j]);
            Fo(j,1,n) {
                if(vy[j]) ey[j]-=d;
                if(vx[j]) ex[j]+=d;
                else slack[j]-=d;
            }
        }
    }
    LL res=0;
    Fo(i,1,n)
        res+=a[my[i]][i];
    return res;
}

int main() {
    // ios::sync_with_stdio(false);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    n=read(); m=read();
    // cin>>n>>m;
    Fo(i,1,n)
        Fo(j,1,n)
            a[i][j] = -INF;
    Fo(i,1,m) {
        LL x,y,z; x=read(); y=read(); z=read();//cin>>x>>y>>z;
        a[x][y] = z;
    }
    printf("%lld\n",KM());
    // cout<<KM()<<endl;
    Fo(i,1,n) printf("%lld ",b[i]);//cout<<b[i]<<" ";
    return 0;
}