//copy
#include<iostream>
using namespace std;
int main()
{
    int n,ans=0,temp,b,max=1;  
    cin>>n;
    cin>>b;                //���룬��ʼ��b 
    for(int i=1;i<=n-1;i++)
    {
        cin>>temp;
        if(temp==b+1) max++;    //����������ǰһ������1�����ֵ������1 
        else max=1;             //����max�ص���ʼֵ 
        if(ans<max) ans=max;    //������ֵ�ȵ�ǰ�Ĵ𰸴󣬸��Ĵ� 
        b=temp;                 //b=��ǰ����� 
    }
    cout<<ans;                      //��� 
return 0;
}
