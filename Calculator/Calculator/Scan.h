	//添加一个scan类 用来处理输入的字符串
	//声明方法：ToStringQueue(string input)
	#pragma once
	#ifndef SCAN_H     //防止重复编译
	#define SCAN_H
	#include<string>
	#include<iostream>
	#include<stdlib.h>
	#include<queue>
	using namespace std;


	class Scan
	{
	public:

		Scan();

		~Scan();

		queue<string>ToStringQueue(string input);

	};

	#endif