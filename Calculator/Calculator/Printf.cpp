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
			cout << output.front() << endl;
			output.pop();
		}

	}