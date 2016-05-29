#include "circle.h"
#include<math.h>
#define pai 3.1415926

circle::circle()
{
}


circle::~circle()
{
}

double circle::calculatecircle(double r)
{
	double s;
	s = r*r*pai;
	return s;
}