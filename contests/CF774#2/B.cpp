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
        sort(a+1, a+n+1);
        LL sum1=0, sum2=0;
        if(n%2) {
            Fo(i,1,n/2+1) sum1+=a[i];
            Fo(i,n/2+2,n) sum2+=a[i];
        } else {
            Fo(i,1,n/2) sum1+=a[i];
            Fo(i,n/2+2,n) sum2+=a[i];
        }
        // cout<<sum1<<" "<<sum2<<endl;
        if(sum1<sum2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}