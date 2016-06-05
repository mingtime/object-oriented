#pragma once
#include<stack>
#include <string>
#include <iostream>
#include <queue>
using namespace std;
class Calculation
{
public:
	Calculation();
	~Calculation();

	stack <string> ScanStringExperssion(queue<string> que);
	double CalculateResult(queue<string>que);

};

