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
const double eps = 1e-5;
LL n, L;
double a[maxn], sum[maxn];

bool judge(double x) {
    Fo(i,1,n) {
        double y = a[i]-x;
        sum[i] = sum[i-1]+y;
    }
    double minn=INT_MAX, res=-INT_MAX;
    Fo(i,L,n) {
        minn = min(minn, sum[i-L]);
        res = max(res, sum[i]-minn);
    }
    return (res>=0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>L;
    Fo(i,1,n) cin>>a[i];
    double l = 0, r = 2000;
    while(r-l > eps) {
        double mid = (l+r)/2;
        if(judge(mid)) l = mid;
        else r = mid;
    }
    cout<<int(r*1000);
    return 0;
}