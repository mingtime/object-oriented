#include<stdio.h>
#include<math.h>
int main()
{
	int a, b, c, s;
	scanf_s("%d%d", &a, &b);
	c = a + b;
	void math(int q);
	if (c == 0)
	{
		printf("0");
}
    else if (c < 0)
	{
		c = -c;
		printf("-");
         math(c);

	}
	else if (c>0)
	{
	 math(c);
	}
   
	return 0;
}

void math(int q)
{
	int m, n, l;
	if (q < 1000)
	{
		printf("%d", q);
	}
	else if (q<1000000)
	{
		m = q % 1000;
		n = q / 1000;
		printf("%d,%03d", n, m);
	}
	else if (q<1000000000)
	{
		l = q % 1000;
		q = q / 1000;
		m = q % 1000;
		n = q / 1000;
		printf("%d,%03d,%03d", n, m, l);
	}
	
}