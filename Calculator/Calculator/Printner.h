#pragma once
#include <string>
#include <iostream>
using namespace std;
class Printner
{
public:
	Printner();
	~Printner();


	/*ÐÞ¸Ä*/
	void ShowError();

	void printfout(string filename_out , double results);

	void PrintfResult(double result);

};

