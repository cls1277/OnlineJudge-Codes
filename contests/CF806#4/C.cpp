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
    LL t; cin>>t;
    while(t--) {
        LL n; cin>>n;
        vector<LL> a;
        Fo(i,1,n) {
            LL x; cin>>x;
            a.push_back(x);
        }
        Fo(i,1,n) {
            LL m; string str; cin>>m>>str;
            for(char c:str) {
                    if(c=='D') {
                    a[i-1]++;
                    if(a[i-1]==10) a[i-1]=0;
                } else {
                    a[i-1]--;
                    if(a[i-1]==-1) a[i-1]=9;
                }
            }
            cout<<a[i-1]<<' ';
        }
        cout<<endl;
    }
    return 0;
}