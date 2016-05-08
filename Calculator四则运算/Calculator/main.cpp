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
	#include"Printf.h"   //����
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

		/*�ж��Ƿ���-aָ��*/
		if (s == "-a")
		{
			s1 = argv[2];
			s.clear();
			printf.ExperssionOutput(s1);
			calcu(s1);

		}

		/*�ļ��������*/
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
		Printf printf;    //����Printf����
		Calculation calculation;
		Result result;
		double results;
		queue<string>que;    //����һ��string��Ķ���
		stack<string>experssion;


		que = scan.ToStringQueue(ss);      //����Scan�����ToStringQueue(string input)�������봫��ȥ�Ի�ȡ����
		printf.OutStringQueue(que);         //��printf�����Խ��ܵ���ʽ�����
										
		/**************************�����������**************************************/
		if (que.front() == "WRONG EXPERSSION")  //�޸ģ����λ��������Χ���д�������
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
