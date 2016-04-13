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
		Printf printf;    //创建Printf对象
		Scan scan;      
		Calculation calculation;
		Result result;
		string s,s1,str; 
		int a = 0;
		double results;
		queue<string>que;    //定义一个string类的队列
		stack<string>experssion;
		str = argv[argc - 1];
		s = argv[1];
		/*判断是否有-a指令*/
		if (s=="-a")
		{
			a = 1;
		}

		que = scan.ToStringQueue(str);      //调用Scan对象的ToStringQueue(string input)，将输入传进去以获取队列
		printf.OutStringQueue(que);         //在printf函数对接受到的式子输出
		/**************************四则运算调用**************************************/

		if (que.front() == "WRONG EXPERSSION")  //修改：针对位数超出范围进行错误提醒
		{
			cout << "WRONG EXPERSSION"<<endl;
			return 0;
		}

		else
		{
			experssion = calculation.ScanStringExperssion(que);
			results = result.CalculationResult(experssion);

			if (a == 0)
			{
				cout << results << endl;
			}

			else if (a == 1)
			{
				cout << str << "=" << " " << results << endl;
			}
		}
		
		/****************************************************************/

		system("pause");
		return 0;

	}

