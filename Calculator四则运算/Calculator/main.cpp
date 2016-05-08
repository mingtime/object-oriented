    /*******************************************************************
	FileName: main.cpp
	Author:mingtime         Date: 16/04/08    version:3.1
	Description:  int main(),calcu()
	Version:        16/05/07
	Function List:  1.int main():From CMD windows,there are two 
	                                new ways to input the experssion-output wi-
									th experssion,read the expr from files.
								2.calcu():In this function,deal with the expr we
								    get from main() using Scan,Printf and Result.
	1. -------    History:        
	<author>  <time>   <version >   <desc>        
	mingtime    16/04/08     1.0     build this moudle   
	mingtime    16/04/10     2.0     add CMD input 
	mingtime    16/05/06     3.0     add FILE *stream
	mingtime    16/05/07     3.1     move all output functions to Printf
	********************************************************************/
    #include<string>      
	#include<iostream>
	#include<queue>
	#include"Printf.h"   //声明
	#include"Scan.h"
	#include"Calculation.h"
	#include"Result.h"
	using namespace std;

	int main(int argc, char*argv[])
	{


		Printf printf;
		string s, s1;
		void calcu(string ss);
		s = argv[1];

		/*判断是否有-a指令*/
		if (s == "-a")
		{
			s1 = argv[2];
			s.clear();
			printf.ExperssionOutput(s1);
			calcu(s1);

		}

		/*文件输入输出*/
		else if (s == "-f")
		{

			string filename_in, filename_out;
			filename_in = argv[2];
			filename_out = argv[3];

			FILE* stream;

			freopen_s(&stream, filename_in.c_str(), "r", stdin);
			freopen_s(&stream, filename_out.c_str(), "w", stdout);

			while (cin >> s1)
			{
				calcu(s1);
			}

			fclose(stdin);
			fclose(stdout);
		}

		else
		{
			calcu(s);
		}


		system("pause");
		return 0;

	}


	void calcu(string ss)
	{
		Scan scan;
		Printf printf;    //创建Printf对象
		Calculation calculation;
		Result result;
		double results;
		queue<string>que;    //定义一个string类的队列
		stack<string>experssion;


		que = scan.ToStringQueue(ss);      //调用Scan对象的ToStringQueue(string input)，将输入传进去以获取队列
		printf.OutStringQueue(que);         //在printf函数对接受到的式子输出
										
		/**************************四则运算调用**************************************/
		if (que.front() == "WRONG EXPERSSION")  //修改：针对位数超出范围进行错误提醒
		{
			printf.ShowError();
			//cout << "WRONG EXPERSSION" << endl;
		}

		else
		{
			experssion = calculation.ScanStringExperssion(que);
			results = result.CalculationResult(experssion);

			printf.PrintfResult(results);
		}

		/****************************************************************/
	}
