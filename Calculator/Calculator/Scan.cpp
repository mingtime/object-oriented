    #include "Scan.h"
	#include<string>
	#include<iostream>
	#include<stdlib.h>
	#include<queue>
	using namespace std;


	Scan::Scan()
	{
	}


	Scan::~Scan()
	{
	}


	//�Խ��յ��ı��ʽ����
	//������һ������
	queue<string> Scan::ToStringQueue(string input)
	{
		int n, i, count = 0; //count���ڼ��������ַ����ĳ���
		n = size(input);
		queue<string>que, que2;
		string digit, digit2;

		//���ɨ����ʽ
		for (i = 0; i < n; i++)  
		{

			//��ȡ��С����ķ���
			if ((input[i]<'0' || input[i]>'9') && input[i] != '.')   
			{
				count = 0;  //���Ŵ���������
				digit = input[i];
				que.push(digit);
				digit.clear();
			}

			//��ȡ�����ַ���
			else if ((input[i] >= '0' && input[i] <= '9') || input[i] == '.')   
			{
				digit = digit + input[i];

				if ((input[i + 1]<'0' || input[i + 1]>'9') && input[i + 1] != '.')
				{
					que.push(digit);
					digit.clear();
				}

				//С���㲻���볤��
				if (input[i] == '.')
				{
					count += 0;
				}

				else
					count++;

				//���ֵ����ȳ���10��������С���㣩�򱨴�
				if (count == 10)   
				{
					que2.push("WRONG EXPERSSION");
					return que2;
					break;
				}

			}
		}
		return que;
	}