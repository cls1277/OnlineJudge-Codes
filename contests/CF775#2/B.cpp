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
LL n, a[maxn], sum;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        cin>>n;
        LL mx = 0;
        sum = 0;
        Fo(i,1,n) {
            cin>>a[i];
            sum += a[i];
            mx = max(mx, a[i]);
        }
        if(!sum) cout<<0<<endl;
        else if(mx<=sum-mx) cout<<1<<endl;
        else cout<<mx-(sum-mx)<<endl;
    }
    return 0;
}