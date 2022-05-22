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
LL a[maxn], b[maxn], c[maxn], d[maxn], n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        cin>>n;
        Fo(i,1,n) {
            cin>>a[i];
            b[i] = c[i] = d[i] = a[i];
        }
        bool flag1 = 1, flag2 = 1, flag3 = 1;
        Fo(i,2,n) {
            if(abs(b[i]-(b[1]+i-1))>=2) {
                flag1 = 0;
                break;
            }
        }
        c[1] = a[1]-1;
        Fo(i,2,n) {
            if(abs(c[i]-(c[1]+i-1))>=2) {
                flag2 = 0;
                break;
            }
        }
        d[1] = a[1]+1;
        Fo(i,2,n) {
            if(abs(d[i]-(d[1]+i-1))>=2) {
                flag3 = 0;
                break;
            }
        }
        // cout<<flag1<<' '<<flag2<<' '<<flag3<<endl;   
        if(flag1||flag2||flag3) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;    
    }
    return 0;
}