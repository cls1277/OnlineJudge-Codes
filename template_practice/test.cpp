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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL a[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	swap(a[0], a[1]);
	Fo(i,0,2) {
		Fo(j,0,2) {
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	} 
    return 0;
}

