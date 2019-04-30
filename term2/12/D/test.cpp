//Memory  Time 
//16696K 3766MS 
#include <stdio.h>
#include<iostream>
using namespace std;

const __int64 prime=999983;  // 10n����������������n=10W��

class
{
public:
	__int64 len[6];  //6��Ҷ�ӵĳ���
}leaf[100001];

typedef class HashTable
{
public:
	__int64 len[6];   //��¼6��Ҷ�ӵĳ�����Ϣ
	HashTable* next;  //���ڳ�ͻʱ����Ѱַ

	HashTable()  //Initial
	{
		next=0;
	}
}Hashtable;

Hashtable* hash[prime+1];

/*�����k��ѩ���Ĺؼ���key*/

__int64 compute_key(int k)
{
	__int64 key=0;
	for(int i=0;i<6;i++)
	{
		key+=(leaf[k].len[i]) % prime;
		key%=prime;   //����ͬ��ģ�������key��������ִ���
	}

	return ++key;  //��ֵ����1λ����key�ķ�Χ��0~999982��Ϊ 1~999983
}

/*��˳ʱ�뷽���ж���Ƭѩ���Ƿ���ͬ*/

bool clockwise(Hashtable* p,int k)
{
	for(int j=0;j<6;j++)  //˳ʱ��ת��j��
	{
		bool flag=true;
		for(int i=0;i<6;i++)
			if(leaf[k].len[i] != p->len[(i+j)%6])
			{
				flag=false;
				break;
			}
		if(flag)
			return true;
	}
	return false;
}

/*����ʱ�뷽���ж���Ƭѩ���Ƿ���ͬ*/

bool counterclockwise(Hashtable* p,int k)
{
	for(int j=0;j<6;j++)  //��ʱ��ת��j��
	{
		bool flag=true;
		for(int i=0;i<6;i++)
			if(leaf[k].len[i] != p->len[(5-i-j+6)%6])
			{
				flag=false;
				break;
			}
		if(flag)
			return true;
	}
	return false;
}

/*�ѵ�k��ѩ����Ϣ����HashTable*/
/*�������λ���Ѵ�������ѩ����Ϣʱ��˳��Ƚ�*/

bool insert(int k)
{
	__int64 key=compute_key(k);

	if(!hash[key])
	{
		Hashtable* temp=new Hashtable;

		for(int i=0;i<6;i++)
			temp->len[i]=leaf[k].len[i];

		hash[key]=temp;  //����key��Ӧ�ĵ�ַ
	}
	else  //��ַ��ͻ,����Ѱַ,˳��Ƚ�
	{
		Hashtable* temp=hash[key];

		if(clockwise(temp,k) || counterclockwise(temp,k))  //���ѩ���Ƿ���ͬ
			return true;

		while(temp->next)    //Ѱַ
		{
			temp=temp->next;

			if(clockwise(temp,k) || counterclockwise(temp,k))  //���ѩ���Ƿ���ͬ
		{//printf("%d\n",k);
				return true;}
		}

		temp->next=new Hashtable;    //����ռ䣬������ѩ����Ϣ
		for(int i=0;i<6;i++)
			temp->next->len[i]=leaf[k].len[i];
	}
	return false;
}

int main(int i,int j)
{
	int n;  //ѩ����
	while(cin>>n)
	{
		/*Initial*/

		memset(hash,0,sizeof(hash));  // 0 <-> NULL

		/*Input*/

		bool flag=false;  //��¼����������Ƿ��������ͬ��ѩ��
		for(i=1;i<=n;i++)
		{
			for(j=0;j<6;j++)
				scanf("%I64d",&leaf[i].len[j]);

			/*Hash*/

			if(!flag)    //��ǰ��û�г�����ͬ��ѩ��
				flag=insert(i);
			             //��������ͬ��ѩ��������������룬�����ٴ���
		}

		/*Output*/

		if(flag)
			cout<<"Twin snowflakes found."<<endl;
		else
			cout<<"No two snowflakes are alike."<<endl;

	}
	return 0;
}
