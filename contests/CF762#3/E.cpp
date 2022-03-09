//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define INF 2147483647
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define ls x<<1
#define rs x<<1|1
#define endl '\n'

const LL maxn = 2e5+5;
LL n, a[maxn], cnt[maxn], pre;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        cin>>n; Ms(cnt,0);
        priority_queue<LL>q;
        Fo(i,1,n) {
            cin>>a[i];
            cnt[a[i]]++;
        }
        pre = 0;
        Fo(i,0,n) {
            cout<<(pre+cnt[i])<<" ";
            while(cnt[i]--) q.push(i);
            if(!q.empty()) {
                pre+=i-q.top();
                q.pop();
            } else {
                Fo(j,i+1,n) cout<<"-1 ";
                break;
            }
        }
        cout<<endl;
    }
    return 0;
}