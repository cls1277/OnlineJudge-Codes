//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 2e4+5;
LL V, a[7], v[maxn*6], idx, f[maxn*6];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL tt = 0;
    while(1) {
        // cout<<(++tt)<<endl;
        V = 0; idx = 0;
        Fo(i,1,6) {
            cin>>a[i];
            V += a[i]*i;
        }
        if(!V) break;
        if(V%2) {
            cout<<"Can't"<<endl;
            continue;
        }
        Fo(i,0,V) f[i]=0;
        Fo(i,1,6) {
            LL k = 1;
            while(a[i]>=k) {
                idx++;
                v[idx] = i*k;
                a[i]-=k;
                k<<=1;
            }
            if(a[i]) {
                idx++;
                v[idx] = i*a[i];
            }
        }
        V>>=1;
        Fo(i,1,idx)
            Ro(j,V,v[i])
                f[j] = max(f[j], f[j-v[i]]+1);
        if(f[V]) cout<<"Can"<<endl;
        else cout<<"Can't"<<endl;
    }
    return 0;
}