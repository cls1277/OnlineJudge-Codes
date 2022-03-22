//By cls1277 
// 未AC， 一直TLE
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
inline LL read() {
	LL x = 0, f = 1;char c = getchar();
	while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
	while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
	return x * f;
}

const LL maxn = 33000;
LL n, m, v[maxn], w[maxn], f[65][maxn], ans;
vector<LL>e[maxn];

void dfs(LL x) {
    Fo(i,w[x],n) f[x][i]=v[x];
    for(auto &it:e[x]) {
        dfs(it);
        Ro(i,n,w[x])
            Fo(j,0,i-w[x])
                f[x][i]=max(f[x][i], f[x][i-j]+f[it][j]);
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    // cin>>n>>m;
    n=read(); m=read();
    Fo(i,1,m) {
        LL x, y, z; x=read(); y=read(); z=read();//cin>>x>>y>>z;
        v[i]=x*y; w[i]=x;
        e[z].push_back(i);
    }
    dfs(0);
    // cout<<f[0][n];
    printf("%lld",f[0][n]);
    return 0;
}