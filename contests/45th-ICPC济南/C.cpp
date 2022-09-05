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
LL a, b, c;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>a>>b>>c;
    LL ans = 0;
    if(a==b) {
        ans += 2*a;
    } else if(a<b) {
        ans += 2*a;
        b -= a;
        if(b%3==0) {
            ans += b*2;
        } else if(b%3==1) {
            ans += (b-1)*2;
        } else {
            ans += (b-2)*2+4;
        }
    } else {
        ans += 2*b;
        a -= b;
        if(a%3==0) {
            ans += a;
        } else if(a%3==1) {
            ans += a-1;
        } else {
            ans += a-1;
        }
    }
    cout<<ans;
    return 0;
}