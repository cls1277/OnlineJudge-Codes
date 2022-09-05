//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 1e5+5;
LL n, m, k, a[maxn];
char str[maxn], _str[maxn];

LL solve(char str1[], char str2[]) {
    LL len1 = strlen(str1), len2 = strlen(str2);
    LL len = 0, mx = 0;
    LL row = 0, col = len2-1;
    while(row<len1) {
        LL i=row, j=col;
        while(i<len1&&j<len2) {
            if(str1[i]==str2[j]) {
                len += a[j];
                mx = max(mx, len);
            } else len = 0;
            i++; j++;
        }
        if(col>0) col--;
        else row++;
    }
    return mx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>m>>k;
    cin>>str;
    Fo(i,0,m-1) cin>>a[i];
    Fo(i,1,k) {
        cin>>_str;
        cout<<solve(str, _str)<<endl;
    }
    return 0;
}
