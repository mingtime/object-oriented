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
		queue<string>que, que2, experssion,expression,expression1;
		string digit, digit2;
		int count_digit=0;
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
		/*******************���º���ֻ����Ҫ������������ʱ����*******************************/

		while (!que.empty())
		{
			digit = que.front();
			experssion.push(digit);
			que.pop();

			//���Ӹ���
			if ((digit == "(" || digit == "+" || digit == "-" || digit == "*" || digit == "/") && que.front() == "-")
			{
				digit = que.front();
				que.pop();
				digit2 = que.front();
				digit += digit2;
				que.pop();
				experssion.push(digit);
			}

			//���Ӵ���������������
			else if ((digit == "(" || digit == "+" || digit == "-" || digit == "*" || digit == "/") && que.front() == "+")
			{
				digit = que.front();
				que.pop();
				digit2 = que.front();
				digit += digit2;
				que.pop();
				experssion.push(digit);
			}

			//��ʡ�Ե���*��
			else if ((!que.empty()) && (digit == ")" || (digit <= "9"&&digit >= "0")) && que.front() == "(")
			{
				experssion.push("*");
			}
		}

		//�����������ŵ�ƥ�䴦�� ��2+��2+4��=4������޸�  16.4.10
		while (!experssion.empty())
		{
			expression.push(experssion.front());
			if (experssion.front() == "(")
			{
				expression1.push(experssion.front());
			}
			else if (experssion.front() == ")")
			{
				if (!experssion.empty())
				{
					expression1.pop();
				}
				else
				{
					expression.push(")");
				}
			}
			experssion.pop();
		}
		while (!expression1.empty())
		{
			expression.push(")");
			expression1.pop();
		}
		/****************************************************************************************/
		return expression;  //���ʽ���򽫴��и�Ϊ  return que;   
	}