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
LL n, m;
vector<LL>x[maxn], y[maxn];

LL sol(vector<LL> v) {
    if(!v.size()) return 0;
    LL res = 0, sum = 0;
    
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>m;
    LL ans = 0, mx = 0;
    Fo(i,1,n)
        Fo(j,1,m) {
            LL c; cin>>c;
            x[c].push_back(i-1);
            y[c].push_back(j-1);
            mx = max(mx, c);
        }
    Fo(i,1,mx) {
        LL sum = 0, res = 0;
        sort(x[i].begin(), x[i].end());
        for(int j=0; j<x[i].size(); j++) {
            sum += x[i][j];
            res += (j+1)*x[i][j]-sum;
        }
        ans += res;
        // cout<<"x:"<<res<<" ";
        sum = 0; res = 0;
        sort(y[i].begin(), y[i].end());
        for(int j=0; j<y[i].size(); j++) {
            sum += y[i][j];
            res += (j+1)*y[i][j]-sum;
        }
        // cout<<"y:"<<res<<endl;
        ans += res;
    }
    cout<<ans;
    return 0;
}