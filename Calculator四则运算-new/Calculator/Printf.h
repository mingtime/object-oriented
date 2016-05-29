	#pragma once
	#ifndef PRINT_H
	#define PRINT_H
	#include<string>
	#include<iostream>
	#include<queue>
	using namespace std;
	class Printf
	{
	public:
		Printf();

		~Printf();

		void OutStringQueue(queue<string> output);

		/*ÐÞ¸Ä*/
		void ShowError();

		void ExperssionOutput(string s);

		void PrintfResult(double result);

		void printfout(string filename_out,double results);
	};

	#endif