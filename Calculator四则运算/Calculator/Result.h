	#pragma once
	#ifndef  RESULT_H
	#define RESULT_H
	#include<stdio.h>
	#include<string>
	#include<stdlib.h>
	#include<stack>
	#include<queue>
	#include<iostream>
	using namespace std;
	class Result
	{
	public:
		Result();
		~Result();
		double CalculationResult(stack<string>experssion);
	};

	#endif

