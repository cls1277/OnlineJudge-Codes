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
map<LL, vector<LL>> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("A.txt","r",stdin);
    #endif
    LL n; cin>>n;
    vector<LL> a(n+1);
    Fo(i,1,n) cin>>a[i];
    Fo(i,1,2*n) {
        LL x; cin>>x;
        mp[x].push_back(i);
    }
    bool flag = 0;
    Fo(i,1,n) {
        for(int j=0; j<int(mp[i].size())-1; j++) {
            if(mp[i][j+1]-mp[i][j]>a[i]) {
                flag = 1;
                break;
            }
        }
        if(int(mp[i].size())&&mp[i][0]-1+2*n-mp[i][int(mp[i].size())-1]>a[i]) {
            flag = 1;
            break;
        }
    }
    if(flag) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    return 0;
}
