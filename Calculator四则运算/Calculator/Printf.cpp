	//���Printf�࣬��������õ��Ķ���
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

	//���
	void Printf::OutStringQueue(queue<string> output)
	{

		while (!output.empty())
		{
			/*��Ҫ�����ֵ�ʽ��ʱ��cout << output.front() << endl;*/
			output.pop();
		}

	}