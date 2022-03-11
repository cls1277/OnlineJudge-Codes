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

const LL maxn = 105;
LL n, m;
bool vis[maxn][maxn];
LL dx[4]={0,0,1,-1}, dy[4]={1,-1,0,0};
string mp[maxn];
vector<pair<LL,LL>>b;

void dfs(LL x, LL y) {
    Fo(i,0,3) {
        LL tx=x+dx[i], ty=y+dy[i];
        if(tx<0||ty<0||tx>=n||ty>=m) continue;
        if(vis[tx][ty]||mp[tx][ty]=='0') continue;
        vis[tx][ty] = 1;
        b.push_back(make_pair(tx,ty));
        dfs(tx,ty);
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
        Ms(vis,0);
        cin>>n>>m; bool flag = false;
        Fo(i,0,n-1) cin>>mp[i];
        Fo(i,0,n-1) {
            Fo(j,0,m-1) {
                if(vis[i][j]||mp[i][j]=='0') continue;
                vis[i][j] = 1;
                b.clear();
                b.push_back(make_pair(i,j));
                dfs(i,j);
                LL minx=INF, miny=INF, maxx=-1, maxy=-1;
                for(auto &it:b) {
                    minx = min(minx , it.first);
                    maxx = max(maxx , it.first);
                    miny = min(miny , it.second);
                    maxy = max(maxy , it.second);
                }
                if((maxy-miny+1)*(maxx-minx+1)!=b.size()) {
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}