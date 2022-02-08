//By cls1277
#include<bits/stdc++.h>
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

const LL maxn = 1e5+5;

int pri[maxn] , cnt , phi[maxn];
bool vis[maxn];
void getphi(int maxx) {
    Fo(i,2,maxx) {
        if(!vis[i]) {
            pri[cnt++] = i;
            phi[i] = i-1;
        }
        Fo(j,0,cnt-1) {
            if(i*pri[j]>maxx) break;
            vis[i*pri[j]] = 1;
            if(i%pri[j]==0) {
                phi[i*pri[j]] = phi[i]*pri[j];
                break;
            } else {
                phi[i*pri[j]] = phi[i]*(pri[j]-1);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    getphi(10);
    Fo(i,1,10)
        cout<<i<<":"<<phi[i]<<endl;
    return 0;
}