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

const LL maxn = 1670000;
unordered_map<int,int>hashmu;
unordered_map<int,LL>hashphi;
bool vis[maxn]; LL cnt=0, pri[maxn];
int n;
int maxx;
double N;
LL phi[maxn], mu[maxn];

int summu(int n) {
    if(n<=N) return mu[n];
    if(hashmu[n]) return hashmu[n];
    int res = 1;
    for(LL i=2,j; i<=n; i=j+1) {
        j=n/(n/i);
        res -= summu(n/i)*(j-i+1);
    }
    return hashmu[n]=res;
}

LL sumphi(LL n) {
    if(n<=N) return phi[n];
    if(hashphi[n]) return hashphi[n];
    LL res = n*(n+1)/2;
    for(LL i=2,j; i<=n; i=j+1) {
        j = n/(n/i);
        res -= 1LL*sumphi(n/i)*(j-i+1);
    }
    return hashphi[n] = res;
}

void init(LL maxx, LL phi[], LL mu[]) {
    memset(vis, 0, sizeof(vis));
    mu[1] = phi[1] = 1;
    for(LL i=2; i<=maxx; i++) {
        if(!vis[i]) {
            mu[i] = -1;
            pri[cnt++] = i;
            phi[i] = i-1;
        }
        for(LL j=0; j<cnt; j++) {
            if(i*pri[j]>maxx) break;
            vis[i*pri[j]] = 1;
            if(i%pri[j]==0) {
                phi[i*pri[j]] = phi[i]*pri[j];
                mu[i*pri[j]] = 0;
                break;
            } else {
                phi[i*pri[j]] = phi[i]*(pri[j]-1);
                mu[i*pri[j]] = -mu[i]; 
            }
        }
    }
    Fo(i,1,maxx) {
        phi[i] += phi[i-1];
        mu[i] += mu[i-1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    int t; cin>>t;
    vector<int>a(t);
    Fo(i,0,t-1) {
        int x; cin>>x;
        a[i] = x;
        maxx = max(maxx, x);
    }
    N = pow(maxx, 2.0/3);
    init(N, phi, mu);
    for(auto &it:a) {
        cout<<sumphi(it)<<" "<<summu(it)<<endl;
    }
    return 0;
}