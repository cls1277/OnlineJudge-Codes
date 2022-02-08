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

// const LL maxn = ;

int T,n,m,p,q;

struct Mat {
    int data[25][25];
    Mat() {
        Ms(data,0);
    }
    Mat operator * (const Mat&b) {
        Mat res;
        Fo(i,0,n-1)
            Fo(j,0,q-1)
                Fo(k,0,m-1)
                    res.data[i][j] += data[i][k]*b.data[k][j];
        return res;
    }
    void print() {
        Fo(i,0,n-1) {
            Fo(j,0,q-1)
                cout<<data[i][j]<<" ";
            cout<<endl;
        }
    }
};

Mat x , y;

int main() {
    ios::sync_with_stdio(false);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>T; int tt=0;
    while(T--) {
        cout<<"Case "<<(++tt)<<":"<<endl;
        cin>>n>>m>>p>>q;
        Fo(i,0,n-1)
            Fo(j,0,m-1)
                cin>>x.data[i][j];
        Fo(i,0,p-1)
            Fo(j,0,q-1)
                cin>>y.data[i][j];
        if(m!=p) {
            cout<<"ERROR"<<endl;
            continue;
        }
        (x*y).print();
    }
    return 0;
}