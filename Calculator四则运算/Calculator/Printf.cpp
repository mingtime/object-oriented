	/*******************************************************************
	FileName: result.cpp
	Author:mingtime         Date: 16/04/08    version:2.0
	Description: OutStringQueue();
	                         ShowError();
							 ExperssionOutput();
							 PrintResult();
	Function List:  1.Print the results
	                             2.Print the split expr;
								 3.print error warning;
								 4.Print result wiht expr;
	
	1. -------    History:
	<author>  <time>   <version >   <desc>
	mingtime    16/04/08     1.0     build this moudle
	mingtime    16/05/06     2.0     add error warning,expr output,r-
	                                                       esult output.
	********************************************************************/
	//添加Printf类，用来输出得到的队列
	#include "Printf.h"
	#include<string>
	#include<iostream>
	#include<stdlib.h>
	#include<queue>
	#include<stdio.h>
	using namespace std;
	Printf::Printf()
	{
	}


	Printf::~Printf()
	{
	}

	//输出
	void Printf::OutStringQueue(queue<string> output)
	{

		while (!output.empty())
		{
			/*需要输出拆分的式子时：cout << output.front() << endl;*/
			output.pop();
		}

	}

	//错误提示
	void Printf::ShowError()
	{
		cout << "WRONG EXPERSSION" << endl;
	}

	//参数为“-a”时输出表达式
	void Printf::ExperssionOutput(string s)
	{
		cout << s << " ";
	}

	//输出结果
	void Printf::PrintfResult(double result)
	{
		cout << result << endl;
	}

