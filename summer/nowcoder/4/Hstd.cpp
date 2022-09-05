//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

// const LL maxn = ;
char s[500][500];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL n; cin>>n;
    LL x=-1, y=-1;
    Fo(i,1,n) {
        LL a, b, c, d; cin>>a>>b>>c>>d;
        x = max(x, c); y = max(y, d);
        Fo(j,a,c) s[j][b] = s[j][d] = '|';
        Fo(j,b,d) s[a][j] = s[c][j] = '-';
    }
    Fo(i,0,x) {
        Fo(j,0,y) {
            cout<<s[i][j];
        }
        cout<<endl;
    }

    return 0;
}