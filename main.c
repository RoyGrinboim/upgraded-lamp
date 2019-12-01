#include <stdio.h>
#include <stdbool.h>
#include "myBank.h"
#define MAX_ACOUNT 950
#define MIN_ACOUNT 901

int main()
{
char input = 'O';
float deposit = 0.0;
int acNum = 0;
while(input != 'E')
{	
	printf("enter a char: \n");
	printf("to open new acount press O\n");
	printf("to check your balance press B\n");
	printf("to deposit money to your acount press D\n");
	printf("to withdraw money from your acount press W\n");
	printf("to close acount press C\n");
	printf("to add inflation press I\n");
	printf("to print all the acounts press P\n");
	printf("to close the program press E\n");
	scanf(" %c", &input );
	switch(input)
	{
	case 'O':
		printf("enter your deposit: ");
		scanf(" %f", &deposit);
		openAcount(deposit);
		break;

	case 'B':
		printf("enter your acount number: ");
		scanf(" %d", &acNum);
		if(acNum > MAX_ACOUNT || acNum < MIN_ACOUNT)
		{
		printf("wrong acount number\n");
		break;
		}
		checkMoney(acNum);
		break;

	case 'D':
		printf("enter your acount number: ");
		scanf(" %d", &acNum);
		printf("enter your deposit: ");
		scanf(" %f", &deposit);
		if(acNum > MAX_ACOUNT || acNum < MIN_ACOUNT)
		{
		printf("wrong acount number\n");
		break;
		}
		addMoney(acNum, deposit);
		break;
	case 'W':
		printf("enter your acount number: ");
		scanf(" %d", &acNum);
		printf("enter the amount of money you want to take: ");
		scanf(" %f", &deposit);
		if(acNum > MAX_ACOUNT || acNum < MIN_ACOUNT)
		{
		printf("wrong acount number\n");
		break;
		}
		subMoney(acNum, deposit);
		break;
	case 'C':
		printf("enter your acount number: ");
		scanf(" %d", &acNum);
		if(acNum > MAX_ACOUNT || acNum < MIN_ACOUNT)
		{
		printf("wrong acount number\n");
		break;
		}
		closeAcount(acNum);
		break;
	case 'I':
		printf("enter the iflation presentege: ");
		scanf(" %f", &deposit);
		addInflation(deposit);
		break;
	case 'P':
		printAll();
		break;
	case 'E':
		closeAll();
		break;
	default:
		printf("Wrong input, please try again.\n");
	}
}
return 0;
}




