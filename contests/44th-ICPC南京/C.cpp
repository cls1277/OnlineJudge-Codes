//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 1e3+5;
LL n, m, a[maxn][maxn];
LL dx[4] = {0, 0, -1, 1};
LL dy[4] = {1, -1, 0, 0};
vector<pair<LL, LL>> e[maxn][maxn];
LL ind[maxn][maxn], res[maxn][maxn], ind2[maxn][maxn];
const LL mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>m;
    Fo(i,1,n) {
        Fo(j,1,m) {
            cin>>a[i][j];
        }
    }
    Fo(i,1,n) {
        Fo(j,1,m) {
            Fo(k,0,3) {
                LL x = i+dx[k], y = j+dy[k];
                if(x<1||x>n||y<1||y>m) continue;
                if(a[x][y]==a[i][j]+1) {
                    e[i][j].push_back({x, y});
                    ind[x][y] ++;
                    ind2[x][y] ++;
                }
            }
        }
    }
    queue<pair<LL, LL>> q;
    vector<pair<LL, LL>> z;
    Fo(i,1,n) {
        Fo(j,1,m) {
            if(!ind[i][j]&&e[i][j].size()) {
                q.push({i, j});
                res[i][j] = 1;
            }
            if(e[i][j].size()==0) {
                z.push_back({i, j});
            }
            // cout<<i<<","<<j<<":"<<ind[i][j]<<" ";
            // for(auto it:e[i][j]) {
            //     cout<<"("<<it.first<<","<<it.second<<") ";
            // }
            // cout<<endl;
        }
    }
    // for(auto it:z) {
    //     cout<<it.first<<' '<<it.second<<endl;
    // }
    // return 0;
    while(!q.empty()) {
        pair<LL, LL> u = q.front();
        q.pop();
        for(auto it:e[u.first][u.second]) {
            ind[it.first][it.second]--;
            if(!ind[it.first][it.second]) {
                q.push({it.first, it.second});
            }
            // if(it.first==2&&it.second==5) {
            //     cout<<u.first<<' '<<u.second<<'*'<<endl;
            // }
            res[it.first][it.second] = (res[it.first][it.second]+res[u.first][u.second])%mod;
        }
    }
    LL ans = 0;
    for(auto it:z) {
        // cout<<it.first<<' '<<it.second<<' '<<res[it.first][it.second]<<endl;
        ans = (ans+res[it.first][it.second])%mod;
    }
    Fo(i,1,n) {
        Fo(j,1,m) {
            if(!ind2[i][j]) {
                for(auto it:e[i][j]) {
                    if(e[it.first][it.second].size()==0) {
                        // cout<<i<<' '<<j<<' '<<it.first<<' '<<it.second<<endl;
                        ans = (ans-1+mod)%mod;
                    }
                    for(auto it2:e[it.first][it.second]) {
                        if(e[it2.first][it2.second].size()==0) {
                            // cout<<i<<' '<<j<<' '<<it.first<<' '<<it.second<<' '<<it2.first<<' '<<it2.second<<endl;
                            ans = (ans-1+mod)%mod;
                        }
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}