//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 55;
const LL maxm = 51;
LL n, a[maxn], p[maxn];

void insert() {
    Fo(i,1,n) {
        LL x = a[i];
        Ro(j,maxm,0) {
            if(x&(1LL<<j)) {
                if(!p[j]) {
                    p[j] = x;
                    break;
                } else {
                    x^=p[j];
                }
            }
        }
    }
}

LL maxXor() {
    LL ans = 0;
    Ro(i,maxm,0) {
        if((ans^p[i])>ans) {
            ans ^= p[i];
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n;
    Fo(i,1,n) cin>>a[i];
    insert();
    cout<<maxXor();
    return 0;
}