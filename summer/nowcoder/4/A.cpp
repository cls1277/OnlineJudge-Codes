//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 1e5+5;
LL n, m, w[maxn];
double p[maxn];
bool vis[maxn];
LL a[maxn];
double ans=-INT_MAX;

void dfs(LL cnt, bool vis[], LL a[]) {
    if(cnt==m) {
        double ops = 0;
        Fo(i,1,m) {
            double res = 1;
            Fo(j,0,i-1) res *= p[a[j]];
            ops += w[a[i]]*res;
        }
        ans = max(ans, ops);
        return ;
    }
    Fo(i,1,n) {
        if(vis[i]) continue;
        vis[i] = 1;
        a[cnt+1] = i;
        dfs(cnt+1, vis, a);
        vis[i] = 0;
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
    // cin>>n>>m;
    n=read(); m=read();
    Fo(i,1,n) w[i]=read(); //cin>>w[i];
    Fo(i,1,n)  {
        LL x; x=read(); //cin>>x;
        p[i] = x*1.0/10000;
    }
    a[0] = 0;
    p[0] = 1;
    dfs(0, vis, a);
    // cout<<ans;
    printf("%.16lf",ans);
    return 0;
}