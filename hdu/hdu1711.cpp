//By cls1277
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<stack>
#include<sstream>
#include<set>
#include<cassert>
#include<bitset>
using namespace std;
typedef long long LL;
#define PI acos(-1)
#define INF 2147483647
#define eps 1e-7
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define lowbit(_) _&(-_)
inline LL read() {
    LL x = 0, f = 1;char c = getchar();
    while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
    while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
    return x * f;
}

#define MAXN 1000005
int str1[MAXN] , str2[10005];
LL nxt[MAXN] , len1 , len2 , T;
bool flag;

void Next() {
    LL p1 = 0 , p2 = -1;
    nxt[0] = -1;
    while(p1<len2) {
        if(p2==-1 || str2[p1]==str2[p2])
            nxt[++p1] = ++p2;
        else    p2 = nxt[p2];
    }
}

void KMP() {
    LL p1 = 0 , p2 = 0;
    while(p1<len1) {
        if(p2==-1 || str1[p1]==str2[p2]) {
            p1++; p2++;            
        }
        else    p2 = nxt[p2];
        if(p2==len2) {
        	flag=true;
            cout<<p1-len2+1<<endl;
            return ;
            p2 = nxt[p2];
        }
    }
}

int main() {
    //ios::sync_with_stdio(false);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>T;
    while(T--) {
        flag=false;
        Ms(nxt,0);
	    cin>>len1>>len2;
	    Fo(i,0,len1-1) cin>>str1[i];
		Fo(i,0,len2-1) cin>>str2[i];
	    Next();
	    KMP();	
	    if(flag==false) cout<<"-1"<<endl;
	}
    return 0;
}
