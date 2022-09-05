#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
typedef long long LL;
LL f[402][202][202];
char s[444];
inline void add(LL &x,LL y){
	x += y;
	if(x >= mod) x -= mod;
}
void solve(){
	int n,m;
	cin>>n>>m>>(s+1);
	f[0][0][0] = 1;
	for(int i=1;i<=m;i++){
		for(int j=0;j<=m;j++){
			for(int k=0;k<=n;k++){
				{
					int nxk = k;
					if(s[k+1] == '(') nxk++;
					add(f[i][j+1][nxk],f[i-1][j][k]);
					printf("f[%d][%d][%d]+=f[%d][%d][%d]\n",i,nxk,j+1,i-1,k,j);
				}
				if(j >= 1){
					int nxk = k;
					if(s[k+1] == ')') nxk++;
					add(f[i][j-1][nxk],f[i-1][j][k]); 
					printf("f[%d][%d][%d]+=f[%d][%d][%d]\n",i,nxk,j-1,i-1,k,j);
				}
			}
		}
	}
	cout<<f[m][0][n]<<"\n";
	for(int i=1;i<=m;i++){
		for(int j=0;j<=m;j++){
			for(int k=0;k<=n;k++) f[i][j][k] = 0;
		}
	}
}
int main(){
	freopen("data.txt","r",stdin);
	int _;
	cin>>_;
	while(_--) solve();
	return 0;
}

