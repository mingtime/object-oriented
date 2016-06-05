#include "stdafx.h"
#include "Calculation.h"
#include "Printner.h"
#include <stack>
#include <queue>
#include <iostream>
#include <sstream>
using namespace std;

Calculation::Calculation()
{
}


Calculation::~Calculation()
{
}

stack<string> Calculation::ScanStringExperssion(queue<string>que)
{
	stack<string> stack_equation;
	stack<string> stack_symbol;
	string str, str1, str2;
    string digit, digit1;

	while (!que.empty())
	{
		str = que.front();
		que.pop();

		if (str == "(")
		{
			stack_symbol.push(str);
		}

		else if (str == ")")
		{
			while (!stack_symbol.empty() && stack_symbol.top() != "(")
			{
				stack_equation.push(stack_symbol.top());
				stack_symbol.pop();
			}
			if (!stack_symbol.empty())
			{
				stack_symbol.pop();
			}
		}

		else if (str == "+" || str == "-")
		{
			if (stack_symbol.empty() || stack_symbol.top() == "(")
			{
				stack_symbol.push(str);
			}
			else
			{
				while (!stack_symbol.empty() && stack_symbol.top() != "(")
				{
					stack_equation.push(stack_symbol.top());
					stack_symbol.pop();
				}
				stack_symbol.push(str);
			}
		}

		else if (str == "*" || str == "/")
		{
			if (stack_symbol.empty() || stack_symbol.top() == "(" || stack_symbol.top() == "+" || stack_symbol.top() == "-")
			{
				stack_symbol.push(str);
			}
			else
			{
				stack_equation.push(stack_symbol.top());
				stack_symbol.pop();
				stack_symbol.push(str);
			}
		}

		else
		{
			stack_equation.push(str);
		}

	}

	while (!stack_symbol.empty())
	{
		if (stack_symbol.top() != "(")
		{
			stack_equation.push(stack_symbol.top());
		}
		stack_symbol.pop();
	}

	while (!stack_equation.empty())
	{
		stack_symbol.push(stack_equation.top());//�й�!.empty() ������� ����ǿ�ҵ� 
												/* Ϊ����֤��Ϊ��׺���ʽ�Ƿ����cout << stack_equation.top() << endl;  */
		stack_equation.pop();
	}

	//CalculationResult(stack_symbol);
	return stack_symbol;

}

double Calculation::CalculateResult(queue<string>que)
{
	stack<string>experssion;
	experssion = ScanStringExperssion(que);
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
				Printner printf;
				printf.ShowError();
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