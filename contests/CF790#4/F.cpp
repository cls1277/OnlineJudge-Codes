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
    int t; cin>>t;
    while(t--) {
        int n, k; cin>>n>>k;
        map<int, int>cnt;
        Fo(i,0,n-1) {
            int x; cin>>x;
            cnt[x]++;
        }
        vector<int> a(cnt.size()); int top=0;
        for(auto it:cnt) {
            if(it.second<k) continue;
            a[top++] = it.first;
        }
        if(!top) {
            cout<<"-1"<<endl;
            continue;
        }
        int l=a[0], r=a[0], c=1, ans=0;
        int resl=l, resr=r;
        Fo(i,1,top-1) {
            if(a[i]==l+c) {
                c++;
            } else {
                c = 1;
                r = a[i-1];
                if(r-l>ans) {
                    resr = r;
                    resl = l;
                    ans = r-l;
                }
                // ans = max(ans, r-l);
                l = r = a[i];
            }
        }
        r = a[top-1];
        // ans = max(ans, r-l);
        if(r-l>ans) {
            resr = r;
            resl = l;
            ans = r-l;
        }
        cout<<resl<<' '<<resr<<endl;
    }
    return 0;
}