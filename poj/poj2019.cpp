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

const LL maxn = 255;
LL n, k, w, a[maxn][maxn], fx[maxn][maxn][10], fn[maxn][maxn][10];

inline LL mymax(LL x, LL y, LL z, LL g) {
    return max(max(x,y),max(z,g));
}

inline LL mymin(LL x, LL y, LL z, LL g) {
    return min(min(x,y),min(z,g));
}

void init() {
    Fo(i,1,n)
        Fo(j,1,n) {
            fx[i][j][0] = a[i][j];    
            fn[i][j][0] = a[i][j];         
        }
    for(LL j=1; (1<<j)<=n; j++) {
        LL t=(1<<(j-1));
        // LL t=1<<j-1;
        Fo(i,1,n) {
        // for(LL i=1; i+(1<<j)-1<=n; i++) {
            for(LL l=1; l+(1<<j)-1<=n; l++) {
                fx[i][l][j] = mymax(fx[i][l][j-1], fx[i][l+t][j-1], fx[i+t][l][j-1], fx[i+t][l+t][j-1]);
                fn[i][l][j] = mymin(fn[i][l][j-1], fn[i][l+t][j-1], fn[i+t][l][j-1], fn[i+t][l+t][j-1]);
            }
        }
    }
}

LL query(LL x, LL y) {
    LL t=log((double)(w))/log(2.0);
    LL mx = mymax(fx[x][y][t], fx[x+w-(1<<t)][y][t], fx[x][y+w-(1<<t)][t], fx[x+w-(1<<t)][y+w-(1<<t)][t]);
    LL mn = mymin(fn[x][y][t], fn[x+w-(1<<t)][y][t], fn[x][y+w-(1<<t)][t], fn[x+w-(1<<t)][y+w-(1<<t)][t]);
    return mx-mn;
}

int main() {
    // ios::sync_with_stdio(false);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    while(scanf("%lld%lld%lld",&n,&w,&k)!=EOF) {
        Fo(i,1,n)
            Fo(j,1,n)
                scanf("%lld",&a[i][j]);//cin>>a[i][j];
        init();
        Fo(i,1,k) {
            LL x,y; scanf("%lld%lld",&x,&y);//cin>>x>>y;
            // cout<<query(x,y)<<endl;
            printf("%lld\n",query(x,y));
        }
    }
    return 0;
}