//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define INF 2147483647
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define ls x<<1
#define rs x<<1|1
#define endl '\n'

// const LL maxn = ;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        LL n, m, k;
        cin>>n>>m>>k;
        LL s=n%m, b=m-s, t=1, temp=1;
        Fo(i,1,k) {
            t= temp;
            Fo(j,1,s) {
                cout<<n/m+1<<" ";
                Fo(l,1,n/m+1) {
                    cout<<t<<" ";
                    t=t%n+1;
                }
                cout<<endl;
            }
            temp = t;
            Fo(j,1,b) {
                cout<<n/m<<" ";
                Fo(l,1,n/m) {
                    cout<<t<<" ";
                    t=t%n+1;
                }
                cout<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}