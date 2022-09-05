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
bool vis[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    // freopen("data.txt","r",stdin);
    // freopen("data.txt","w",stdout);
    #endif
    srand(time(NULL));
    LL t; t=1;
    cout<<t<<endl;
    while(t--) {
        LL n=rand()%10+1, m=rand()%n+1;
        cout<<n<<' '<<m<<endl;
        Fo(i,1,n) {
            LL x=rand()%10+1, y=rand()%15+1;
            while(vis[x]) {
                x = rand()%10+1;
            }
            vis[x] = 1;
            cout<<x<<' '<<y<<endl;
        }
    }
    return 0;
}