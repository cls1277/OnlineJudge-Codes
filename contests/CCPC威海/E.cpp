//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 15;
LL a[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL n, k; cin>>n>>k;
    LL ans = -1;
    Fo(i,1,n) {
        cin>>a[i];
        if(a[i]<k) {
            ans = i;
            break;
        }
    }
    if(ans!=-1) {
        cout<<"Python 3."<<ans<<" will be faster than C++";
        return 0;
    }
    LL a1=a[n-1], a2=a[n];
    if(a2>=a1) {
        cout<<"Python will never be faster than C++";
        return 0;
    }
    if((2*a1-a2-k)%(a2-a1)==0) {
        ans = (2*a1-a2-k)/(a2-a1) + 1;
    } else {
        ans = ceil((k+a2-2*a1)*1.0/(a2-a1));
    }
    cout<<"Python 3."<<ans+n-2<<" will be faster than C++";
    return 0;
}