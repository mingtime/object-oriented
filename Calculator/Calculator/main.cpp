    //main主函数：获取键盘输入以及创建Scan 和 Print 对象
	#include<string>      
	#include<iostream>
	#include<queue>
	#include"Printf.h"   //声明
	#include"Scan.h"
	using namespace std;

	int main()
	{
		Printf printf;    //创建Printf对象
		Scan scan;      
		string s; 
		queue<string>que;    //定义一个string类的队列
		cin >> s;      //获取键盘输入
		que = scan.ToStringQueue(s);      //调用Scan对象的ToStringQueue(string input)，将输入传进去以获取队列
		printf.OutStringQueue(que);         //在printf函数对接受到的式子输出
		system("pause");
		return 0;

	}


	//注释参考：http://blog.csdn.net/weiwenhp/article/details/8484973 