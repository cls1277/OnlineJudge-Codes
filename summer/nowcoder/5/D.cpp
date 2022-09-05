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
const LL maxn = 5e5+5;
char str[maxn] , s[maxn<<1];
LL f[maxn<<1];
map<char, LL> ans;

LL init() {
	LL len = strlen(str)-1 , j=2;
	s[0]='^'; s[1]='$';
	Fo(i,0,len) {
		s[j++] = str[i];
		s[j++] = '$';
	}
	s[j] = '&';
	return j;
}

void Manacher() {
	LL len=init()-1 , mid=1 , maxx=1;// , ans=-1;
	Fo(i,1,len) {
		if(i<maxx) f[i]=min(maxx-i,f[mid*2-i]);
		else f[i]=1;
		while(s[i-f[i]]==s[i+f[i]]) {
            ans[s[i-f[i]]]++;
            f[i]++;
        }
		if(maxx<i+f[i]) {
			mid = i;
			maxx = i+f[i];
		}
		// ans = max(ans , f[i]-1);
	}
	// return ans;
}

LL n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    while(cin>>n) {
        cin>>str;
        Manacher();
        cout<<ans['k']<<' '<<ans['f']<<' '<<ans['c']<<endl;
    }
    return 0;
}