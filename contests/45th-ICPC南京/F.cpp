//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define ls x<<1
#define rs x<<1|1
#define endl '\n'
#define eps 1e-6

// const LL maxn = ;
double n, m, p;

inline double qpow(double a, LL b) {
    double res = 1;
    while(b) {
        if(b&1)
            res =res*a;
        a = a*a;
        b>>=1;
    }
    return res;
}

//三分
double func(LL k) {
    return (k*n+m)/(1-qpow(1-p, k));
}

#define INF 2147483647

double three_divide() {
    double res = (n+m)/p;
    LL l=1, r=1000000;
    while(r-l+1>=10) {
        LL mid1=(l*2+r)/3, mid2=(l+r*2)/3;
        double f1=func(mid1), f2=func(mid2);
        res = min({res, f1, f2});
        if(f1<f2) r=mid2; else l=mid1;
    }
    for(int i=l; i<=r; i++)  res=min(res, func(i));
    return res;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; scanf("%lld",&t);//cin>>t;
    while(t--) {
        scanf("%lf%lf%lf",&n,&m,&p);
        // cin>>n>>m>>p;
        p *= 0.0001;
        // cout<<three_divide()<<endl;
        printf("%.6lf\n",three_divide());
    }
    return 0;
}