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

const LL maxn = 1e6+5;
LL phi[maxn], f[maxn], pri[maxn];
bool vis[maxn];

void getphi(LL maxx, LL phi[]) {
    LL cnt=0;
    memset(vis, 0, sizeof(vis));
    for(LL i=2; i<=maxx; i++) {
        if(!vis[i]) {
            pri[cnt++] = i;
            phi[i] = i-1;
        }
        for(LL j=0; j<cnt; j++) {
            if(i*pri[j]>maxx) break;
            vis[i*pri[j]] = 1;
            if(i%pri[j]==0) {
                phi[i*pri[j]] = phi[i]*pri[j];
                break;
            } else {
                phi[i*pri[j]] = phi[i]*(pri[j]-1);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    getphi(1000000, phi); Ms(f, 0);
    Fo(i,2,1000000)
        for(int j=1; i*j<=1000000; j++)
            f[i*j]+=phi[i]*i/2;
    LL t; cin>>t;
    while(t--) {
        LL n; cin>>n;
        cout<<(f[n]+1)*n<<endl;
    }
    return 0;
}