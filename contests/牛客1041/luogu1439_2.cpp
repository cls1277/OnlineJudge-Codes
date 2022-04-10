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
LL n, a[maxn], b[maxn], f[maxn];
unordered_map<LL, LL>mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n;
    Fo(i,1,n) {
        cin>>a[i];
        mp[a[i]] = i;
    }
    Fo(i,1,n) {
        cin>>b[i];
        b[i] = mp[b[i]];
    }
    f[1] = b[1];
    LL p = 1;
    Fo(i,2,n) {
        if(b[i]>f[p]) {
            p++;
            f[p] = b[i];
            continue;
        }
        LL idx = upper_bound(f+1, f+p+1, b[i])-f;
        swap(f[idx], b[i]);
    }
    cout<<p;
    return 0;
}