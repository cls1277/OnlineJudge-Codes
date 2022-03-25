//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define ls x<<1
#define rs x<<1|1
#define endl '\n'

const LL maxn = 5e4+5;
LL f[maxn], mu[maxn];
bool vis[maxn]; LL cnt=0, pri[maxn];

void getmu(LL maxx, LL mu[]) {
    memset(vis, 0, sizeof(vis));
    mu[1] = 1;
    for(LL i=2; i<=maxx; i++) {
        if(!vis[i]) {
            mu[i] = -1;
            pri[cnt++] = i;
        }
        for(LL j=0; j<cnt; j++) {
            if(i*pri[j]>maxx) break;
            vis[i*pri[j]] = 1;
            if(i%pri[j])
                mu[i*pri[j]] = -mu[i];             
            else {
                mu[i*pri[j]] = 0;
                break;
            }
        }
    }
}

void init() {
    getmu(50000, mu);
    Fo(k,1,50000) {
        for(LL i=1,j; i<=k; i=j+1) {
            j=k/(k/i);
            f[k]+=(j-i+1)*(k/i);
        }
    }
    Fo(i,1,50000) mu[i]+=mu[i-1];
}

LL sol(LL x, LL y) {
    LL res = 0;
    for(LL i=1,j; i<=min(x, y); i=j+1) {
        j=min(x/(x/i), y/(y/i));
        res += f[x/i]*f[y/i]*(mu[j]-mu[i-1]);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    init();
    while(t--) {
        LL n, m;
        cin>>n>>m;
        cout<<sol(n, m)<<endl;
    }
    return 0;
}