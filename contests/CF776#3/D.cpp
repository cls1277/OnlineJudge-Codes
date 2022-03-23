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

const LL maxn = 2e3+5;
LL n, a[maxn], b[maxn], c[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        cin>>n; LL tn = n;
        Fo(i,1,n) {
            cin>>a[i];
            c[a[i]] = i;
        }
        Ro(i,tn,1) {
            b[i] = c[i]%i;
            LL temp[maxn];
            Fo(j,1,c[i]-1) {
                 c[a[c[i]-j]] = n-j;
                 temp[n-j] = a[c[i]-j];            
            }
            Fo(j,1,n-c[i]) {
                c[a[c[i]+j]] = j;
                temp[j] = a[c[i]+j];
            }    
            n--;
            Fo(i,1,n) a[i]=temp[i];
            // Fo(i,1,n) cout<<i<<":"<<c[i]<<endl;
        }
        Fo(i,1,tn)
            cout<<b[i]<<" ";
        cout<<endl;
        // return 0;
    }
    return 0;
}