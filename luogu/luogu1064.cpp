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

const LL maxn = 33000;
LL n, m, v[maxn], w[maxn], c[maxn], idx, vm[maxn], wm[maxn], d, f[maxn];
vector<LL>son[maxn], g[maxn];
vector<LL>res;

void dfs(LL x, LL k, LL id) {
    if(x==k+1) {
        LL a=0, b=0;
        for(auto &it:res) {
            a+=v[son[id][it]];
            b+=w[son[id][it]];
        }
        idx++;
        vm[idx]=a+v[id]; wm[idx]=b+w[id];
        g[d].push_back(idx);
        return ;
    }
    res.push_back(x);
    dfs(x+1, k, id);
    res.pop_back();
    dfs(x+1, k, id);
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
        v[i] = x*y;
        w[i] = x;
        c[i] = z;
        if(z) son[z].push_back(i);
    }
    Fo(i,1,m) {
        if(son[i].size()) {
            d++;
            res.clear();
            dfs(0, son[i].size()-1, i);
        } else if(!c[i]){
            d++; idx++;
            vm[idx] = v[i];
            wm[idx] = w[i];
            g[d].push_back(idx);
        }
    }
    Fo(i, 1, d)
        Ro(j, n, 0)
            for(auto &it:g[i])
                if(j>=wm[it])
                    f[j] = max(f[j], f[j-wm[it]]+vm[it]);
    cout<<f[n];
    return 0;
}