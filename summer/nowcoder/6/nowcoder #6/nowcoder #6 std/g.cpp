#include <bits/stdc++.h>
using namespace std;

int n;
char c[105][105];

void paint1(int x,int y,int len,char ch='@')
{
	for(int i=0;i<len;i++) c[x][y+i]=ch;
}

void paint2(int x,int y,int len,char ch='@')
{
	for(int i=0;i<len;i++) c[x+i][y]=ch;
}

void paint3(int x,int y,int len,char ch='@')
{
	for(int i=0;i<len;i++) c[x+i][y+i]=ch;
}

void paintN(int x,int y,int len,char ch='@')
{
	paint2(x,y,len,ch);
	paint3(x,y,len,ch);
	paint2(x,y+len-1,len,ch);
}

void paintF(int x,int y,int len,char ch='@')
{
	paint2(x,y,len,ch);
	paint1(x,y,len,ch);
	paint1(x+(len>>1),y,len,ch);
}

void paintL(int x,int y,int len,char ch='@')
{
	paint2(x,y,len,ch);
	paint1(x+len-1,y,len,ch);
}

void paintS(int x,int y,int len,char ch='@')
{
	paint1(x,y,len,ch);
	paint1(x+(len>>1),y,len,ch);
	paint1(x+len-1,y,len,ch);
	paint2(x,y,len>>1,ch);
	paint2(x+(len>>1),y+len-1,len>>1,ch);
}

int main()
{
	// freopen("5.in","r",stdin);
	// freopen("5.out","w",stdout);
	cin>>n;
	int N=4*n+5,M=13*n+19,L=2*n+3;
	for(int i=0;i<N;i++) paint1(i,0,M,'.');
	paint1(0,0,M,'*');
	paint2(0,0,N,'*');
	paint1(N-1,0,M,'*');
	paint2(0,M-1,N,'*');

	paintN(n+1,n+2,L);
	paintF(n+1,4*n+6,L);
	paintL(n+1,7*n+10,L);
	paintS(n+1,10*n+14,L);

	for(int i=0;i<N;i++) printf("%s\n",c[i]);
	return 0;
}
