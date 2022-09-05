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
char a[maxn];

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
     scanf("%s",a);
    bool flag = 0;
    for(int i=0; i<strlen(a)-1; i++) {
        if(a[i]!='9') {
            flag = 1;
            break;
        }
    }
    LL l = strlen(a);
    if(!flag) {
        for(int i=0; i<l-1; i++) printf("9");
        printf("%c",a[l-1]);
    }  else {
        for(int i=0; i<l-1; i++) printf("9");
    }
    return 0;
}
