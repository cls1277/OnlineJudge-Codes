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
        vector<LL> a(n), c(n);
        Fo(i,0,n-1) {
            cin>>a[i];
            c[i] = a[i];
        }
        if(n==1) {
            cout<<0<<endl;
            continue;
        }
        if(n==2) {
        	if(a[0]!=a[1]) cout<<0<<endl;
        	else cout<<1<<endl;
        	continue;
		}
        LL ans1=0, ans2=0;
        bool flag = 0;
        Fo(i,1,n-2) {
            if(flag) { //比两边最大的要大 
                LL b = max(a[i-1], a[i+1]);
                if(b>=a[i]) {
                    LL temp = a[i];
                    a[i] = b+1;
                    ans1 += a[i]-temp;
                }
            } else {//比两边最小的要小 
                LL b = min(a[i-1], a[i+1]);
                if(b<=a[i]) {
                    LL temp = a[i];
                    a[i] = b-1;
					ans1 += temp-a[i];
                }                
            }
            flag = !flag;
        }
        flag = 1;
        Fo(i,1,n-2) {
            if(flag) {
                LL b = max(c[i-1], c[i+1]);
                if(b>=c[i]) {
                    LL temp = c[i];
                    c[i] = b+1;
                    ans2 += c[i]-temp;
                }
            } else {
                LL b = min(c[i-1], c[i+1]);
                if(b<=c[i]) {
                    LL temp = c[i];
                    c[i] = b-1;
                    ans2 += temp-c[i];
                }                
            }
            flag = !flag;
        }
        cout<<min(ans1, ans2)<<endl;
    }
    return 0;
}
