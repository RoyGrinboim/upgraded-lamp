#include <stdio.h>
#include "myMath.h"

double f1(double x)
{
	double y = (double)add((float)Exp((int)x), (float)Pow(x, 3));
	y = (double)sub((float)y, 2.0);
	return y;
}

double f2(double x)
{
	double y = (double)add((float)mul(x, 3), (float)mul(Pow(x, 2), 2));
	return y;
}

double f3(double x)
{
	double y = 0.0;
	double s = mul(x, 2);
	double p = Pow(x, 3);
	double m = mul(p, 4);
	double d = div(m, 5);
	y = (double)sub((float)d, (float)s);
	return y;
}


int main()
{
	double x = 0.0;
	printf("please insert a real number: ");
	scanf("%lf", &x);
	double fx1 = f1(x);
	double fx2 = f2(x);
	double fx3 = f3(x);
	printf("The value of f(𝑥) = 𝑒^𝑥 + 𝑥^3 − 2 at the point %lf is %.4lf\n", x, fx1);
	printf("The value of f(𝑥) = 3x + 2X^2 at the point %lf is %.4lf\n", x, fx2);
	printf("The value of f(𝑥) =  (4x^3)/5 -2x at the point %.4lf is %lf\n", x, fx3);
	return 0;
}
