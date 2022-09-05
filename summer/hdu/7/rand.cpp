//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

//const LL maxn = ;

LL a, b, c;

void abc()
{
    if (a > b) {
        swap(a, b);
    }
    if (b > c) {
        swap(b, c);
    }
    if (a > b) {
        swap(a, b);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    srand(time(NULL));
    LL t=1; cout<<t<<endl;
    while(t--) {
        a = rand()%11+1;
        b = rand()%11+1;
        c = rand()%11+1;
        abc();
        if(a+b<=c) {
            cout<<"2 2 3"<<endl;
            continue;
        }
        cout<<a<<' '<<b<<' '<<c<<endl;
    }
    return 0;
}