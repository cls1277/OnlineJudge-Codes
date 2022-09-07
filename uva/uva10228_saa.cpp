//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 105;

const double Q = 0.997;
const LL MAXN = 3000;
const double eps = 1e-12;

#define pdd pair<double, double>
LL n, _x[maxn], _y[maxn];
pdd ans, now;
double res = 1e20;

double getDis(double x, double y) {
    double dis = 0;
    Fo(i,1,n) dis+=sqrt((_x[i]-x)*(_x[i]-x)+(_y[i]-y)*(_y[i]-y));
    return dis;
}

void SAA() {
    double t = MAXN;
    while(t>eps) {
        double x = now.first+((rand()<<1)-RAND_MAX)*t;
        double y = now.second+((rand()<<1)-RAND_MAX)*t;
        double dis = getDis(x, y);
        double det = dis-res;
        if(det<0) {
            res = dis;
            ans = now = {x, y};
        } else if(exp(-det/t)*RAND_MAX > rand()) {
            now = {x, y};
        }
        t*=Q;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    srand(time(NULL));
    LL T; cin>>T;
    while(T--) {
        cin>>n;
        Fo(i,1,n) cin>>_x[i]>>_y[i];
        res = 1e20;
        now = ans = {0, 0};
        Fo(i,1,5) SAA();
        cout<<LL(res+0.5)<<endl;
        if(T) cout<<endl;
    }
    return 0;
}