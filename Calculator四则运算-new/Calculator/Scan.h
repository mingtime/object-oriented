	//���һ��scan�� ��������������ַ���
	//����������ToStringQueue(string input)
	#pragma once
	#ifndef SCAN_H     //��ֹ�ظ�����
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

		void writein(string filename_in,string filename_out);
		queue<string>ToStringQueue(string input);

	};

	#endif