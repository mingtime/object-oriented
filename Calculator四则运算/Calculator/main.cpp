	#include<string>      
	#include<iostream>
	#include<queue>
	#include"Printf.h"   //����
	#include"Scan.h"
    #include"Calculation.h"
    #include"Result.h"
	using namespace std;

	int main(int argc, char*argv[])
	{
		Printf printf;    //����Printf����
		Scan scan;      
		Calculation calculation;
		Result result;
		string s,s1,str; 
		int a = 0;
		double results;
		queue<string>que;    //����һ��string��Ķ���
		stack<string>experssion;
		str = argv[argc - 1];
		s = argv[1];
		/*�ж��Ƿ���-aָ��*/
		if (s=="-a")
		{
			a = 1;
		}

		que = scan.ToStringQueue(str);      //����Scan�����ToStringQueue(string input)�������봫��ȥ�Ի�ȡ����
		printf.OutStringQueue(que);         //��printf�����Խ��ܵ���ʽ�����
		/**************************�����������**************************************/

		if (que.front() == "WRONG EXPERSSION")  //�޸ģ����λ��������Χ���д�������
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

