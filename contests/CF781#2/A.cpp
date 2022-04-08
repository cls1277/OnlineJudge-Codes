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
    LL t; cin>>t;
    while(t--) {
        LL x; cin>>x;
        if(x%4==0) cout<<x/4<<' '<<x/4<<' '<<x/4<<' '<<x/4<<endl;
        else if(x%4==1) {
            if(x!=5)  cout<<"2 "<<x-5<<" 2 1"<<endl;
            else  cout<<"2 1 1 1"<<endl;
        }
        else if(x%4==2) cout<<(x-2)/2+1<<" "<<(x-2)/2-1<<" 1 1"<<endl;
        else cout<<(x-2)/2<<' '<<(x-2)/2+1<<" 1 1"<<endl;
    }
    return 0;
}