	/****************************************************************
	FileName:HomeWorkCircle.cpp

	Author:sin      Version:1.1   Date:2016/5/4

	Function List:
	    1. Ask for the radiu of a circle

		2.Print the area of that circle

	*****************************************************************/

    #include<iostream>
	using namespace std;
	#include"circle.h"

	int main()
	{
		int s,r;
		circle circle;
		cout << "Please enter the radiu:";
		while (cin>>r)
		{
			cout <<"The area is "<< circle.calculatecircle(r) << endl;
			cout << "Please enter the radiu:";
		}
		return 0;
	}