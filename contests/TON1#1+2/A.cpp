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

const LL maxn = 1e5+5;
LL n, a[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        LL n; cin>>n;
        Fo(i,1,n) cin>>a[i];
        LL mx=0, mn=INT_MAX, xd=0, nd=0;
        Fo(i,1,n) {
            if(a[i]>mx) {
                mx = a[i];
                xd = i;
            }
            if(a[i]<mn) {
                mn = a[i];
                nd = i;
            }
        }
        cout<<nd<<" "<<xd<<endl;
    }
    return 0;
}