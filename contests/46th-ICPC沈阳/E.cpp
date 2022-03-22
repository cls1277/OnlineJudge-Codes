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
char a[maxn];
int ans;

int main() {
    // ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    scanf("%s",a); ans=0;
    if(strlen(a)<5) {
        printf("0");
        return 0;
    }
    for(int i=0; i<=strlen(a)-5; i++) {
        // cout<<a[i];
        if(a[i]=='e'&&a[i+1]=='d'&&a[i+2]=='g'&&a[i+3]=='n'&&a[i+4]=='b')
            ans++;
    }
    printf("%d",ans);
    return 0;
}