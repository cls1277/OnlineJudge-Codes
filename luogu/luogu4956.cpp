//copy
#include<iostream>//
using namespace std;//������֣����Ҳ��������
int main()//�������壬�Ƿ�����һ������
{
	int x,k=1,n;//�㿴��Щ���䷱��
	cin>>n;//���в������������û�
	while(1)//���޵ĵ���ѭ��
	{
		for(x=100;x>=1;x--)//�Ƿ����������������
			if((7*x+21*k)*52==n)
			{//����������粻���������ģ��
				cout<<x<<endl;//���Ƿ�Ը���׳�������
				cout<<k;//��Ϊ�����վƣ�����
				return 0;//���ǵ���걦ʯ���������˵�����
			}
		k++;//һ����һ��ı䣬ֻΪ��һ�����õĽ��
	}
	return 0;//���磬�վ������������ģ��
}