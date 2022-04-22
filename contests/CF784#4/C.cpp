//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 55;
int a[maxn], b[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t, n; cin>>t;
    while(t--) {
        int idx1=0, idx2=0;
        cin>>n;
        if(n==1) {
            cout<<"YES"<<endl;
            continue;
        }
        Fo(i,1,n) {
            LL x; cin>>x;
            if(i%2==0) a[++idx1] =x;
            else b[++idx2] = x; 
        }
        int f = a[1]%2;
        bool flag = false;
        Fo(i,2,idx1) {
            if(a[i]%2!=f) {
                cout<<"NO"<<endl;
                flag = 1;
                break;
            }
        }
        if(flag) continue;
        f = b[1]%2; flag=0;
        Fo(i,2,idx2) {
            if(b[i]%2!=f) {
                cout<<"NO"<<endl;
                flag = 1;
                break;
            }
        }
        if(flag) continue;
        cout<<"YES"<<endl;
    }
    return 0;
}