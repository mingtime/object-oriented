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


class Scanner
{
public:

	Scanner();

	~Scanner();

	queue<string>Scan_m_cinstr(string input);
	void writein(string filename_in, string filename_out);

};

#endif
