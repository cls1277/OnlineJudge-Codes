//By cls1277
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<stack>
#include<set>
using namespace std;
typedef long long LL;
#define PI acos(-1)
#define INF 2147483647
#define eps 1e-7
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define lowbit(_) _&(-_)
#define mk(_,__) make_pair(_,__)
#define pii pair<int,int>
#define ls x<<1
#define rs x<<1|1
#define endl '\n'
inline LL read() {
    LL x = 0, f = 1;char c = getchar();
    while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
    while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
    return x * f;
}

const LL maxn = 2e5+5;
LL a[maxn], b[maxn], n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        bool flag = 1;
        LL last = 0;
        cin>>n;
        Fo(i,1,n) cin>>a[i];
        Fo(i,1,n) cin>>b[i];
        Ro(i,n,1) {
            if(i-1>=1&&b[i]==b[i-1]) {
                bool op = 0; LL idx = 0;
                Ro(j,i-1,1) {
                    if(a[j+1]==b[j]) {
                        if(j+1!=i&&a[j+1]==b[i]) {
                            op = 1;
                            idx = j+1;
                        }
                    } else {
                        if(a[j+1]==b[i]) {
                            op = 1;
                            idx = j+1;
                        }
                        if(op) {
                            i = idx;
                        }
                        break;
                    }
                }
            } else if(a[i]==b[i]) {
                continue;
            } else {
                flag = 0;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
