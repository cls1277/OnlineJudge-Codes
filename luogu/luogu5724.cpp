//copy
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,maxn=-1,minn=1001;
	cin>>n;
	for(int i=1;i<=n;++i){
		int tmp;
		cin>>tmp;
		maxn=max(tmp,maxn);//�����ֵ
		minn=min(tmp,minn);//����Сֵ
	}
	cout<<maxn-minn;//���
	return 0;
}
