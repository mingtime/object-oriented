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


//������ʾ
void Printner::ShowError()
{
	//cout << "WRONG EXPERSSION" << endl;
}

//������
void Printner::PrintfResult(double result)
{
	//cout << result << endl;
}

void Printner::printfout(string filename_out, double results)
{
	fstream fout;
	fout.open(filename_out.c_str(), ios::app);     //��������ļ�
	fout << results << endl;
	fout.close();
}

