//copy
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,maxn=-1,minn=1001;
	cin>>n;
	for(int i=1;i<=n;++i){
		int tmp;
		cin>>tmp;
		maxn=max(tmp,maxn);//算最大值
		minn=min(tmp,minn);//算最小值
	}
	cout<<maxn-minn;//求差
	return 0;
}
