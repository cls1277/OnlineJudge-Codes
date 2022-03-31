//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 2e5+5;
LL n, a[maxn], c[maxn];
bool e[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        cin>>n; Ms(c, 0); Ms(e, 0);
        vector<LL>b, d;
        LL cnt = 0, res = 0, l, r, z;
        Fo(i,1,n) {
            cin>>a[i];
            if(i==1||a[i-1]==0) {
                if(a[i]>0) e[i] = 1;
                else e[i] = 0;
            } else {
                if(a[i]<0) {
                    if(e[i-1]>0) e[i] = 0;
                    else e[i] = 1;
                }
            }
            c[i] = c[i-1];
            if(a[i]==2) c[i]++;
            if(!a[i]) b.push_back(i); 
            if(a[i]<0) d.push_back(i);
        }
        cnt = b.size();
        res = d.size();
        if(!cnt) {
            if(res%2==0) cout<<"0 0"<<endl;
            else {
                if(res==1) {
                    l = c[d[0]];
                    r = c[n]-c[d[0]];
                    // cout<<l<<" "<<r<<endl;
                    if(l<r) cout<<d[0]<<" 0"<<endl;
                    else cout<<"0 "<<n-d[0]+1<<endl;
                } else {
                    if(a[d[0]]<a[d[res-1]]) cout<<"0 "<<n-d[res-1]+1<<endl;
                    else cout<<d[0]<<" 0"<<endl;
                }
            }
        } else if(cnt==1) {
            if(b[0]==1) {
                if(e[n]) cout<<"1 0"<<endl;
                else cout<<n<<" 0"<<endl;
                continue;
            }
            l = e[b[0]-1];
            r = e[n];
            if(l&&!r) {
                cout<<"0 "<<n-b[0]+1<<endl;
            } else if(!l&&r) {
                cout<<b[0]<<" 0"<<endl;
            } else if(!l&&!r) {
                cout<<n<<" 0"<<endl;
            } else if(l&&r) {
                l = c[b[0]];
                r = c[n];
                if(l<r) cout<<b[0]<<" 0"<<endl;
                else cout<<"0 "<<n-b[0]+1<<endl;
            }
        } else if(cnt==2) {
            if(b[0]==1) {
                l = e[b[1]-1];
                r = e[n];
                if(l&&!r) {
                    cout<<"1 "<<n-b[1]+1<<endl;
                } else if(!l&&r) {
                    cout<<b[1]<<" 0"<<endl;
                } else if(!l&&!r) {
                    cout<<n<<" 0"<<endl;
                } else if(l&&r) {
                    l = c[b[1]];
                    r = c[n];
                    if(l<r) cout<<b[1]<<" 0"<<endl;
                    else cout<<"1 "<<n-b[0]+1<<endl;
                }
                continue;
            }
            l = e[b[0]-1];
            r = e[b[1]-1];
            z = e[n];
            LL mx = 0;
            if(l&&r&&!z) {
                mx = max(l, r);
                if(mx==l) cout<<"0 "<<b[0]<<endl;
                else cout<<b[0]<<" "<<n-b[1]+1<<endl;
            } else if(l&&!r&&z) {
                mx = max(l, z);
                if(mx==l) cout<<"0 "<<b[0]<<endl;
                else cout<<n-b[1]+1<<" 0"<<endl;
            } else if(!l&&r&&z) {
                mx = max(r, z);
                if(mx==r) cout<<b[0]<<" "<<n-b[1]+1<<endl;
                else cout<<n-b[1]+1<<" 0"<<endl;
            } else if(l&&!r&&!z) {
                cout<<"0 "<<b[0]<<endl;
            } else if(!l&&r&&!z) {
                cout<<b[0]<<" "<<n-b[1]+1<<endl;
            } else if(!l&&!r&&z) {
                cout<<n-b[1]+1<<" 0"<<endl;
            } else {
                l = c[b[0]];
                r = c[b[1]]-c[b[0]];
                z = c[n]-c[b[1]];
                LL mx = max({l, r, z});
                if(mx==l) cout<<"0 "<<b[0]<<endl;
                else if(mx==r) cout<<b[0]<<" "<<n-b[1]+1<<endl;
                else if(mx==z) cout<<n-b[1]+1<<" 0"<<endl;
            }
        } else {
            l = c[b[0]];
            r = c[n]-c[b[cnt-1]];
            if(l<r) cout<<b[cnt-1]<<" 0"<<endl;
            else cout<<"0 "<<n-b[0]+1<<endl;
        }
    }
    return 0;
}