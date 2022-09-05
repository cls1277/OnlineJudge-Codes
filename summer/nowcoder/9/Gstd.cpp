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
LL mi[1009],has1[1009],has2[1009],ans;
int n;
char s[1009];
const int h=31;

LL gethas1(int x,int y){
	return has1[y]-has1[x-1]*mi[y-x+1];
}
LL gethas2(int x,int y){
	return has2[x]-has2[y+1]*mi[y-x+1];
}
void query1(int x){//疑惑 
    unordered_set<LL> st;
	int l=1,r=min(x,n-x);
	while(l<=r){
		int mid=(l+r)>>1;
		if(gethas1(x-mid,x+mid)==gethas2(x-mid,x+mid)){
            l=mid+1;
            st.insert(gethas1(x-mid,x+mid));
        }
		else r=mid-1;
	}//return r;
    for(auto it:st) cout<<it<<' ';
    cout<<endl;
}

void query2(int x){
    unordered_set<LL> st;
	int l=1,r=min(x,n-x);
	while(l<=r){
		int mid=(l+r)>>1;
		if(gethas2(x-mid+1,x+mid)==gethas1(x-mid+1,x+mid)) {
            l=mid+1;
            st.insert(gethas2(x-mid+1,x+mid));
        }
		else r=mid-1;
	}//return r;
    for(auto it:st) cout<<it<<' ';
    cout<<endl;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL m; cin>>m;
        Fo(_m,1,m) {
            scanf("%s",s+1);
            n=strlen(s+1),mi[0]=1;
            for(int i=1;i<=n;i++){
                has1[i]=has1[i-1]*h+(s[i]-'a');
                mi[i]=mi[i-1]*h;
            }for(int i=n;i>=1;i--) has2[i]=has2[i+1]*h+(s[i]-'a');
            Fo(i,1,n) {
                query1(i);
                query2(i);
                cout<<endl;
            }
    }
    return 0;
}