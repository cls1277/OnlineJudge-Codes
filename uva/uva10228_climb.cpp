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
#define MAXN 1e20
LL n, _x[maxn], _y[maxn];
LL dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

double getDis(double x, double y) {
    double dis = 0;
    Fo(i,1,n) dis+=sqrt((_x[i]-x)*(_x[i]-x)+(_y[i]-y)*(_y[i]-y));
    return dis;
}

double climb() {
    double x=rand()%10001, y=rand()%10001;
    double dis = getDis(x, y);
    double step = 10000;
    while(step>0.001) {
        double mn=MAXN, tx, ty;
        Fo(i,0,3) {
            double nx=x+dx[i]*step, ny=y+dy[i]*step;
            double ndis = getDis(nx, ny);
            if(ndis<mn) {
                mn = ndis;
                tx = nx;
                ty = ny;
            }
        }
        if(mn<dis) {
            dis = mn;
            x = tx;
            y = ty;
        }
        step*=0.5;
    }
    return dis;
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
        double ans = MAXN;
        Fo(i,1,10) ans = min(ans, climb());
        cout<<LL(ans+0.5)<<endl;
        // printf("%.0lf\n",ans);
        if(T) cout<<endl;
    }
    return 0;
}