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
LL n, a[maxn], c[maxn], pre[maxn], f[maxn];
int e[maxn];

LL sgn(LL x) {
    if(x>0) return 1;
    else if(x<0) return -1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        cin>>n; Ms(c, 0); Ms(e, 0);
        LL last, op;
        Fo(i,1,n) {
            cin>>a[i];
            if(i==1||e[i-1]==0) {
                e[i] = sgn(a[i]);
                if(e[i-1]==0) pre[i] = i;
                else pre[i] = pre[i-1];
            }
            else {
                if(a[i]<0) {
                    if(e[i-1]>0) e[i] = -1;
                    else e[i] = 1;
                } else if(a[i]>0) e[i] = e[i-1];
                pre[i] = pre[i-1];
            }
            c[i] = c[i-1];
            if(abs(a[i])==2) {
                c[i]++;
                if(!pre[i]) pre[i] = i;
            }
        }
        LL l[3]; Ms(l, 0);
        Fo(i,1,n) {
            f[i] = l[e[i]+1];
            l[e[i]+1] = i;
        }
        LL mx = 0, idx = 0;
        Fo(i,1,n) {
            if(c[i]>mx) {
                mx = c[i];
                idx = i;
            }
        }
        cout<<f[idx]<<" "<<n-idx<<endl;
    }
    return 0;
}