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
LL n, a[maxn], pos, ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n;
    Fo(i,1,n) {
        cin>>a[i];
    }
    sort(a+1, a+n+1);
    if(n&1) {
        pos = a[(n+1)/2];
    } else {
        pos = a[n/2];
    }
    Fo(i,1,n) {
        ans += abs(a[i]-pos);
    }
    cout<<ans;
    return 0;
}