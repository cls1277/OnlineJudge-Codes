//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 5e5+5;
const LL mod = 998244353;
LL n, ans;
vector<LL> e[maxn];
bool vis[maxn];
LL frac[maxn], inv[maxn];

inline LL qpow(LL a, LL b, LL mod) {
    LL res = 1;
    while(b) {
        if(b&1)
            res = res*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return res;
}

LL C(LL x, LL y) {
    if(x<y) return 0;
    return frac[x]*inv[y]%mod*inv[x-y]%mod;
}

void dfs(LL x) {
    LL cnt1 = e[x].size();
    LL cnt2=0, cnt3=0;
    vector<LL> b;
    for(auto v:e[x]) {
        cnt2 += (e[v].size()==2);
        if(e[v].size()>2) {
            cnt3++;
            b.push_back(v);
        }
        if(vis[v]) continue;
        vis[v] = 1;
        dfs(v);
    }
    LL cnt4 = cnt2;
    for(auto v:b) cnt4 += e[v].size()-1;
    for(auto v:b) {
        LL a = C(e[v].size()-1, 2);
        ans = (ans+(cnt1-cnt2-cnt3)*a%mod*C(cnt4-e[v].size()+1, 2)%mod)%mod;
        ans = (ans+cnt2*a%mod*C(cnt4-e[v].size(), 2)%mod)%mod;
        for(auto p:b) {
        	if(p==v) continue;
        	ans = (ans+a*C(cnt4-e[v].size()+1-e[p].size()+1, 2)%mod)%mod;
		}
    }
}

inline LL read() {
	LL x = 0, f = 1;char c = getchar();
	while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
	while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
	return x * f;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; t=read(); //cin>>t;
    frac[0] = 1;
    for(LL i=1; i<=500000; i++)
        frac[i] = frac[i-1]*i%mod;
    inv[500000] = qpow(frac[500000],mod-2,mod);
    for(LL i=500000-1; i>=0; i--)
        inv[i] = inv[i+1]*(i+1)%mod;
    while(t--) {
        n=read(); //cin>>n;
        Fo(i,1,n) e[i].clear();
        ans = 0;
        Fo(i,1,n-1) {
            LL x, y; x=read(); y=read(); //cin>>x>>y;
            e[x].push_back(y);
            e[y].push_back(x);
        }
        Fo(i,1,n) vis[i] = false;
        vis[1] = 1;
        dfs(1);
        printf("%lld\n",ans);
        // cout<<ans<<endl;
    }
    return 0;
}
