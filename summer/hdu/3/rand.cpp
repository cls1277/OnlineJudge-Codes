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
queue<LL> q1, q2, q3;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    // freopen("data.txt","r",stdin);
    //  freopen("data.txt","w",stdout);
    #endif
    srand(time(NULL));
    LL t = 1;
    cout<<t<<endl;
    while(t--) {
        LL n = 3; cout<<n;
        LL H = rand()%20+1; cout<<' '<<H<<endl;
        Fo(i,1,n) {
            LL t=rand()%5+1, len=rand()%5+1;
            cout<<t<<' '<<len<<endl;
            Fo(i,1,len) {
                cout<<rand()%3+1<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}
