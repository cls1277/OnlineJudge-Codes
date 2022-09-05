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

inline LL read() {
	LL x = 0, f = 1;char c = getchar();
	while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
	while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
	return x * f;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; t=read(); //cin>>t;
    while(t--) {
        LL n; n=read(); //cin>>n;
        vector<LL> a(n), b(n);
        Fo(i,0,n-1) a[i]=read(); //cin>>a[i];
        sort(a.begin(), a.end());
        LL p=a.size()-1, q=0, cnt=0;
        while(1) {
            b[cnt++] = a[p--];
            if(cnt==n) break;
            b[cnt++] = a[q++];
            if(cnt==n) break;
        }
        bool flag = 0;
        for(int i=0; i<n-2; i++) {
            if(b[i+2]-b[i+1]==b[i+1]-b[i]) {
                flag = 1;
                break;
            }
        }
        if(flag) printf("NO\n"); //cout<<"NO"<<endl;
        else {
            printf("YES\n"); 
            for(auto it:b) printf("%lld ",it);
            printf("\n");
            // cout<<"YES"<<endl;
            // for(auto it:b) cout<<it<<' ';
            // cout<<endl;
        }
    }
    return 0;
}