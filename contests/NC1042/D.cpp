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
LL n, m, a[105], c[105], used[100005];
bool f[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    while(cin>>n>>m&&n&&m) {
        Ms(f, 0);
        Fo(i,1,n) cin>>a[i];
        Fo(i,1,n) cin>>c[i];
        f[0] = 1;
        Fo(i,1,n) {
            Ms(used, 0);
            Fo(j,a[i],m)
                if(!f[j]&&f[j-a[i]]&&used[j-a[i]]<c[i]) {
                    f[j] = 1;
                    used[j] = used[j-a[i]]+1;
                }
        }
        LL cnt = 0;
        Fo(i,1,m)
            if(f[i])
                cnt++;
        cout<<cnt<<endl;
    }
    return 0;
}