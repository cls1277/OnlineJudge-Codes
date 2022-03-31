//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 2e5+5;
LL n, a[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        cin>>n;
        Fo(i,1,n) cin>>a[i];
        if(n==1) {
            if(a[1]>=2) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
            continue;
        }
        sort(a+1, a+n+1);
        LL b=a[n], c=a[n-1];
        LL d = b-c;
        if(d>=2) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}