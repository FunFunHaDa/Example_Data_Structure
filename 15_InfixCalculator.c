#include<string.h>
#include<stdlib.h>
#include "15_InfixToPostfix.h"
#include "15_PostCalculator.h"

int EvalInfixExp(char exp[])
{
	int len = strlen(exp);
	int ret;
	char * expcpy = (char*)malloc(len + 1);
	strcpy(expcpy, exp);
	ConvToRPNExp(expcpy);
	ret = EvalRPNExp(expcpy);

	free(expcpy);

	return ret;
}
