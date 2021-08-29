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

const LL maxn = 3;
struct Node {
    char a[maxn][maxn];
    string b;
    Node operator = (const Node &temp) {
    	Fo(i,0,2)
    		Fo(j,0,2)
    			a[i][j] = temp.a[i][j];
    	b = temp.b;
	}
};
const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,1,-1};
const char ch[4] = {'d','u','l','r'};
int flag;
map<string , string>ans;
set<string>s;
Node in;

string tostr(Node x) {
    string temp = "";
    Fo(i,0,2)
        Fo(j,0,2)
            temp = temp+x.a[i][j];
    return temp;
}

void bfs() {
	Node one;
	one.a[0][0]='1'; one.a[0][1]='2'; one.a[0][2]='3';
	one.a[1][0]='4'; one.a[1][1]='5'; one.a[1][2]='6';
	one.a[2][0]='7'; one.a[2][1]='8'; one.a[2][2]='x';
    queue<Node>q;
    string str1 = tostr(one);
    s.insert(str1);
    q.push(one);
    while(!q.empty()) {
        Node u = q.front();
        q.pop();
        LL ops , tx , ty;
        ops = tostr(u).find('x');
        tx = ops/3;
        ty = ops%3;
        Fo(i,0,3) {
        	Node v = u;
            LL sx , sy;
            sx = tx+dx[i];
            sy = ty+dy[i];
            if(sx<3&&sx>=0&&sy<3&&sy>=0) {
                swap(v.a[tx][ty],v.a[sx][sy]);
                string tmp = tostr(v);
                if(!s.count(tmp)) {
                    v.b = v.b+ch[i];
                    s.insert(tmp);
                    //reverse(tmp.begin(),tmp.end());
                    ans[tmp] = v.b;
                    q.push(v);
                }
            }
        }
    }
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    bfs();
    while(cin>>in.a[0][0]>>in.a[0][1]>>in.a[0][2]>>in.a[1][0]>>in.a[1][1]>>in.a[1][2]>>in.a[2][0]>>in.a[2][1]>>in.a[2][2]) {
		string input = tostr(in);
		if(s.count(input)==0) cout<<"unsolvable"<<endl;
	    else {
	    	string res = ans[input];
	    	reverse(res.begin(),res.end());
	    	cout<<res<<endl;
		}
		//flag = 0;
		//bfs();
	    //if(!flag) cout<<"unsolvable"<<endl;	
	}
    return 0;
}
