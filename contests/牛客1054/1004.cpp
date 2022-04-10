//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 85;
LL a[maxn], b[maxn], f[maxn][maxn], len1, len2;
LL g[maxn][maxn], h[maxn][maxn];
char c[maxn];
set<string>st;

void dfs(LL p1, LL p2, string s, LL l) {
    // if(p1<0||p2<0) return ;
    if(l==0) {
        st.insert(s);
        return ;
    }
    if(!p1||!p2) return ;
    Fo(i,0,25) {
        LL p=g[i][p1], q=h[i][p2];
        if(f[p][q]>=l) {
            char ch = i+'a';
            dfs(p-1, q-1, ch+s, l-1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>(c+1);
    len1 = strlen(c+1);
    Fo(i,1,len1) a[i] = c[i]-'a';
    cin>>(c+1);
    len2 = strlen(c+1);
    Fo(i,1,len2) {
        b[i] = c[i]-'a';
        f[0][i] = 0;
    }
    Fo(i,1,len1) {
        f[i][0] = 0;
        Fo(j,1,len2)
            f[i][j] = -INT_MAX;
    }
    Fo(i,1,len1) {
        Fo(j,1,len2) {
            if(a[i]==b[j]) f[i][j] = max(f[i][j], f[i-1][j-1]+1);
            else f[i][j] =max({f[i][j], f[i-1][j], f[i][j-1]});
        }
    }
    // cout<<f[len1][len2]<<endl;
    Fo(i,0,25) {
        Fo(j,1,len1) {
            if(a[j]==i) g[i][j] = j;
            else g[i][j] = g[i][j-1];
        }
        Fo(j,1,len2) {
            if(b[j]==i) h[i][j] = j;
            else h[i][j] = h[i][j-1];
        }
    }
    dfs(len1, len2, "", f[len1][len2]);
    for(auto it:st) cout<<it<<endl;
    return 0;
}