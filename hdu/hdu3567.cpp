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
struct Node {
	char a[3][3];
	int x , y , cnt;
	string op="";
};
int T , len , ans , pp; 
const int dx[4]={1,0,0,-1};
const int dy[4]={0,-1,1,0};
const char ch[4]={'d','l','r','u'};
Node s , t;
string str , ans2;

string exc(Node x) {
	string temp="";
	Fo(i,0,2)
		Fo(j,0,2)
			temp+=x.a[i][j];
	return temp;
}

void bfs() {
	map<string,bool>vis;
	queue<Node>q;
	q.push(s);
	vis[exc(s)]=1;
	while(!q.empty()) {
		Node u=q.front();
		q.pop();
		Fo(i,0,3) {
			Node v=u; v.cnt++;
			if(v.cnt>=ans) break;
			int a1=v.x,b1=v.y; int a2=v.x+dx[i],b2=v.y+dy[i];
			if(a2<0||a2>2||b2<0||b2>2) continue;
			swap(v.a[a1][b1],v.a[a2][b2]);
			v.x=a2; v.y=b2; v.op+=ch[i];
			string tmp=exc(v);
			if(tmp==str) {
				ans = v.cnt;
				ans2 = v.op;
				break;
			}
			if(!vis[tmp]) {
				q.push(v);
				vis[tmp]=1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>T;
	while(T--) {
		pp++;
		ans=INF;
		cin>>str;
		Fo(i,0,2)
			Fo(j,0,2) {
				s.a[i][j]=str[i*3+j];
				if(str[i*3+j]=='X') {
					s.x=i;
					s.y=j;
				}
			}
		cin>>str;
		Fo(i,0,2)
			Fo(j,0,2) {
				t.a[i][j]=str[i*3+j];
				if(str[i*3+j]=='X') {
					t.x=i;
					t.y=j;
				}
			}
		s.cnt=0;
		bfs();
		cout<<"Case "<<pp<<": "<<ans<<endl<<ans2<<endl;
	}
	return 0;
}

