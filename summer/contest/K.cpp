#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int fa[N],size[N],n,m,ans;
int read(){
	int x=0,w=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*w;
}

int find(int x){
	if(fa[x]==x)return fa[x];
	fa[x]=find(fa[x]);
	size[fa[x]]+=size[x];
	size[x]=0;
	return fa[x];
}

void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy){
		size[fx]+=size[fy];size[fy]=0;
		fa[fy]=fx;
	}
}
//�����ǲ��鼯 
int main(){
	n=read();m=read();ans=0;
	for(int i=1;i<=2*n;i++)fa[i]=i;
	for(int i=1;i<=n;i++)size[i]=0;
	for(int i=1+n;i<=2*n;i++)size[i]=1;//Ԥ���� 
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		int fx=find(x),fy=find(y),fxn=find(x+n),fyn=find(y+n);//�ٶ�x,y��ʾ���ˣ�x+n,y+n��ʾ���� 
		string ch;cin>>ch;
		if(ch=="good"){
			merge(x+n, y+n);merge(x, y);//���x˵y�Ǻ��ˣ���x,yҪôͬʱ�Ǻ��ˣ�Ҫôͬʱ�ǻ��� 
		}else {
			merge(x, y+n);merge(y, x+n);//���x˵y�ǻ��ˣ���x,yһ����һ��һ������� 
		}
	}
	for(int i=1;i<=n;i++){
		if(find(i)==find(i+n)){cout<<-1<<endl;return 0;}//���������i���Ǻ������ǻ��˵���������޽� 
	}
	for(int i=1;i<=n;i++){
		ans+=max(size[find(i)], size[find(i+n)]);//ͳ�ƴ� ,ȡmax����Ϊ̰��ȡ���ͺã���Ϊ������ͬ�����ĳ���������Ӱ���ǲ�һ���� 
		size[find(i)]=size[find(i+n)]=0;//ע����0����Ϊ֮ǰ�Ѿ�ͳ�ƹ����� 
	}cout<<ans<<endl;
	return 0;
}


