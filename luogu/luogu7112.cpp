//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 605;
LL n, a[maxn][maxn], mod;

LL det() {
    LL ans=1, w=1;
    Fo(i,1,n) {
        Fo(j,i+1,n) {
            while(a[i][i]) {
                LL div = a[j][i]/a[i][i];
                Fo(k,i,n) a[j][k] = (a[j][k]-div*a[i][k]%mod+mod)%mod;
                swap(a[i], a[j]);
                w *= (-1);
            }
            swap(a[i], a[j]);
            w *= (-1);
        }
    }
    ans = w;
    Fo(i,1,n) ans=ans*a[i][i]%mod;
    return (ans%mod+mod)%mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>mod;
    Fo(i,1,n)
        Fo(j,1,n)
            cin>>a[i][j];
    cout<<det()<<endl;
    return 0;
}
