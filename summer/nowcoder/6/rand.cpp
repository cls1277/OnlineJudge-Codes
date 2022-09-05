//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

//const LL maxn = ;
const double eps = 1e-7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    // freopen("data.txt","w",stdout);
    #endif
    srand(time(NULL));
    LL n=rand()%100000+1; //cout<<n<<endl;
    vector<LL> a;
    LL m=0;
    double res=0;
    LL cnt = 0;
    while(m<=5) {
        LL x = rand()%18+2;
        if(res+1.0/x<=0.5) {
            res += 1.0/x;
            // cout<<x<<' ';
            a.push_back(x);
            m++;
            cnt = 0;
        }
        cnt++;
        if(cnt==100) break;
    }
    while(m<=n&&fabs(res-0.5)<eps) {
        LL x = rand()%199999+2;
        if(res+1.0/x<=0.5) {
            res += 1.0/x;
            // cout<<x<<' ';
            a.push_back(x);
            m++;
            cnt = 0;
        }
        cnt++;
        if(cnt==100) break;
    }
    if(!m) {
        cout<<1<<endl<<2;
        return 0;
    }
    cout<<m<<endl;
    for(auto it:a) cout<<it<<' ';
    return 0;
}