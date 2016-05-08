	/*******************************************************************
	FileName: scan.cpp
	Author:mingtime         Date: 16/04/08    version:3.0
	Description:  ToStringQueue()
	Function List:  1.Scan the expr and split it. The oprator and n-
									umbers should be departed.
								2.Deal with  Irregular input.
	1. -------    History:
	<author>  <time>   <version >   <desc>
	mingtime    16/04/08     1.0     build this moudle
	mingtime    16/04/10     2.0     add limited warning
	mingtime    16/04/10     2.1     fill the brackets 
	mingtime     16/04/10    2.2     add function to deal with negative 
														   numbers
	mingtime    16/05/06     3.0     ignore the "="
	********************************************************************/
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


	//对接收到的表达式处理：
	//返回是一个队列
	queue<string> Scan::ToStringQueue(string input)
	{
		int n, i, count = 0; //count用于计算数字字符串的长度
		n = size(input);
		queue<string>que, que2, experssion,expression,expression1;
		string digit, digit2;
		int count_digit=0;
		//逐个扫描表达式
		for (i = 0; i < n; i++)
		{
			//忽略行尾‘=’ 16.05.06
			if (input[i] == '=')
			{
				break;
			}
			//提取非小数点的符号
			if ((input[i]<'0' || input[i]>'9') && input[i] != '.')
			{
				count = 0;  //符号处计算清零
				digit = input[i];
				que.push(digit);
				digit.clear();
			}

			//提取数字字符串
			else if ((input[i] >= '0' && input[i] <= '9') || input[i] == '.')
			{
				digit = digit + input[i];

				if ((input[i + 1]<'0' || input[i + 1]>'9') && input[i + 1] != '.')
				{
					que.push(digit);
					digit.clear();
				}

				//小数点不计入长度
				if (input[i] == '.')
				{
					count += 0;
				}

				else
					count++;

				//数字当长度超过10（不包含小数点）则报错
				if (count == 10)
				{
					que2.push("WRONG EXPERSSION");
					return que2;
					break;
				}

			}
		}
		/*******************以下函数只在需要进行四则运算时调用******************************/

		while (!que.empty())
		{
			digit = que.front();
			experssion.push(digit);
			que.pop();

			//连接负号
			if ((digit == "(" || digit == "+" || digit == "-" || digit == "*" || digit == "/") && que.front() == "-")
			{
				digit = que.front();
				que.pop();

				if (que.front() == "(")
				{
					experssion.push(digit);
					experssion.push(que.front());
					que.pop();
				}

				else
				{
					digit2 = que.front();
					digit += digit2;
					que.pop();
					experssion.push(digit);
				}

			}

			//连接带正号正数的正号
			else if ((digit == "(" || digit == "+" || digit == "-" || digit == "*" || digit == "/") && que.front() == "+")
			{
				digit = que.front();
				que.pop();
				digit2 = que.front();
				digit += digit2;
				que.pop();
				experssion.push(digit);
			}

			//补省略掉的*号
			else if ((!que.empty()) && (digit == ")" || (digit <= "9"&&digit >= "0")) && que.front() == "(")
			{
				experssion.push("*");
			}
		}

		//新增：对括号的匹配处理 （2+（2+4）=4情况的修改  16.4.10
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
		/***************************************************************************************/
		return expression;  //拆分式子则将此行改为  return que;   
	}

