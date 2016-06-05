#include "stdafx.h"
#include "Printner.h"
#include "Calculation.h"
#include "CalculatorDlg.h"
#include <fstream>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

Printner::Printner()
{
}


Printner::~Printner()
{
}


//错误提示
void Printner::ShowError()
{
	//cout << "WRONG EXPERSSION" << endl;
}

//输出结果
void Printner::PrintfResult(double result)
{
	//cout << result << endl;
}

void Printner::printfout(string filename_out, double results)
{
	fstream fout;
	fout.open(filename_out.c_str(), ios::app);     //创建输出文件
	fout << results << endl;
	fout.close();
}

