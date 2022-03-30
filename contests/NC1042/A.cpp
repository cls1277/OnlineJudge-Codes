    //By cls1277
    #include<bits/stdc++.h>
    using namespace std;
    typedef long long LL;
    #define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
    #define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
    #define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
    #define Ms(a,b) memset((a),(b),sizeof(a))
    #define endl '\n'

    // const LL maxn = ;
    LL w[105], n, m, f[10005];

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        #ifdef DEBUG
        freopen("data.txt","r",stdin);
        #endif
        cin>>n>>m;
        Fo(i,1,n) cin>>w[i];
        f[0] = 1;
        Fo(i,1,n)
            Ro(j,m,w[i])
                f[j] += f[j-w[i]];
        cout<<f[m];
        return 0;
    }