//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 35;
LL n, m, b[maxn];
vector<pair<string, LL>> a;

bool judge(int idx, int x) {
    for(auto it:a) {
        if(it.first[0]=='A') {
            x &= ((it.second>>idx)&1);
        } else if(it.first[0]=='O') {
            x |= ((it.second>>idx)&1);
        } else if(it.first[0]=='X') {
            x ^= ((it.second>>idx)&1);
        }
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>m;
    Fo(i,1,n) {
        string str; int num;
        cin>>str>>num;
        a.push_back({str, num});
    }
    LL res = 0, op = 1;
    Fo(i,0,31) {
        if(res+op>m) {
            b[i] = 0;
        } else if(judge(i,0)==0&&judge(i,1)==1) {
            b[i] = 1;
            res += op;
            op *= 2;
        }
    }
    LL ans = 0; op = 1;
    Fo(i,0,31) {
    	ans += judge(i, b[i])*op;
    	op *= 2;
	}
	cout<<ans;
    return 0;
}
