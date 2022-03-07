//By cls1277
#ifdef ONLINE_JUDGE
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<stack>
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef long long LL;
#define PI acos(-1)
#define INF 2147483647
#define eps 1e-7
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define lowbit(_) _&(-_)
#define mk(_,__) make_pair(_,__)
#define pii pair<int,int>
#define ls x<<1
#define rs x<<1|1
#define endl '\n'
inline LL read() {
    LL x = 0, f = 1;char c = getchar();
    while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
    while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
    return x * f;
}

const LL maxn = 5e4+5;
LL n, q, a[maxn];
LL mx[maxn][20], mn[maxn][20], bin[25];

void init() {
    bin[0] = 1;
    Fo(i,1,20)
        bin[i] = bin[i-1]*2;
    Fo(i,1,n) {
        mx[i][0] = a[i];
        mn[i][0] = a[i];
    }
    for(LL j=1; bin[j]<=n; j++)
        for(LL i=1; i+bin[j]-1<=n; i++) {
            mn[i][j] = min(mn[i][j-1], mn[i+bin[j-1]][j-1]);
            mx[i][j] = max(mx[i][j-1], mx[i+bin[j-1]][j-1]);
        }
    return ;
}

LL query(LL l, LL r) {
    LL k = (log((double)(r-l+1))/log(2.0));
    LL minn = min(mn[l][k], mn[r-bin[k]+1][k]);
    LL maxx = max(mx[l][k], mx[r-bin[k]+1][k]);
    return maxx-minn;
}

int main() {
    // ios::sync_with_stdio(false);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    while(scanf("%lld%lld",&n,&q)!=EOF) {
    // while(cin>>n>>q) {
        Fo(i,1,n) scanf("%lld",&a[i]);//cin>>a[i];
        init();
        Fo(i,1,q) {
            LL x, y; scanf("%lld%lld",&x,&y);// cin>>x>>y;
            // cout<<query(x,y)<<endl;
            printf("%lld\n",query(x,y));
        }
    }
    return 0;
}