//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define ls x<<1
#define rs x<<1|1
#define endl '\n'

const LL maxn = 135000;
LL l, r, a[maxn], b[maxn], n, c[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        cin>>l>>r; n=r-l+1;
        Fo(i,1,n) cin>>a[i];
        sort(a+1, a+n+1);
        LL pre=1, cnt=0, sum=n+1;
        while(cnt<n) {
            cnt++; LL i=pre;
            // cout<<i<<" ";
            bool flag = true;
            Ms(c,0);
            Fo(j,1,n) b[j]=a[j]^a[i];
            Fo(j,1,n) c[b[j]]++;
            Fo(j,0,n-1) if(!c[j]) {flag=false; break;}
            if(flag) {cout<<a[i]<<endl; break; }
            pre = sum-pre;
            sum = 2*n+3-sum;
        }
        // cout<<endl;
        // Fo(i,1,n) {
        //     bool flag = true;
        //     Ms(c,0);
        //     Fo(j,1,n) b[j]=a[j]^a[i];
        //     Fo(j,1,n) c[b[j]]++;
        //     Fo(j,0,n-1) if(!c[j]) {flag=false; break;}
        //     if(flag) {cout<<a[i]<<endl; break; }
        // }
    }
    return 0;
}