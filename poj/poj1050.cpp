//By cls1277
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
#include<set>
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

const LL maxn = 105;
LL n, a[maxn][maxn], sum[maxn], ans;

int main() {
    ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n;
    Fo(i,1,n) {
        Fo(j,1,n) {
            cin>>a[i][j];
        }
    }
    Fo(i,1,n) {
        Ms(sum, 0);
        Fo(j,i,n) {
            LL res = 0;
            Fo(k,1,n) {
                sum[k] += a[j][k];
                res = res+sum[k]<0 ? 0:res+sum[k];
                ans = max(ans, res);
            }
        }
    }
    cout<<ans;
    return 0;
}