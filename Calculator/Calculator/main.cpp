    //main����������ȡ���������Լ�����Scan �� Print ����
	#include<string>      
	#include<iostream>
	#include<queue>
	#include"Printf.h"   //����
	#include"Scan.h"
	using namespace std;

	int main()
	{
		Printf printf;    //����Printf����
		Scan scan;      
		string s; 
		queue<string>que;    //����һ��string��Ķ���
		cin >> s;      //��ȡ��������
		que = scan.ToStringQueue(s);      //����Scan�����ToStringQueue(string input)�������봫��ȥ�Ի�ȡ����
		printf.OutStringQueue(que);         //��printf�����Խ��ܵ���ʽ�����
		system("pause");
		return 0;

	}


	//ע�Ͳο���http://blog.csdn.net/weiwenhp/article/details/8484973 