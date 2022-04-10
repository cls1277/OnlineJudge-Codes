//By cls1277
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<stack>
#include<set>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define ls x<<1
#define rs x<<1|1
#define endl '\n'

const LL maxn = 1e3+5;
LL n, a[maxn], f[maxn];

int main() {
    ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    while(cin>>n) {
        LL p=1;
        Fo(i,1,n) cin>>a[i];
        f[1] = a[1];
        Fo(i,2,n) {
            if(a[i]>f[p]) {
                p++;
                f[p] = a[i];
                continue;
            }
            LL idx = upper_bound(f+1, f+p+1, a[i])-f;
            swap(f[idx], a[i]);
        }
        cout<<p<<endl;
    }
    return 0;
}