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
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define lowbit(_) _&(-_)
inline LL read() {
	LL x = 0, f = 1;char c = getchar();
	while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
	while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
	return x * f;
}

//const LL maxn = ;
int n , p1 , p2 , len;

string sol3(int x) {
	int temp[15] , cnt=0;
	string res="";
	while(x>0) {
		if(x%26==0) {
			temp[++cnt]=26;
		//	x = (x-pow(26,cnt))/26;
			x--;
			x/=26;
		} else {
			temp[++cnt]=x%26;
			x/=26;	
		}
	}
	Ro(i,cnt,1)
		res+=temp[i]-1+'A';
	return res;
}

string sol4(string &x , int y) {
	int res=0; string s;
	Fo(i,0,y-1)
		res+=(x[i]-'A'+1)*pow(26,y-1-i);
	stringstream ss;
	ss<<res;
	ss>>s;
	return s;
}

string sol2(string &x) {
	int ops; string res="" , temp="";
	string ans="R";
	Fo(i,0,len-1) {
		if(x[i]>='A'&&x[i]<='Z') {
			res+=x[i];
		} else {
			ops = i;
			break;
		}
	}
	Fo(i,ops,len-1)
		temp+=x[i];
	ans=ans+temp+"C"+sol4(res,ops);
	return ans;
}

string sol1(string &x) {
	int res=0;
	string tmp="";
	string ops="";
	Fo(i,1,p2-1)
		tmp=tmp+x[i];
	Fo(i,p2+1,len-1)
		res=res*10+(x[i]-'0');
	ops+=sol3(res)+tmp;
	return ops;
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>n;
	Fo(i,1,n) {
		string str;
		cin>>str;
		len = str.length();
		p1=str.find('R');
		p2=str.find('C');
		if(p1>=0&&p1<len-1&&p2>=0&&p2<len-1&&str[p1+1]>='0'&&str[p1+1]<='9'&&str[p2+1]>='0'&&str[p2+1]<='9')
			cout<<sol1(str)<<endl;
		else cout<<sol2(str)<<endl;
	}
	return 0;
}

