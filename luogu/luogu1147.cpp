//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

//const LL maxn = ;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL M; cin>>M;
    LL p1=1, p2=2, sum=3;
    while(p1<=M/2) {
        if(sum==M) {
            cout<<p1<<' '<<p2<<endl;
            sum -= p1;
            p1 ++;
        } else if(sum<M) {
            p2 ++;
            sum += p2;
        } else {
            sum -= p1;
            p1 ++;
        }
    }
    return 0;
}