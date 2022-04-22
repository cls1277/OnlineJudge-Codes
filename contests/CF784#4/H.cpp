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
LL a[maxn], q[31]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        LL n, k, ans=0; cin>>n>>k;
        Fo(i,1,n) {
            cin>>a[i];
        }
        Ro(i,30,0) {
            LL cnt = 0, b=0;
            for(int j=1; j<=n; j++) {
                if(a[j]<q[i]) {
                    cnt++;
                    continue;
                }
//                LL temp = (a[j]>>i)&1;
                if(((a[j]>>i)&1)==0) {
                    cnt++;
                } else {
                	b++;
				}
            }
            if(cnt<=k||b==n) {
                ans+=q[i];	
                k-=cnt;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
