//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(int i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 20;
const LL mod = 32768;
int a[maxn], n, ans=15;

void dfs(LL idx, int a[]) {
    if(idx==15) {
    	// Fo(i,1,4) {
    	// 	if(a[i]==0)
    	// 		return ;
		// }
        // Fo(i,5,15) {
        // 	if(a[i]==1) {
        // 		return ;
		// 	}
		// }
        LL t = n;
        Fo(i,1,15) {
            if(a[i]==1) t=(t+1)%mod;
            else t=t*2%mod;
            if(!t) {
                ans = min(ans, i);
                // cout<<i<<' ';
                return ;
            }
        }
        return ;
    }
    a[idx+1] = 1;
    dfs(idx+1, a);
    a[idx+1] = 0;
    dfs(idx+1, a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    // LL t; cin>>t;
    // while(t--) {

    // cin>>n;
    for(n=0; n<32768; n++) {
        ans = 15;
        // n = 32764;
        dfs(0, a);
        // if(ans!=15) continue;
        // cout<<"a["<<n<<"]="<<ans<<';';
        cout<<n<<' '<<ans<<endl;
        // cout<<endl;
    }

    return 0;
}
