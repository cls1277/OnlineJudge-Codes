//By cls1277
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

const LL maxn = 35;
LL n, x[maxn], y[maxn], z[maxn], d[maxn][3];

LL dfs(LL a, LL b) {
    if(d[a][b]!=-1) return d[a][b];
    d[a][b] = 0; LL p, q;
    if(b==0) {
        p=x[a]; q=y[a];
    } else if(b==1) {
        p=y[a]; q=z[a];
    } else if(b==2) {
        p=x[a]; q=z[a];
    }
    Fo(i,1,n) {
        if((x[i]<p&&y[i]<q)||(y[i]<p&&x[i]<q))
            d[a][b] = max(d[a][b], dfs(i, 0)+z[i]);
        if((y[i]<p&&z[i]<q)||(z[i]<p&&y[i]<q))
            d[a][b] = max(d[a][b], dfs(i, 1)+x[i]);
        if((x[i]<p&&z[i]<q)||(z[i]<p&&x[i]<q))
            d[a][b] = max(d[a][b], dfs(i, 2)+y[i]);
    }
    return d[a][b];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL tt=0;
    while(cin>>n&&n) {
        Fo(i,1,n) cin>>x[i]>>y[i]>>z[i];
        Fo(i,1,n) d[i][0]=d[i][1]=d[i][2]=-1;
        LL res=0;
        Fo(i,1,n)
            res = max({res, dfs(i,0)+z[i], dfs(i,1)+x[i], dfs(i,2)+y[i]});
        cout<<"Case "<<(++tt)<<": maximum height = "<<res<<endl;
    }
    return 0;
}