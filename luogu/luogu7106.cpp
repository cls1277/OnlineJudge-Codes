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
using namespace std;
typedef long long LL;
#define PI acos(-1)
#define INF 2147483647
#define eps 1e-7
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Ms(a,b) memset((a),(b),sizeof(a))
inline LL read() {
	LL x = 0, f = 1;char c = getchar();
	while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
	while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
	return x * f;
}

string in;

LL cha(char ch) {
	if(ch>='0'&&ch<='9')
		return ch-'0';
	return ch-'A'+10;
}

char chb(LL x) {
	if(x>=0&&x<=9)
		return x+'0';
	return x-10+'A';
}

string che(LL x) {
	string ans = "";
	LL x1 = x/16 , x2 = x%16;
	ans += chb(x1);
	ans += chb(x2);
	return ans;
}

struct Node {
	LL R , G , B;
	Node(){};
	Node(LL r , LL g , LL b) {
		R=r , G=g , B=b;
	}
}; 

Node str2node(string s) {
	LL r = cha(s[1])*16+cha(s[2]);
	LL g = cha(s[3])*16+cha(s[4]);
	LL b = cha(s[5])*16+cha(s[6]);
	return Node(r,g,b);
}

string node2str(Node s) {
	string ans = "#";
	ans += che(s.R);
	ans += che(s.G);
	ans += che(s.B);
	return ans;
}

int main() {
//	freopen("data.txt","r",stdin);
	cin>>in;
	cout<<node2str(Node(255-str2node(in).R,255-str2node(in).G,255-str2node(in).B));
	return 0;
}
