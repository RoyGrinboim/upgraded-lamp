#include "myMath.h"
#define E 2.7182

double Exp(int x)
{
double sum = 0.0;
	while(x>0)
	{
	sum = sum*E;
	x = x-1;
	}
return sum;
}

double Pow(double x, int y)
{
double sum = 0.0;
	while(x>0)
	{
	sum = sum*x;
	x = x-1;
	}
return sum;
}
