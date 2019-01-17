#include<stdio.h>
#include "17_PostCalculator.h"

int main(void)
{
	char postExp1[] = "42*8+";
	char postExp2[] = "123+*4/";

	printf("%s = %d \n", postExp1, EvalPRNExp(postExp1));
	printf("%s = %d \n", postExp2, EvalPRNExp(postExp2));
	return 0;
}