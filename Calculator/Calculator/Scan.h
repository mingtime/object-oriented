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

		queue<string>ToStringQueue(string input);

	};

	#endif