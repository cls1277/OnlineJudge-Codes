//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

// const LL maxn = 10;
LL a[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    Fo(i,0,9) a[i]=2021;
    LL ans = 0;
    while(1) {
        ans++;
        LL temp = ans;
        bool flag = true;
        while(temp) {
            LL k = temp%10;
            temp/=10;
            a[k]--;
            if(a[k]<0) {
                flag = false;
                break;
            }
        }
        if(!flag) {
            cout<<ans-1;
            break;
        }
    }
    return 0;
}