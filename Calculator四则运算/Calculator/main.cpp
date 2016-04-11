    //main主函数：获取键盘输入以及创建Scan 和 Print 对象
	#include<string>      
	#include<iostream>
	#include<queue>
	#include"Printf.h"   //声明
	#include"Scan.h"
    #include"Calculation.h"
    #include"Result.h"
	using namespace std;

	int main()
	{
		Printf printf;    //创建Printf对象
		Scan scan;      
		Calculation calculation;
		Result result;
		string s,s1; 
		int a = 0;
		double results;
		queue<string>que;    //定义一个string类的队列
		stack<string>experssion;
		cin >> s;      //获取键盘输入
		
		/*判断是否有-a指令*/
		if (s[0] == '-'&&s[1] == 'a')
		{
			cin >> s1;
			s.clear();
			s = s1;
			a = 1;
		}

		que = scan.ToStringQueue(s);      //调用Scan对象的ToStringQueue(string input)，将输入传进去以获取队列
		printf.OutStringQueue(que);         //在printf函数对接受到的式子输出

		/**************************四则运算调用**************************************/
		experssion=calculation.ScanStringExperssion(que);
		results=result.CalculationResult(experssion);
		if (a == 0)
		{
			cout << results<<endl;
		}
		else if (a == 1)
		{
			cout << s <<"="<<" "<<results << endl;
		}
		/****************************************************************/

		system("pause");
		return 0;

	}


	//注释参考：http://blog.csdn.net/weiwenhp/article/details/8484973 