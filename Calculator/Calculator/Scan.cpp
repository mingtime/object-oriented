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
		queue<string>que, que2;
		string digit, digit2;

		//逐个扫描表达式
		for (i = 0; i < n; i++)  
		{

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
		return que;
	}