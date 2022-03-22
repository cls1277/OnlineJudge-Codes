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
    // freopen("data.txt","w",stdout);
    #endif
    srand(time(NULL));
    LL n = 5; LL m=3;
    cout<<n<<" "<<m<<endl;
    Fo(i,1,m) {
        LL a=rand()%n+1, b=rand()%n+1, w=rand()%2+1;
        cout<<a<<" "<<b<<" "<<w<<endl;
    }
    return 0;
}