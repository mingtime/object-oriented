	#include "Calculation.h"
	#include<stdio.h>
	#include<string>
	#include<stdlib.h>
	#include<stack>
	#include<queue>
	#include<iostream>
	using namespace std;


	Calculation::Calculation()
	{
	}


	Calculation::~Calculation()
	{
	}

	stack<string>Calculation::ScanStringExperssion(queue<string>que)
	{
		stack<string> stack_equation;
		stack<string> stack_symbol;
		string str, str1, str2;
		string digit, digit1;

		while (!que.empty())
		{
			str = que.front();
			que.pop();

			if (str == "(")//   " "和 ' '的区别 wocao//
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
				if (!stack_symbol.empty())   //**//
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
			if (stack_symbol.top() != ")")
			{
				stack_equation.push(stack_symbol.top());
			}
			stack_symbol.pop();
		}

		while (!stack_equation.empty())
		{
			stack_symbol.push(stack_equation.top());//有关！empty 这个条件 是最强烈的 整整调试了两天！！！！！！打好基础真的很重要  细微之处的过失有时真的能要人命 
													//特地去百度了一下这一点
			/* 为了验证改为后缀表达式是否错误：cout << stack_equation.top() << endl;  */
			stack_equation.pop();
		}

		return stack_symbol;

	}
