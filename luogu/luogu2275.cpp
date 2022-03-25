//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef int LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define ls x<<1
#define rs x<<1|1
#define endl '\n'

const LL maxn = 1e7+5;
vector<pair<LL,LL>>a;
LL maxx, mu[maxn];
bool vis[maxn]; LL cnt=0, pri[maxn];
long long f[maxn];

inline LL read() {
	LL x = 0, f = 1;char c = getchar();
	while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
	while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
	return x * f;
}

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
    getmu(maxx, mu);
    Fo(i,0,cnt-1) {
        for(int j=1; pri[i]*j<=maxx; j++) {
            f[pri[i]*j]+=mu[j];
        }
    }
    Fo(i,1,maxx) f[i]+=f[i-1];
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; t=read();//scanf("%d",&t);//cin>>t;
    vector<pair<LL,LL>>a(t);
    Fo(i,0,t-1) {
        LL n, m; n=read(); m=read();//scanf("%d%d",&n,&m);//cin>>n>>m;
        if(n>m) swap(n, m);
        a[i] = make_pair(n, m);
        maxx = max(maxx, m);
    }
    init();
    for(auto &it:a) {
        LL n=it.first, m=it.second;
        long long ans=0;
        for(int i=1,j; i<=min(n, m); i=j+1) {
            j=min(n/(n/i), m/(m/i));
            ans+=1ll*(n/i)*(m/i)*(f[j]-f[i-1]);
        }
        printf("%lld\n",ans);
        // cout<<ans<<endl;
    }
    return 0;
}