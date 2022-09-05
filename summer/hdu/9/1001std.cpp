//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 5e3+5;
LL a[maxn], b[maxn<<1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        LL n; cin>>n;
        Fo(i,1,n) cin>>a[i];
        sort(a+1, a+n+1);
        vector<LL> c, d, e;
        Ro(i,n,n/2) c.push_back(a[i]);
        Ro(i,n/2-1,1) d.push_back(a[i]);
        LL cnt = 0, p=0, q=0;
        while(1) {
            if(p!=c.size()) {
                if(cnt>=2) {
                    if(b[5000+cnt]==b[5000+cnt-1]&&b[5000+cnt]==c[p]) {
                        e.push_back(c[p]);
                        p++;
                    } else {
                        cnt++;
                        b[5000+cnt] = c[p];
                        p++;
                    }
                } else {
                    cnt++;
                    b[5000+cnt] = c[p];
                    p++;
                }
            }
            if(cnt==n) break;
            if(q!=d.size()) {
                if(cnt>=2) {
                    if(b[5000+cnt]==b[5000+cnt-1]&&b[5000+cnt]==d[q]) {
                        e.push_back(d[q]);
                        q++;
                    } else {
                        cnt++;
                        b[5000+cnt] = d[q];
                        q++;
                    }
                } else {
                    cnt++;
                    b[5000+cnt] = d[q];
                    q++;
                }                
            }
            if(cnt==n) break;
            if(p==c.size()&&q==d.size()) break;
        }
        LL cnt1 = cnt;
        // for(auto it:e) cout<<it<<' ';
        sort(e.begin(), e.end());
        c.clear(); d.clear();
        LL _n = e.size();
        Ro(i,_n-1,_n/2) c.push_back(e[i]);
        Ro(i,_n/2-1,0) d.push_back(e[i]);
        e.clear();
        cnt = 0, p=0, q=0;
        while(1) {
            if(p!=c.size()) {
                if(5002-cnt<=5000+cnt1) {
                    if(b[5001-cnt]==b[5002-cnt]&&b[5002-cnt]==c[p]) {
                        e.push_back(c[p]);
                        p++;
                    } else {
                        cnt++;
                        b[5001-cnt] = c[p];
                        p++;
                    }
                } else {
                    cnt++;
                    b[5001-cnt] = c[p];
                    p++;
                }
            }
            if(cnt==_n) break;
            if(q!=d.size()) {
                if(5002-cnt<=5000+cnt1) {
                    if(b[5001-cnt]==b[5002-cnt]&&b[5002-cnt]==d[q]) {
                        e.push_back(d[q]);
                        q++;
                    } else {
                        cnt++;
                        b[5001-cnt] = d[q];
                        q++;
                    }
                } else {
                    cnt++;
                    b[5001-cnt] = d[q];
                    q++;
                }                
            }
            if(cnt==_n) break;
            if(p==c.size()&&q==d.size()) break;
        }
        if(e.size()) cout<<"NO"<<endl;
        else {
            cout<<"YES"<<endl;
            Fo(i,5001-cnt,5000+cnt1) cout<<b[i]<<' ';
            cout<<endl;
        }
    }
    return 0;
}
