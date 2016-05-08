	/*******************************************************************
	FileName: result.cpp
	Author:mingtime         Date: 16/04/08    version:3.0
	Description:  CalculationResult();
	Function List:
								1.Calculate the <stack>
								2.(string)str-->(double)i
								3.Judge if the divisor is 0 or not
	1. -------    History:
	<author>  <time>   <version >   <desc>
	mingtime    16/04/08     1.0     build this moudle
	mingtime    16/04/14     2.0     add divisoriszero warning 
	mingtime    16/05/06     3.0     delete output functions
	********************************************************************/
    #include "Result.h"
    #include "Printf.h"
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
		Printf printf;
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
					printf.ShowError();
					//cout << "WRONG EXPERSSION" << endl;
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

