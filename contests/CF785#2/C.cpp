//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 4e4+5;
const LL mod = 1e9+7;
int f[maxn][505], m;

bool isP(int x) {
    int tmp = x;
    int res = 0;
    while(x) {
        res = res*10+x%10;
        x /= 10;
    }
    return (tmp==res);
}

void init() {
    vector<int> a;
    a.push_back(0);
    Fo(i,1,40000) {
        if(isP(i)) {
            a.push_back(i);
        }
    }
    m = a.size()-1;
    Fo(i,1,m) f[0][i] = 1;
    Fo(i,1,40000) {
        Fo(j,1,m) {
            if(i<a[j]) {
                f[i][j] = f[i][j-1];
            } else {
                f[i][j] = (f[i][j-1]+f[i-a[j]][j])%mod;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    init();
    int t; cin>>t;
    while(t--) {
        int x; cin>>x;
        cout<<f[x][m]<<endl;
    }
    return 0;
}