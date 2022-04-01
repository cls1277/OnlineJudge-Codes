//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 1e12;
set<LL>a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    // for(LL i=1; i<=maxn; i<<=1)
        // cout<<i<<" ";
        // a.insert(i);
    LL mul = 1;
    Fo(i,1,100) {
        mul = mul*i;
        if(mul>maxn) break;
        // cout<<mul<<" ";
        a.insert(mul);
    }
    for(auto &it:a) cout<<it<<",";
    return 0;
}