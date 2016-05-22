#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct MyStruct
{
	int afterstr;
	int theadr;
	int num;
	MyStruct *next;
};

struct list
{
	int afterstr;
	int num;
}a[100001];

int main()
{
	int count = 0, times;
	int adr, n, k;
	int i, j;
	int theastr, afterstr, num;

	scanf_s("%d %d %d", &adr, &n, &k);
	if (adr == -1)
	{
		printf("-1\n"); 
		return 0;
	}

	for (i = 0; i < n; i++)
	{
		scanf_s("%d %d %d", &theastr, &num, &afterstr);
		a[theastr].afterstr = afterstr;
		a[theastr].num = num;
	}

	

	MyStruct *head, *pnew, *tail, *p, *q, *temp;
	head = (MyStruct*)malloc(sizeof(MyStruct));

	head->next = NULL;
	tail = head;

	for (theastr = adr; theastr != -1; theastr = a[theastr].afterstr)
	{
		pnew = (MyStruct*)malloc(sizeof(MyStruct));
		pnew->num = a[theastr].num;
		pnew->afterstr = a[theastr].afterstr;
		pnew->theadr = theastr;
		tail->next = pnew;
		tail = pnew;
		count += 1;
	}

	times = count / k;

	p = head->next;
	temp = head;
	for (i = 0; i < times; i++)
	{
		for (j = 0; j < k - 1; j++)
		{
		
			q =p->next;
			p->next = q->next;
			q->next =temp->next;
			temp->next = q;

		}
		temp = p;
		if (p->next == NULL)break;
		p = p->next;
	}


	for (p = head->next; p ->next!= NULL; p = p->next)
	{
		printf("%05d %d %05d\n", p->theadr,p->num,p->next->theadr);
		
	}
	printf("%05d %d -1\n", p->theadr, p->num);
	return 0;
}