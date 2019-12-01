#include <stdio.h>
#include <stdbool.h>
#include "myBank.h"
#define NUM_ACOUNTS 50
#define UNUSED_ACOUNTS 901

float acounts[NUM_ACOUNTS];
bool  isAcountOpen[NUM_ACOUNTS] = {false};
int open_acounts = 0;

int findAcount()
{
	int i=0;
	for(i=0; i<NUM_ACOUNTS; i++)
	{
		if(isAcountOpen[i] == false)
		{
			return i;
		}
	}
	return (NUM_ACOUNTS+1);
}

void openAcount(float deposit)
{
	if(deposit < 0)
	{
	printf("you not aload to deposit negative number.\n");
	return;
	}
	if(open_acounts >= NUM_ACOUNTS)
	{
	printf("all the bank acounts are taken.\n");
	return;
	}
	int a = findAcount();
	acounts[a] = deposit;
	isAcountOpen[a] = true;
	open_acounts++;
	a = a + UNUSED_ACOUNTS; 
	printf("your acount number is %d.\n", a);	
}

void checkMoney(int acNum)
{
	acNum = acNum - UNUSED_ACOUNTS;
	if(isAcountOpen[acNum] == false)
	{
	printf("wrong acount number\n");
	return;
	}
	if(acNum >= NUM_ACOUNTS)
	{
	printf("wrong acount number\n");
	return;
	}
	printf("you have in your acount %f NIS\n", acounts[acNum]);
}

void addMoney(int acNum, float deposit)
{
	acNum = acNum - UNUSED_ACOUNTS;
	if(isAcountOpen[acNum] == false)
	{
	printf("wrong acount number\n");
	return;
	}
	if(acNum >= NUM_ACOUNTS)
	{
	printf("wrong acount number\n");
	return;
	}
	if(deposit < 0.0)
	{
	printf("you can't deposit a negative number.\n");
	return;
	}
	acounts[acNum] = acounts[acNum] + deposit;
	printf("you have in your acount %f NIS\n", acounts[acNum]);
}

void subMoney(int acNum, float take)
{
	acNum = acNum - UNUSED_ACOUNTS;
	if(isAcountOpen[acNum] == false)
	{
	printf("wrong acount number\n");
	return;
	}
	if(acNum >= NUM_ACOUNTS)
	{
	printf("wrong acount number\n");
	return;
	}
	if(take < 0.0)
	{
	printf("you can't take a negative number\n");
	return;
	}
	if(acounts[acNum] - take < 0.0)
	{
	printf("you are not alowd to take more then you have\n");
	return;
	}
	acounts[acNum] = acounts[acNum] - take;
	printf("you have in your acount %f NIS\n", acounts[acNum]);
}

void closeAcount(int acNum)
{
	acNum = acNum - UNUSED_ACOUNTS;
	if(isAcountOpen[acNum] == false)
	{
	printf("wrong acount number\n");
	return;
	}
	if(acNum >= NUM_ACOUNTS)
	{
	printf("wrong acount number\n");
	return;
	}
	isAcountOpen[acNum] = false;
	acNum = acNum + UNUSED_ACOUNTS;
	printf("acount %d has closed\n", acNum);
}

void addInflation(float per)
{
	per = per/100.0;
	per = per + 1.0;
	int i=0;
	for(i = 0; i<NUM_ACOUNTS; i++)
	{
		if(isAcountOpen[i] == true)
		{
			acounts[i] = acounts[i]*per;	
		}
	} 
}

void printAll()
{
int i=0;
for(i = 0; i<NUM_ACOUNTS; i++)
	{
		if(isAcountOpen[i] == true)
		{
		printf("acount number: %d ; money: %f\n", i+UNUSED_ACOUNTS, acounts[i]);	
		}
	} 
}

void closeAll()
{
int i=0;
for(i = 0; i<NUM_ACOUNTS; i++)
	{
		if(isAcountOpen[i] == true)
		{
		isAcountOpen[i] = false;
		}
	}
	
}







