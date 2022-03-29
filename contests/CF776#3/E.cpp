//傻逼题 写不出来
/*
asfafda；
ds；vds
as
fd
s;fds
g;
fsd;fg
vsdfg;
fsd;f;d
s;f
s;f;gf's;g's;df;d
s'f
af;d
';f
;sf;s'f;
s;
f;
sf;d
s;fd
;s
f;dds
';fd
s;
f;ds
f;ds;f'
;sf'gdl
dsgfvg'dlbmf
,fsdfa
vgf;a
vbga;b
a;b';ad
;fad;b
a;ba;
ab;a;ab
'fb;a;b
a;b'a;bf;a
*/
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
LL n, d, a[maxn];

bool judge(LL x) {
    LL cnt = 0, pre = 0, op = 0;
    bool flag = false;
    Fo(i,1,n) {
        // if(i==2) cout<<op<<endl;
        if(cnt>=0&&a[i]-a[i-1]-1<x) {
            if(i+1<=n&&a[i+1]-a[i-1]-1>=2*x+1) {
                flag = true;
                pre = i+2;
                break;
            }
            if(i-2>=0&&a[i]-a[i-2]-1>=2*x+1) {
                flag = true;
                pre = i+2;
                break;
            }
            if(d-a[n]-1>=2*x+1) {
                flag = true;
                pre = i+2;
                break;
            }
            op = i;
            cnt--;
        } else {
            if(op==i-1) {
                if(i-2>=0&&a[i]-a[i-2]-1>=x&&cnt<0) {
                    flag = true;
                    pre = i+2;
                    break;
                } 
            } else {
                if(a[i]-a[i-1]-1>=2*x+1&&cnt<0) {
                    flag = true;
                    pre = i+2;
                    break;
                }
            }
        }
        // cout<<cnt;
        // exit(0);
    }
    Fo(i,pre,n) 
        if(a[i]-a[i-1]-1<x) return false;
    pre--;
    if(pre-2>=0&&a[pre]-a[pre-2]-1<x) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL  t; cin>>t;
    while(t--) {
        cin>>n>>d;
        a[0] = 0;
        Fo(i,1,n) cin>>a[i];
        LL l=INT_MAX, r=d;
        Fo(i,1,n) l=min(l, a[i]-a[i-1]-1);
        cout<<judge(3)<<endl;
        return 0;
        while(l<r) {
            LL mid=(l+r+1)>>1;
            if(judge(mid)) l=mid;
            else r=mid-1;
        }
        cout<<l<<endl;
        Fo(i,1,n) a[i]=0;
    }
    return 0;
}