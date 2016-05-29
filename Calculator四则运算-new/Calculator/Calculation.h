	#pragma once
	#ifndef  CALCULATOR_H
	#define CALCULATOR_H
	#include<stdio.h>
	#include<string>
	#include<stdlib.h>
	#include<stack>
	#include<queue>
	#include<iostream>
	using namespace std;
	class Calculation
	{
	public:
		Calculation();
		~Calculation();
		stack<string> ScanStringExperssion(queue<string> experssion);
		double CalculationResult(queue<string>que);
	};

	#endif

