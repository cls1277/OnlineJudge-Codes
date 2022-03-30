//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

// const LL maxn = ;
LL n, m, f[31][5001];
struct Pair {
    LL idx, g;
};
Pair c[31];
LL sum[31], ans[31];
Pair pre[31][5001];

bool operator < (const Pair &a, const Pair &b) {
    return a.g>b.g;
}

void print(Pair t) {
    if(!t.idx) return;
    print(pre[t.idx][t.g]);
    if(pre[t.idx][t.g].idx==t.idx) {
        Fo(i,1,n) ans[c[i].idx]++;
    } else {
        Fo(i,pre[t.idx][t.g].idx+1,n) ans[c[i].idx]=1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>m;
    Fo(i,1,n) {
        LL x; cin>>x;
        c[i] = {i, x};
    }
    sort(c+1, c+n+1);
    Fo(i,1,n) sum[i]=sum[i-1]+c[i].g;
    Ms(f, 0x3f);
    f[0][0] = 0;
    Fo(i,1,n)
        Fo(j,i,m) {
            LL temp = f[i][j-i];
            pre[i][j] = {i, j-i};
            Fo(k,0,i-1)
                if(temp>f[k][j-(i-k)]+k*(sum[i]-sum[k])) {
                    temp = f[k][j-(i-k)]+k*(sum[i]-sum[k]);
                    pre[i][j] = {k, j-(i-k)};
                }
            f[i][j] = temp;
        }
    cout<<f[n][m]<<endl;
    print({n,m});
    Fo(i,1,n) cout<<ans[i]<<" ";
    return 0;
}