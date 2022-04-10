//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 5005;
LL n, a[maxn], f[maxn], mx;
char num[maxn][maxn];
LL x[maxn]; char ans[maxn];

char* add(char* s1, char* s2) {
    Ms(x, 0);
	LL len1 = strlen(s1)-1;
    LL len2 = strlen(s2)-1;
	LL len = max(len1 , len2);
    reverse(s1, s1+len1+1);
    reverse(s2, s2+len2+1);
	Fo(i,0,len) {
		LL tmp1 = 0 , tmp2 = 0;
		if(i<=len1)
			tmp1 = s1[i]-'0';
		if(i<=len2)
			tmp2 = s2[i]-'0';
		x[i]=x[i]+tmp1+tmp2;
		x[i+1]+=x[i]/10;
		x[i]%=10;
	}
	len++;
	while(!x[len]&&len>0)
		len--;
    Ro(i,len,0) s1[len-i] = x[i]+'0';
    s1[len+1] = '\0';
	return s1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n;
    Fo(i,1,n) cin>>a[i];
    Fo(i,1,n) {
        f[i] = 1;
        num[i][0] = '1';
        num[i][1] = '\0';
        Fo(j,1,i-1) {
            if(a[j]>a[i]) {
                if(f[j]+1>f[i]) {
                    f[i] = f[j]+1;
                    // LL l = strlen(num[j])-1;
                    // Fo(k,0,l) num[i][k] = num[j][k];
                    // num[i][l+1] = '\0';
                    // cout<<num[i]<<' '<<num[j]<<' ';
                    strcpy(num[i], num[j]);
                    // cout<<num[i]<<endl;
                } else if(f[j]+1==f[i]) {
                    // cout<<num[i]<<' '<<num[j]<<' ';
                    add(num[i], num[j]);
                    // cout<<num[i]<<endl;
                }
            } else if(a[i]==a[j]) {
                f[j] = 0;
                num[j][0]= '0';
                num[j][1] = '\0';
            }
        }
        mx = max(mx, f[i]);
    }
    ans[0] = '0';
    ans[1] = '\0';
    Fo(i,1,n)
        if(f[i]==mx) {
            // cout<<ans<<' '<<num[i]<<' ';
            add(ans, num[i]);
            // cout<<ans<<endl;
        }
    cout<<mx<<' '<<ans;
    return 0;
}