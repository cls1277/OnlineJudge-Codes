//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 1e6+5;
const LL mod = 998244353;
LL len2, nxt[maxn];
char s2[maxn];

void Next() {
	LL p1=0, p2=-1;
	nxt[0] = -1;
	while(p1<len2) {
		if(p2==-1||s2[p1]==s2[p2]) nxt[++p1] = ++p2;
		else p2 = nxt[p2];
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        cin>>s2; len2 = strlen(s2);
        Next();
        Fo(i,1,len2) cout<<nxt[i]<<' ';
        
    }
    return 0;
}