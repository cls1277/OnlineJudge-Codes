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
LL a[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        LL n; cin>>n;
        Fo(i,1,n) cin>>a[i];
        if(n==1) cout<<"YES"<<endl;
        else {
            LL maxx = 0, idx;
            Fo(i,1,n) {
                if(a[i]>maxx) {
                    maxx = a[i];
                    idx = i;
                }
            }
            LL cnt = 0;
            Fo(i,1,n)
                if(a[i]==maxx)
                    cnt++;
            if(cnt==1&&idx==n) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        //     bool flag = true;
        //     Fo(i,1,n) {
        //         LL j; bool op = false;
        //         for(j=i+1;j<=n;j++) {
        //             if(a[j]>a[i]||a[i]==n) {
        //                 if(a[i]==n) {
        //                     if(a[j]!=j-i) {
        //                         flag = false;
        //                         break;
        //                     } else op=true;
        //                 }
        //                 if(a[j]>a[i]) {
        //                     if(a[j]-a[i]!=j-i) {
        //                         flag = false;
        //                         break;
        //                     } else op=true;
        //                 }
        //             } else {
        //                 if(!op) flag = false;
        //                 i = j - 1;
        //                 break;
        //             }
        //         }
        //         if(!flag) break;
        //         if(j==n+1) break;
        //     }
        //     if(flag) cout<<"YES"<<endl;
        //     else cout<<"NO"<<endl;
        // }
    }
    return 0;
}