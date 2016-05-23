/*******************************************************************
FileName: result.cpp
Author:mingtime         Date: 16/04/08    version:1.0
Description:  ScanStringExperssion();
Function List:  1.Trans infix expr into suffix
2.Use two <stack> to realize 1
1. -------    History:
<author>  <time>   <version >   <desc>
mingtime    16/04/08     1.0     build this moudle
mingtime    16/05/23     2.0     add a new function to calculate.
                                                       there is no reesult.cpp ~
********************************************************************/
	#include "Calculation.h"
	#include"Printf.h"
	#include<stdio.h>
	#include<string>
	#include<stdlib.h>
	#include<stack>
	#include<queue>
	#include<iostream>
    #include<sstream>
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
			stack_symbol.push(stack_equation.top());//有关!.empty() 这个条件 是最强烈的 
			/* 为了验证改为后缀表达式是否错误：cout << stack_equation.top() << endl;  */
			stack_equation.pop();
		}

		//CalculationResult(stack_symbol);
		return stack_symbol;

	}

	double Calculation::CalculationResult(queue<string>que)
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
				if (number.empty())   //若提取加数后num栈为空
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
				if (number.empty())   //若提取被减数后number栈为空
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

				if (results == 0)    //除数为零判断 4.14修改
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
				stringstream string(str);  //将string型的str转为double型的i
				string >> i;
				number.push(i);
			}

		}


		return number.top();
	}
