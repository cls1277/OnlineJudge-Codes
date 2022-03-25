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
LL n, a, b, c, d, k, mu[maxn];

void getmu(LL maxx, LL mu[]) {
    bool vis[maxn]; LL cnt=0, pri[maxn];
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

LL sol(LL x, LL y) {
    LL res = 0;
    for(LL i=1,j; i<=min(x, y); i=j+1) {
        j=min(x/(x/i), y/(y/i));
        res+=(mu[j]-mu[i-1])*(x/i)*(y/i);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n;
    getmu(50000, mu);
    Fo(i,1,50000) mu[i]+=mu[i-1];//pre sum
    while(n--) {
        cin>>a>>b>>c>>d>>k;
        cout<<(sol(b/k, d/k)-sol((a-1)/k, d/k)-sol(b/k, (c-1)/k)+sol((a-1)/k, (c-1)/k))<<endl;
    }
    return 0;
}