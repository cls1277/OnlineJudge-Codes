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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    // freopen("data.txt","w",stdout);
    #endif
    Fo(n,1,50000) {
    // LL n = 30;
    vector<double> a(n+1);
    // cin>>n;
    Fo(i,1,n) {
        bool flag = 0;
        for(int j=2; j*j<=i; j++) {
            if(i%(j*j)==0) {
                flag = 1;
                a[i] = 1e9;
                break;
            }
        }
        if(!flag) a[i] = i;
    }
    // Fo(i,1,n) cout<<a[i]<<' ';
    double ans = 1e9;
    int idx = -1;
    // Fo(i,1,n) {
        LL i = 30;
        double res = 0;
        for(int j=1; j<=sqrt(i); j++) {
            if(i%j==0) {
                res += 1.0/a[j];
                if(j*j!=i) {
	                res += 1.0/a[i/j];
	            }
            }
        }
        res = 1/res;
        if(res<ans) {
            ans = res;
            idx = i;
        }
    // }
    cout<<idx<<' '<<ans<<endl;
    }
    return 0;
}
