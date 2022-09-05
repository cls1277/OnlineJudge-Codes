//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 105;
LL n, sum, cnt[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        cin>>n;
        Fo(i,1,n) cnt[i]=0;
        sum = 0;
        Fo(i,1,n) {
            sum += i*(n+1-i);
            cnt[n+1-i] = i;
        }
        LL L = int(sqrt(sum));
        LL row, col;
        Ro(i,L,1) {
            if(sum%i==0) {
                row = i;
                col = sum/i;
                break;
            }
        }
        cout<<(row+col)*2<<endl;
        Fo(i,0,row-1) {
            LL x = col, y = 0;
            Ro(j,n,1) {
                if(!cnt[j]) continue;
                LL d = min(x/j, cnt[j]);
                Fo(k,1,d) {
                    cout<<y<<' '<<i<<' '<<y+j<<' '<<i+1<<endl;
                    y += j;
                    cnt[j]--;
                    x -= j;
                }
                if(!x) break;
            }
        }
    }
    return 0;
}