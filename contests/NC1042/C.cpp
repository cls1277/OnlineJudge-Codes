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
LL n, m, a[201], b[201], v[201], w[201], f[21][801], pre[201][21][801];
vector<LL>res;
LL p, q;

void print(LL i, LL j, LL k) {
    if(!j) return ;
    LL idx = pre[i][j][k];
    print(idx-1, j-1, k-w[idx]);
    res.push_back(idx);
    p+=a[idx]; q+=b[idx];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t=0;
    while(cin>>n>>m&&n&&m) {
        res.clear(); p=q=0;
        Fo(i,1,n) {
            cin>>a[i]>>b[i];
            w[i] = a[i]-b[i];
            v[i] = a[i]+b[i];
        }
        Ms(f, -0x3f);
        f[0][400] = 0;
        Fo(i,1,n)
            Ro(j,m,1)
                Fo(k,-400,400) {
                    if(k-w[i]+400<0 || k-w[i]+400>800) continue;
                    pre[i][j][k+400] = pre[i-1][j][k+400];
                    if(f[j-1][k-w[i]+400]+v[i]>f[j][k+400]) {
                        f[j][k+400] = f[j-1][k-w[i]+400]+v[i];
                        pre[i][j][k+400] = i;
                    }
                }
        LL ans = INT_MAX;
        Fo(i,0,400) {
            if(f[m][i+400]<0&&f[m][400-i]<0) continue;
            if(f[m][i+400]>=0&&f[m][i+400]>f[m][400-i]) ans = 400+i;
            else ans = 400-i;
            break;
        }
        print(n, m, ans);
        cout<<"Jury #"<<++t<<endl;
        cout<<"Best jury has value "<<p<<" for prosecution and value "<<q<<" for defence:"<<endl;
        for(auto &it:res) cout<<" "<<it;
        cout<<endl<<endl;
    }
    return 0;
}