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
LL n, m, K, xs, ys, xt, yt;
struct Node {
    LL a, b, c, d; // u, d, l, r;
};

struct Map {
    bool u, d, l, r;
} mp[20][20];

struct Que {
    LL x, y; //1u, 2d, 3l, 4r
};
bool vis[20][20];

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        cin>>n>>m>>K;
        vector<Node> e(K+1);
        cin>>xs>>ys>>xt>>yt;
        Fo(i,1,K) {
            LL a, b, c, d; cin>>a>>b>>c>>d;
            if(a>c) swap(a, c);
            if(b>d) swap(b, d);
            e[i] = {a, b, c, d};
        }
        LL len = (1<<K)-1, ans = INT_MAX;
        Fo(k,0,len) {
            Fo(i,0,n) Fo(j,0,m) mp[i][j] = {0, 0, 0, 0}, vis[i][j] = 0;
            Fo(i,1,K) {
                if(((k>>(i-1))&1)==0) continue;
                if(e[i].a==e[i].c) {
                    Fo(j,e[i].b,e[i].d) {
                        if(j==e[i].b) mp[e[i].a][j].u = 1;
                        else if(j==e[i].d) mp[e[i].a][j].d = 1;
                        else mp[e[i].a][j].u = mp[e[i].a][j].d = 1;
                    }
                } else {
                    Fo(j,e[i].a,e[i].c) {
                        if(j==e[i].a) mp[j][e[i].b].r = 1;
                        else if(j==e[i].c) mp[j][e[i].b].l = 1;
                        else mp[j][e[i].b].l = mp[j][e[i].b].r = 1;
                    }
                }
            }
            queue<Que> q; q.push({xs, ys});
            vis[xs][ys] = 1; bool flag = 0;
            while(!q.empty()) {
                Que u = q.front(); q.pop();
                if(u.x==xt&&u.y==yt) {
                    flag = 1;
                    break;
                }
                Fo(i,0,3) {
                    LL tx=u.x+dx[i], ty=u.y+dy[i];
                    if(tx<0||ty<0||tx>=n||ty>=m||vis[tx][ty]) continue;
                    if(i==0&&!mp[tx][ty].r) {
                        vis[tx][ty] = 1;
                        q.push({tx, ty});
                    } else if(i==1&&!mp[u.x][u.y].r) {
                        vis[tx][ty] = 1;
                        q.push({tx, ty});
                    } else if(i==2&&!mp[tx][ty].u) {
                        vis[tx][ty] = 1;
                        q.push({tx, ty});
                    } else if(i==3&&!mp[u.x][u.y].u) {
                        vis[tx][ty] = 1;
                        q.push({tx, ty});
                    }
                }
            }
            if(flag) ans = min(ans, K-__builtin_popcount(k));
        }
        cout<<ans<<endl;
    }
    return 0;
}
