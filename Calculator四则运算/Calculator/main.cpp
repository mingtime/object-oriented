    //main����������ȡ���������Լ�����Scan �� Print ����
	#include<string>      
	#include<iostream>
	#include<queue>
	#include"Printf.h"   //����
	#include"Scan.h"
    #include"Calculation.h"
    #include"Result.h"
	using namespace std;

	int main()
	{
		Printf printf;    //����Printf����
		Scan scan;      
		Calculation calculation;
		Result result;
		string s,s1; 
		int a = 0;
		double results;
		queue<string>que;    //����һ��string��Ķ���
		stack<string>experssion;
		cin >> s;      //��ȡ��������
		
		/*�ж��Ƿ���-aָ��*/
		if (s[0] == '-'&&s[1] == 'a')
		{
			cin >> s1;
			s.clear();
			s = s1;
			a = 1;
		}

		que = scan.ToStringQueue(s);      //����Scan�����ToStringQueue(string input)�������봫��ȥ�Ի�ȡ����
		printf.OutStringQueue(que);         //��printf�����Խ��ܵ���ʽ�����

		/**************************�����������**************************************/
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


	//ע�Ͳο���http://blog.csdn.net/weiwenhp/article/details/8484973 