//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'
#define lowbit(_) _&(-_)

//const LL maxn = ;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    // cout<<solve(t);
    // return 0;
    while(t--) {
        LL n; cin>>n;
        LL xx=0, sum=0;
        vector<LL> a(n);
        Fo(i,0,n-1) {
            cin>>a[i];
            xx ^= a[i];
            sum += a[i];
        }
        if(!xx) {
            LL cnt = 0;
            vector<bool> v(35, 1);
            Fo(i,0,n-1) {
                LL idx = int(log2(lowbit(a[i])));
                Fo(j,idx+1,31)
                    if((a[i]>>j)&1)
                        v[j] = 0;
            }
            Fo(i,0,n-1)
                if(v[int(log2(lowbit(a[i])))])
                    cnt++;
            cout<<sum<<' '<<cnt<<endl;
        } else {
            LL mx = 0, cnt = 0;
            Fo(i,0,n-1) {
                LL det = a[i]-(a[i]^xx);
                if(det>=mx) {
                    if(det>mx) {
                        mx = det;
                        cnt = 1;
                    } else if(det==mx) {
                        cnt++;
                    }
                }
            }
            cout<<sum-mx+1<<' '<<cnt<<endl;
        }
    }
    return 0;
}