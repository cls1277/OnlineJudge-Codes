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
const LL mod = 998244353;
LL n, ans, frac[maxn], inv2, inv[maxn], invf[maxn], ind[maxn], del[maxn];
vector<LL>e[maxn];
queue<LL>q;

LL qpow(LL a, LL b, LL mod) {
    LL res = 1;
    while(b) {
        if(b&1)
            res = res*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return res;
}

void init() {
    frac[0] = 1;
    inv[1] = inv2 = qpow(2, mod-2, mod);
    for(int i=1; i<=n; i++) {
        frac[i] = frac[i-1]*i%mod;
        inv[i+1]=inv[i]*inv2%mod;
    }
    invf[n] = qpow(frac[n], mod-2, mod);
    for(int i=n-1; i>=0; i--)
        invf[i] = invf[i+1]*(i+1)%mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr );
    #ifdef DEBUG
    freopen("tree1.in","r",stdin);
    // freopen("data.txt","r",stdin);
    #endif
    cin>>n; ans=1;    
    init();
    Fo(i,1,n-1) {
        LL x, y; cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
        ind[x]++; ind[y]++;
    }
    bool vis[maxn]; Ms(vis,0);
    Fo(i,1,n)
        if(ind[i]==1) {
            vis[i] = 1;
            q.push(i);
        }
    while(!q.empty()) {
        LL u=q.front(); q.pop();
        for(int i=0; i<e[u].size(); i++) {
            LL v=e[u][i];
            if((e[u].size()-del[u])%2==0)
                del[v]++;
            ind[v]--;
            if(ind[v]==1&&!vis[v]) {
                q.push(v);
                vis[v] = 1;
                LL x=e[v].size()-del[v];
                if(x==1) continue;
                if(x%2) ans=ans*frac[x-1]%mod*invf[(x-1)/2]%mod*inv[(x-1)/2]%mod;
                else ans=ans*frac[x]%mod*invf[x/2]%mod*inv[x/2]%mod;
            }
        }
    }
    cout<<ans;
    return 0;
}