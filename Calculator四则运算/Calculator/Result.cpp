	#include "Result.h"
	#include<stdio.h>
	#include<string>
	#include<stdlib.h>
	#include<stack>
	#include<queue>
	#include<iostream>
	#include<sstream>
	using namespace std;


	Result::Result()
	{
	}


	Result::~Result()
	{
	}


	double Result::CalculationResult(stack<string>experssion)
	{
		stack<double>number;
		string str;
		double i, results;

		while (!experssion.empty())
		{
			str = experssion.top();
			experssion.pop();

			if (str == "+")
			{
				results = number.top();
				number.pop();
				if (number.empty())   //����ȡ������numջΪ��
				{
					number.push(0);
					results = number.top() + results;
				}
				else
				{
					results += number.top();
				}
				number.pop();
				number.push(results);
			}

			else if (str == "-")
			{
				results = number.top();
				number.pop();
				if (number.empty())   //����ȡ��������numberջΪ��
				{
					number.push(0);
					results = number.top() - results;
				}
				else
				{
					results = number.top() - results;
				}
				number.pop();
				number.push(results);
			}
			
			else if (str == "*")
			{
				results = number.top();
				number.pop();
				results *= number.top();
				number.pop();
				number.push(results);
			}

			else if (str == "/")
			{
				results = number.top();
				number.pop();

				if (results == 0)    //����Ϊ���ж� 4.14�޸�
				{
					cout << "WRONG EXPERSSION" << endl;
					return 0;
				}

				results = number.top() / results;
				number.pop();
				number.push(results);
			}

			else
			{
				stringstream string(str);  //��string�͵�strתΪdouble�͵�i
				string >> i;
				number.push(i);
			}

		}

		return number.top();
	}

