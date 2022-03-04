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

const LL maxn = 205;
LL n, m, a[maxn][maxn], b[maxn], ans;
bool vis[maxn];

bool judge(LL x) {
    Fo(i,1,m) {
        if(a[x][i]&&!vis[i]) {
            vis[i] = 1;
            if(!b[i]||judge(b[i])) {
                b[i] = x;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    while(cin>>n>>m) {
        ans = 0;
        Ms(a,0); Ms(b,0);
        Fo(i,1,n) {
            LL x; cin>>x;
            Fo(j,1,x) {
                LL y; cin>>y;
                a[i][y] = 1;
            }
        }
        Fo(i,1,n) {
            Ms(vis,0);
            if(judge(i))
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}