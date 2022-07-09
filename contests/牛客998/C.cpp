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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    int n;  cin>>n;
    vector<int> a;
    for(int i=1; i<=n; i++) a.push_back(i);
    do {
        for(auto it:a) cout<<it<<' ';
        cout<<endl;
    }while(next_permutation(a.begin(), a.end()));
    return 0;
}